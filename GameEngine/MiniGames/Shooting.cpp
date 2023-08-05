#include "Shooting.h"
#include"../Engine/Components/Transform.h"
#include"../Engine/newSceneManager.h"
#include"../Shooter.h"
#include"../Shooting_Table.h"
#include"../TestObject.h"
#include"../Shooting_TergetGift.h"

Shooting::Shooting(Object* parent)
	:Framework(parent,"Shooting"),state_(PLAY_STATE::STATE_PLAY)
{
	scoreManager_.Init(1, 0);
	ui.Init(1, "");
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
	Instantiate<Shooter>(this);
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

void Shooting::TargetHit(const unsigned short& playerNum, int score)
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
