#include "Shooting.h"
#include"../Engine/Components/Transform.h"
#include"../Engine/newSceneManager.h"
#include"../Shooter.h"

Shooting::Shooting(Object* parent)
	:Framework(parent,"Shooting"),state_(PLAY_STATE::STATE_PLAY)
{
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
	Instantiate<Shooter>(this);
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