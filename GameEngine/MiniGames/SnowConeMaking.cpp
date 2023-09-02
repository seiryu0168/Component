#include "SnowConeMaking.h"
#include"../Engine/GameObject/CameraManager.h"
#include"../Engine/DirectX_11/Input.h"
#include"../Engine/Systems/ImageSystem.h"
#include"../Engine/Systems/TextSystem.h"
#include"../Engine/newSceneManager.h"
#include"../InterSceneData.h"

#include"../SnowConeMaker_Shave.h"
#include"../SnowConeMaker_Topping.h"
#include"../SnowCone_Table.h"
#include"../SnowCone_Cup.h"
#include"../SnowCone_Order.h"

#include<format>

namespace
{
	static const XMFLOAT3 cupPos[3] = { {-10,0,0},{0,0,0},{10,0,0} };
	static const XMFLOAT3 STOCK_POS[3]{ {1220,850,0},{1470,850,0},{1720,850,0} };
	static const XMFLOAT2 STOCK_TEXT_POS[3]{ {1515,200},{1640,200 }, {1765,200} };
	static const XMFLOAT2 COUNT_POS = { 700,50 };
	static const XMFLOAT3 PROGRESS_DEFAULT = { 2,1,0 };
	static const std::string STOCK_TEXT[3] = { "小盛","中盛","大盛" };
	static const float PLAY_COUNT = 60.0f;
}
SnowConeMaking::SnowConeMaking(Object* parent)
	:Framework(parent,"SnowConeMaking"),
	state_(PLAY_STATE::STATE_STAY),
	progressImageNum_(0)
{
}

SnowConeMaking::~SnowConeMaking()
{
}

void SnowConeMaking::Initialize()
{
	CameraManager::AllRmoveCamera();
	D2D::AllRemoveRenderTarget();
	//カメラ用意
	//メニューとか表示する一番でかいカメラ
	{
		Camera camera;
		XMINT2 WH = { Direct3D::GetScreenWidth() ,Direct3D::GetScreenHeight() };
		camera.Initialize(WH.x, WH.y, 1.0f, 500.0f);
		camera.SetViewPort(WH.x, WH.y, 0.0f, 1.0f, 0, 0);
		CameraManager::AddCamera(camera);

	}
	//プレイヤー1のカメラ
	{
		Camera camera;
		XMINT2 WH = { Direct3D::GetScreenWidth() ,Direct3D::GetScreenHeight() };
		camera.Initialize(WH.x, WH.y, 1.0f, 500.0f);
		camera.SetViewPort(WH.x / 2.0f, WH.y / 2.0f, 0.0f, 1.0f, 0, WH.y / 4.0f);
		CameraManager::AddCamera(camera);
	}
	//プレイヤー2のカメラ
	{
		Camera camera;
		XMINT2 WH = { Direct3D::GetScreenWidth() ,Direct3D::GetScreenHeight() };
		camera.Initialize(WH.x, WH.y, 1.0f, 500.0f);
		camera.SetViewPort(WH.x / 2.0f, WH.y / 2.0f, 0.0f, 1.0f, WH.x/2.0f, WH.y / 4.0f);
		CameraManager::AddCamera(camera);
	}
	//ストック表示用の画像用意
	for (int i = 0; i < 3; i++)
	{
		Image backImage(0, 1);
		backImage.Load("Assets/Image/SnowCone_ShavedImage.png");
		backImage.SetPositionAtPixel(STOCK_POS[i]);
		backImage.SetSize({ 1.4f,1.4f,0 });
		backImage.SetColor({ 0,0,0 });
		backImage.SetAlpha(0.7f);
		AddComponent<Image>(backImage);

		Image image(0, 1);
		image.Load("Assets/Image/SnowCone_ShavedImage.png");
		image.SetPositionAtPixel(STOCK_POS[i]);
		image.SetSize({ 1.3f,1.3f,0 });
		image.SetAlpha(0);
		shavedCupList_.push_back(AddComponent<Image>(image));

		Text shavedText("", "りいてがき筆", { 0,0,100,50 });
		shavedText.SetPosition(STOCK_TEXT_POS[i]);
		shavedText.SetTextSize(30);
		shavedText.SetColor({ 0,0,0,1 });
		shavedText.SetAlignmentType(CENTER_CENTER);
		shavedCupSize_.push_back(AddComponent<Text>(shavedText));
	}
	//プレイヤー1,2の背景用意
	for(int i=0;i<2;i++)
	{
		Image tableImage(i + 1,0);
		tableImage.Load("Assets/Image/plywood_diff_1k.jpg");
		tableImage.SetSize({ 2,2,0 });
		AddComponent<Image>(tableImage);
		Image image(i+1);
		image.Load("Assets/Image/MultiWindowFrame.png");
		AddComponent<Image>(image);
	}
	//全体の背景用意
	Image image(0);
	image.Load("Assets/Image/SnowCone_CommandImage2.png");
	AddComponent<Image>(image);
	
	Image progressImage(0);
	progressImage.Load("Assets/Image/ProgressBar_Image.png");
	progressImage.SetSize(PROGRESS_DEFAULT);
	progressImage.SetPositionAtPixel({ -1920,-800,0 });
	progressImageNum_ = AddComponent<Image>(progressImage);

	Image black(-1, 2);
	black.Load("Assets/Image/Filter.png");
	black.SetSize({ 1920,1080,0 });
	black.SetAlpha(0);
	blackImageNum_ = AddComponent<Image>(black);
	

	Text countText("", "りいてがき筆", { 0,0,500,50 },0,2);
	countText.SetPosition(COUNT_POS);
	countText.SetColor({ 0, 0, 0, 1 });
	countText.SetAlignmentType(CENTER_CENTER);
	countText.SetTextSize(200);
	timeText_ = AddComponent<Text>(countText);

	Instantiate<SnowCone_Order>(this)->SetActive(false);
	Instantiate<SnowCone_Table>(this)->SetActive(false);
	SnowConeMaker_Shave* p1 = Instantiate<SnowConeMaker_Shave>(this);
	p1->SetPlayerNumber(0);
	p1->SetUpdate(false);
	SnowConeMaker_Topping* p2 = Instantiate<SnowConeMaker_Topping>(this);
	p2->SetPlayerNumber(1);
	p2->SetUpdate(false);

	time_ = std::make_unique<Time::Watch>();
	time_->SetCountdown(true);
	time_->SetSecond(3.0f);
	time_->UnLock();

	scoreManager_.Init(1, 0);
}

