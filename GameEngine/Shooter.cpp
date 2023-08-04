#include "Shooter.h"
#include "Engine/Systems/ImageSystem.h"
#include"Engine/GameObject/CameraManager.h"
#include"Engine/DirectX_11/Input.h"
#include"Shooting_Gun.h"
namespace
{
	const float TRIGGER_SHOT = 0.7f;
}
Shooter::Shooter(Object* parent)
	:GameObject(parent,"Shooter"),target_(XMVectorSet(0,0,30,0)),playerNum_(0)
{
}

Shooter::~Shooter()
{
}

void Shooter::Initialize()
{
	transform_->position_ = XMVectorSet(0, 0, -20,0);
	Image image;
	image.Load("Assets/Image/Image_Shooting_Sight.png");
	AddComponent<Image>(image);
	Instantiate<Shooting_Gun>(this)->SetPlayerNum_(playerNum_);
	CameraManager::GetCamera(playerNum_).SetPosition(transform_->position_);
}

void Shooter::Update()
{
	transform_->RotateEular({ -Input::GetLStick_Y(playerNum_) * 30.0f, Input::GetLStick_X(playerNum_) * 30.0f, 0 });
	XMVECTOR dir = XMVector3Rotate(target_, transform_->rotate_);
	if (Input::GetRTriggerDown(playerNum_))
	{
		((Shooting_Gun*)FindChild("Shooting_Gun"))->Shot(dir);
	}
	CameraManager::GetCamera(playerNum_).SetTarget(transform_->position_+dir);
}

void Shooter::Release()
{
}
