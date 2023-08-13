#include "Shooting.h"
#include"../Engine/Components/Transform.h"
#include"../Engine/newSceneManager.h"
#include"../Shooter.h"
#include"../Shooting_Table.h"
#include"../Engine/Systems/TextSystem.h"
#include"../Engine/GameObject/CameraManager.h"
#include"../InterSceneData.h"
#include<format>

namespace 
{
	const float COUNT = 10.0f;
	const float STAYCOUNT = 4.0f;
	const XMFLOAT2 COUNTPOS = { 1500,0 };
	const XMFLOAT2 STAYPOS = { 1600,-800 };
	const float STAYSIZE = 500.0f;
	const float COUNTSIZE = 72.0f;
	const XMVECTOR STAYPLAYERPOS = XMVectorSet(0, 50, -100, 0);
	const XMVECTOR STAYPLAYETARGET = XMVectorSet(0, 50, 0, 0);
}

Shooting::Shooting(Object* parent)
	:Framework(parent,"Shooting"),state_(PLAY_STATE::STATE_STAY),
	playerCount_(0)
{
	//playerCount_ = InterSceneData::GetData<int>("PlayerCount");
	//switch (playerCount_)
	//{
	//case 1:
	//	break;
	//case 2:
	//	CameraManager::AllRmoveCamera();
	//	D2D::AllRemoveRenderTarget();
	//	{
	//		Camera camera;
	//		XMINT2 WH = { Direct3D::GetScreenWidth() ,Direct3D::GetScreenHeight() };
	//		camera.Initialize(WH.x, WH.y, 1.0f, 500.0f);
	//		camera.SetViewPort(WH.x / 2.0f, WH.y / 2.0f, 0.0f, 1.0f, 0, 0);
	//		CameraManager::AddCamera(camera);
	//	}
	//	{
	//		Camera camera2;
	//		XMINT2 WH = { Direct3D::GetScreenWidth() ,Direct3D::GetScreenHeight() };
	//		camera2.Initialize(WH.x, WH.y, 1.0f, 500.0f);
	//		camera2.SetViewPort(WH.x / 2.0f, WH.y / 2.0f, 0.0f, 1.0f, WH.x / 2.0f, WH.y / 2.0f);
	//		CameraManager::AddCamera(camera2);
	//	}
	//	break;
	//default:
	//	break;
	//}
	playerCount_ = 1;

	scoreManager_.Init(playerCount_, 0);
	ui.Init(playerCount_, "");
	Transform transform;
	AddComponent<Transform>(transform);
	
}

Shooting::~Shooting()
{
}

void Shooting::Initialize()
{
	CameraManager::GetCamera(0).SetPosition(STAYPLAYERPOS);
	CameraManager::GetCamera(0).SetTarget(STAYPLAYETARGET);
	Instantiate<Shooting_Table>(this);
	//for (int i = 0; i < playerCount_; i++)
	//{
	//	Instantiate<Shooter>(this)->SetPlayerNumber(i);
	//}
	Text countText(std::to_string(STAYCOUNT), "りいてがき筆", { 0,0,450,50 });
	countText.SetPosition(STAYPOS);
	countText.SetTextSize(STAYSIZE);
	AddComponent<Text>(countText);
	time_ = std::make_unique<Time::Watch>();
	time_->SetCountdown(true);
	time_->SetSecond(STAYCOUNT);
	time_->UnLock();
}

void Shooting::Update()
{
	switch (state_)
	{
	case PLAY_STATE::STATE_STAY:
		Stay();
		break;
	case PLAY_STATE::STATE_PLAY:
		Play();
		break;
	case PLAY_STATE::STATE_FINISH:
		break;
	default:
		break;
	}
}

void Shooting::ScoreUpdate(const unsigned short& playerNum, int score)
{
	scoreManager_.ScoreUpdate(playerNum, 1);
	ui.TextUpdate(playerNum, std::to_string(scoreManager_.GetScore(playerNum)));
}

void Shooting::Stay()
{
	float count = time_->GetSeconds<float>();
	GetComponent<Text>().SetText(std::to_string((int)count));
	if (count <= 0.0f)
	{
		time_->SetSecond(COUNT);
		GetComponent<Text>().SetPosition(COUNTPOS);
		GetComponent<Text>().SetTextSize(COUNTSIZE);
		state_ = PLAY_STATE::STATE_PLAY;
		Instantiate<Shooter>(this)->SetPlayerNumber(0);
	}
}

void Shooting::Play()
{
	GetComponent<Text>().SetText(std::format("残り時間\n{:.2f}秒" ,time_->GetSeconds<float>()));

	if (time_->GetSeconds<float>() <=0)
	{
		GetComponent<Text>().SetText("残り時間 \n0.00秒");
		InterSceneData::AddData<int>("ResultData",scoreManager_.GetScore(0));
		newSceneManager::ChangeScene(SCENE_ID::RESULT, 60);
		state_ = PLAY_STATE::STATE_FINISH;
	}
}

void Shooting::Release()
{
}