void SnowConeMaking::Update()
{
	switch (state_)
	{
	case PLAY_STATE::STATE_STAY:
		Stay();
		break;
	case PLAY_STATE::STATE_PLAY:
		Play();
		break;

	default:
		break;
	}
}

void SnowConeMaking::StaticUpdate()
{
	//スタートボタンを押したときの挙動(ポーズ)
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_START))
	{
		SetUpdate(!isUpdate_);
		//ポーズ解除
		if (IsUpdate())
		{
			GetComponent<Image>(blackImageNum_).SetAlpha(0);
			time_->UnLock();
		}
		//ポーズ
		else
		{
			GetComponent<Image>(blackImageNum_).SetAlpha(0.3);
			time_->Lock();
		}
	}
}

void SnowConeMaking::Stay()
{
	GetComponent<Text>(timeText_).SetText(std::format("{:.2f}", time_->GetSeconds<float>()));
	if (time_->GetSeconds<float>() < 0)
	{
		FindChild("SnowCone_Order")->SetActive(true);
		FindChild("SnowCone_Table")->SetActive(true);
		FindChild("SnowConeMaker_Shave")->SetUpdate(true);
		FindChild("SnowConeMaker_Topping")->SetUpdate(true);

		RemoveComponent<Text>(timeText_);
		time_->SetSecond<float>(PLAY_COUNT);
		state_ = PLAY_STATE::STATE_PLAY;
	}
}

void SnowConeMaking::Play()
{
	GetComponent<Image>(progressImageNum_).SetSize({ PROGRESS_DEFAULT.x * (time_->GetSeconds<float>()/ PLAY_COUNT),
													 PROGRESS_DEFAULT.y,
													 PROGRESS_DEFAULT.z });
	if (time_->GetSeconds<float>() < 0)
	{
		newSceneManager::ChangeScene(SCENE_ID::RESULT, 1.0f);
		((SnowCone_Order*)FindChild("SnowCone_Order"))->SendResultData();
		InterSceneData::AddData<int>("ResultData", scoreManager_.GetScore());
		state_ = PLAY_STATE::STATE_FINISH;
	}
}

void SnowConeMaking::AddCup(SnowCone_Cup* cup)
{
	//かき氷をストックする
	if (cupList_.size() < 3)
	{
		cupList_.push(cup);
		
			//cup->GetTransform()->position_ = XMLoadFloat3(&cupPos[i]);
		std::string size = ((SnowCone_Order*)FindChild("SnowCone_Order"))->GetSizeString(cup->GetConeSize());
			GetComponent<Text>(shavedCupSize_[cupList_.size()-1]).SetText(size);
			GetComponent<Image>(shavedCupList_[cupList_.size()-1]).SetAlpha(1);
	}
	else
	{
		cup->KillMe();
		cup->RemoveIce();
	}
}

void SnowConeMaking::ScoreUpdate(int score)
{
	scoreManager_.ScoreUpdate(score);
}

void SnowConeMaking::Evaluation(float size, int syrup, int topping)
{
	((SnowCone_Order*)FindChild("SnowCone_Order"))->Judge(size, syrup, topping);
}

SnowCone_Cup* SnowConeMaking::GetCup()
{
	SnowCone_Cup* cup;
	if (cupList_.empty() == false)
	{
		cup = cupList_.front();
		GetComponent<Image>(shavedCupList_[cupList_.size() - 1]).SetAlpha(0);
		GetComponent<Text>(shavedCupSize_[cupList_.size() - 1]).SetText("");
		cupList_.pop();
		return cup;
	}
	else
	return nullptr;
}



void SnowConeMaking::Release()
{
}
