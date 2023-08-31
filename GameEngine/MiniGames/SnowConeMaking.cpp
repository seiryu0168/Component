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

namespace
{
	static const XMFLOAT3 cupPos[3] = { {-10,0,0},{0,0,0},{10,0,0} };
	static const XMFLOAT3 STOCK_POS[3]{ {1420,850,0},{1620,850,0},{1820,850,0} };
	static const XMFLOAT2 COUNT_POS = { 900,500 };
	static const XMFLOAT3 PROGRESS_DEFAULT = { 2,1,0 };
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
	{
		Camera camera;
		XMINT2 WH = { Direct3D::GetScreenWidth() ,Direct3D::GetScreenHeight() };
		camera.Initialize(WH.x, WH.y, 1.0f, 500.0f);
		camera.SetViewPort(WH.x, WH.y, 0.0f, 1.0f, 0, 0);
		CameraManager::AddCamera(camera);

	}
	{
		Camera camera;
		XMINT2 WH = { Direct3D::GetScreenWidth() ,Direct3D::GetScreenHeight() };
		camera.Initialize(WH.x, WH.y, 1.0f, 500.0f);
		camera.SetViewPort(WH.x / 2.0f, WH.y / 2.0f, 0.0f, 1.0f, 0, WH.y / 4.0f);
		CameraManager::AddCamera(camera);
	}

	{
		Camera camera;
		XMINT2 WH = { Direct3D::GetScreenWidth() ,Direct3D::GetScreenHeight() };
		camera.Initialize(WH.x, WH.y, 1.0f, 500.0f);
		camera.SetViewPort(WH.x / 2.0f, WH.y / 2.0f, 0.0f, 1.0f, WH.x/2.0f, WH.y / 4.0f);
		CameraManager::AddCamera(camera);
	}

	for (int i = 0; i < 3; i++)
	{
		Image image(0, 1);
		image.Load("Assets/Image/SnowCone_ShavedImage.png");
		image.SetPositionAtPixel(STOCK_POS[i]);
		image.SetAlpha(0);
		AddComponent<Image>(image);
	}
	for(int i=0;i<2;i++)
	{
		Image image(i+1);
		image.Load("Assets/Image/MultiWindowFrame.png");
		AddComponent<Image>(image);
	}

		Image image(0);
		image.Load("Assets/Image/SnowCone_CommandImage2.png");
		AddComponent<Image>(image);

	//Image progressFrame(0);
	//progressFrame.Load("Assets/Image/ProgressFrame_Image.png");
	//progressFrame.SetSize(PROGRESS_DEFAULT);
	//progressFrame.SetPositionAtPixel({ -76,-800,0 });
	//progressImageNum_ = AddComponent<Image>(progressFrame);
	
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
	

	Text countText("", "りいてがき筆", { 0,0,500,50 });
	countText.SetPosition(COUNT_POS);
	countText.SetTextSize(100);
	AddComponent<Text>(countText);

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
	GetComponent<Text>().SetText(std::to_string(time_->GetSeconds<float>()));
	if (time_->GetSeconds<float>() < 0)
	{
		FindChild("SnowCone_Order")->SetActive(true);
		FindChild("SnowCone_Table")->SetActive(true);
		FindChild("SnowConeMaker_Shave")->SetUpdate(true);
		FindChild("SnowConeMaker_Topping")->SetUpdate(true);

		RemoveComponent<Text>();
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
		for (int i = 0; i < cupList_.size(); i++)
		{
			cup->GetTransform()->position_ = XMLoadFloat3(&cupPos[i]);
			GetComponent<Image>(i).SetAlpha(1);
		}
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
		GetComponent<Image>(cupList_.size() - 1).SetAlpha(0);
		cupList_.pop();
		return cup;
	}
	else
	return nullptr;
}



void SnowConeMaking::Release()
{
}
