#include "Shooter.h"
#include "Engine/Systems/ImageSystem.h"
#include"Easing.h"
#include"Engine/GameObject/CameraManager.h"
#include"Engine/DirectX_11/Input.h"
#include"Shooting_Gun.h"
#include"MiniGames/Shooting.h"
namespace
{
	const float TRIGGER_SHOT = 0.7f;
	XMVECTOR CAMERA_POS[2] = { XMVectorSet(0, 0, -20, 0),XMVectorSet(0, 45, -100, 0) };
	XMVECTOR CAMERA_DEFAULT_POS = XMVectorSet(0, 50, -100, 0);
	const XMFLOAT2 ROTATE_LIMIT = { 30,30 };
}
Shooter::Shooter(Object* parent)
	:GameObject(parent,"Shooter"),target_(XMVectorSet(0,0,30,0)),playerNum_(0),
	aimMode_(false), rotate_({0,0})
{
}

Shooter::~Shooter()
{
}

void Shooter::Initialize()
{

	float radius = VectorDot(XMVectorSet(0, 0, 1, 0), XMVector3Normalize(target_));
	transform_->position_ = CAMERA_DEFAULT_POS;
	Image image(playerNum_);
	image.Load("Assets/Image/Image_Shooting_Sight.png");
	AddComponent<Image>(image);
	Instantiate<Shooting_Gun>(this)->SetPlayerNum_(playerNum_);
	CAMERA_POS[0] = transform_->position_;
	CameraManager::GetCamera(playerNum_).SetPosition(CAMERA_POS[aimMode_]);
}

void Shooter::Update()
{	
	rotate_.x += -Input::GetLStick_Y(playerNum_);
	rotate_.y += Input::GetLStick_X(playerNum_);
	rotate_.x = Clamp<float>(rotate_.x, -ROTATE_LIMIT.x, ROTATE_LIMIT.x);
	rotate_.y = Clamp<float>(rotate_.y, -ROTATE_LIMIT.y, ROTATE_LIMIT.y);
	transform_->RotateEular({ rotate_.x,rotate_.y,0 });

	//transform_->RotateEular({ -Input::GetLStick_Y(playerNum_) * 30.0f,Input::GetLStick_X(playerNum_)*45.0f , 0 });
	XMVECTOR dir = XMVector3Rotate(target_, transform_->rotate_);
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A, playerNum_))
		ModeChange();

	if (Input::GetRTriggerDown(playerNum_))
	{
		((Shooting_Gun*)FindChild("Shooting_Gun"))->Shot(dir);
	}
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_Y, playerNum_))
		Reload();
	CameraManager::GetCamera(playerNum_).SetTarget(CAMERA_POS[aimMode_] +dir);
}

void Shooter::ModeChange()
{
	aimMode_ = !aimMode_;
	((Shooting_Gun*)FindChild("Shooting_Gun"))->SetDraw(!aimMode_);
	if (aimMode_)
	{
		CameraManager::GetCamera(playerNum_).SetPosition(CAMERA_POS[aimMode_]);
	}
	else
		CameraManager::GetCamera(playerNum_).SetPosition(CAMERA_POS[aimMode_]);

}

void Shooter::Reload()
{
	Shooting_Gun* gun = (Shooting_Gun*)FindChild("Shooting_Gun");
	int score = gun->GetShotCount();
	gun->Reload();
	//((Shooting*)FindObject("Shooting"))->ScoreUpdate(playerNum_, -score);
}

void Shooter::Release()
{
}
