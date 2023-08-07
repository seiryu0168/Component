#include "Shooting.h"
#include"../Engine/Components/Transform.h"
#include"../Engine/newSceneManager.h"
#include"../Shooter.h"
#include"../Shooting_Table.h"
#include"../TestObject.h"
#include"../Shooting_TergetGift.h"
#include"../Engine/GameObject/CameraManager.h"

Shooting::Shooting(Object* parent)
	:Framework(parent,"Shooting"),state_(PLAY_STATE::STATE_PLAY)
{
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
	scoreManager_.Init(2, 0);
	ui.Init(2, "");
	time_ = std::make_unique<Time::Watch>();
	//time_->SetCountdown(true);
	//time_->SetSecond(10);
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
	Instantiate<Shooter>(this)->SetPlayerNumber(0);
	Instantiate<Shooter>(this)->SetPlayerNumber(1);
}

void Shooting::Update()
{
	switch (state_)
	{
	case Shooting::PLAY_STATE::STATE_PLAY:
		//Play();
		break;
	case Shooting::PLAY_STATE::STATE_FINISH:
		break;
	default:
		break;
	}
}

void Shooting::ScoreUpdate(const unsigned short& playerNum, int score)
{
	scoreManager_.ScoreUpdate(playerNum, score);
	ui.TextUpdate(playerNum, std::to_string(scoreManager_.GetScore(playerNum)));


}

void Shooting::Play()
{
	if (time_->GetSeconds<float>() >= 10.0f)
	{
		newSceneManager::ChangeScene(SCENE_ID::MENU, 60);
		state_ = PLAY_STATE::STATE_FINISH;
	}
}

void Shooting::Release()
{
}
