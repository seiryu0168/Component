#include "Shooter.h"
#include "Engine/Systems/ImageSystem.h"
#include"Engine/GameObject/CameraManager.h"
#include"Engine/DirectX_11/Input.h"
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
	//Image image;
	//image.Load("Assets/Image/Fire.png");
	//AddComponent<Image>(image);

	CameraManager::GetCamera(playerNum_).SetPosition(transform_->position_);
}

void Shooter::Update()
{
	XMVECTOR rotate = XMQuaternionRotationRollPitchYaw(XMConvertToRadians(Input::GetLStick_Y() * 60.0f),
													   -XMConvertToRadians(Input::GetLStick_X() * 60.0f),
													   0);
	XMVECTOR dir = XMVector3Rotate(target_, rotate);
													
	CameraManager::GetCamera(playerNum_).SetTarget(transform_->position_+dir);
}

void Shooter::Release()
{
}
