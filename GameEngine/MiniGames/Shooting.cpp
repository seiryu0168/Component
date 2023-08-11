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
}

Shooting::Shooting(Object* parent)
	:Framework(parent,"Shooting"),state_(PLAY_STATE::STATE_PLAY)
{
	playerCount_ = InterSceneData::GetData<int>("PlayerCount");
	switch (playerCount_)
	{
	case 1:
		break;
	case 2:
		CameraManager::AllRmoveCamera();
		D2D::AllRemoveRenderTarget();
		{
			Camera camera;
			XMINT2 WH = { Direct3D::GetScreenWidth() ,Direct3D::GetScreenHeight() };
			camera.Initialize(WH.x, WH.y, 1.0f, 500.0f);
			camera.SetViewPort(WH.x / 2.0f, WH.y / 2.0f, 0.0f, 1.0f, 0, 0);
			CameraManager::AddCamera(camera);
		}
		{
			Camera camera2;
			XMINT2 WH = { Direct3D::GetScreenWidth() ,Direct3D::GetScreenHeight() };
			camera2.Initialize(WH.x, WH.y, 1.0f, 500.0f);
			camera2.SetViewPort(WH.x / 2.0f, WH.y / 2.0f, 0.0f, 1.0f, WH.x / 2.0f, WH.y / 2.0f);
			CameraManager::AddCamera(camera2);
		}
		break;
	default:
		break;
	}
	scoreManager_.Init(playerCount_, 0);
	ui.Init(playerCount_, "");
	time_ = std::make_unique<Time::Watch>();
	time_->SetCountdown(true);
	time_->SetSecond(COUNT);
	time_->UnLock();
	Transform transform;
	AddComponent<Transform>(transform);

}

Shooting::~Shooting()
{
}

void Shooting::Initialize()
{

	Instantiate<Shooting_Table>(this);
	for (int i = 0; i < playerCount_; i++)
	{
		Instantiate<Shooter>(this)->SetPlayerNumber(i);
	}
	Text countText("Žc‚èŽžŠÔ" + std::to_string(COUNT), "‚è‚¢‚Ä‚ª‚«•M", { 0,0,450,50 });
	countText.SetPosition({ 1500,0 });
	AddComponent<Text>(countText);
}

void Shooting::Update()
{
	switch (state_)
	{
	case Shooting::PLAY_STATE::STATE_PLAY:
		Play();
		break;
	case Shooting::PLAY_STATE::STATE_FINISH:
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

void Shooting::Play()
{
	GetComponent<Text>().SetText(std::format("Žc‚èŽžŠÔ{:.2f} •b" ,time_->GetSeconds<float>()));

	if (time_->GetSeconds<float>() <=0)
	{
		GetComponent<Text>().SetText("Žc‚èŽžŠÔ 0.00");
		InterSceneData::AddData<int>("ResultData",scoreManager_.GetScore(0));
		newSceneManager::ChangeScene(SCENE_ID::RESULT, 60);
		state_ = PLAY_STATE::STATE_FINISH;
	}
}

void Shooting::Release()
{
}
