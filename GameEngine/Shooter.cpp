#include "Shooter.h"
#include "Engine/Systems/ImageSystem.h"
#include"Engine/GameObject/CameraManager.h"
#include"Engine/DirectX_11/Input.h"
#include"Shooting_Gun.h"
#include"MiniGames/Shooting.h"
namespace
{
	const float TRIGGER_SHOT = 0.7f;
	XMVECTOR CAMERA_POS[2] = { XMVectorSet(0, 0, -20, 0),XMVectorSet(0, 45, -100, 0) };
	XMVECTOR CAMERA_DEFAULT_POS = XMVectorSet(0, 50, -100, 0);
}
Shooter::Shooter(Object* parent)
	:GameObject(parent,"Shooter"),target_(XMVectorSet(0,0,30,0)),playerNum_(0),
	aimMode_(false)
{
}

Shooter::~Shooter()
{
}

void Shooter::Initialize()
{
	transform_->position_ = CAMERA_DEFAULT_POS;
	//transform_->position_ = CAMERA_DEFAULT_POS;
	Image image;
	image.Load("Assets/Image/Image_Shooting_Sight.png");
	AddComponent<Image>(image);
	Instantiate<Shooting_Gun>(this)->SetPlayerNum_(playerNum_);
	CAMERA_POS[0] = transform_->position_;
	CameraManager::GetCamera(playerNum_).SetPosition(CAMERA_POS[aimMode_]);
}

void Shooter::Update()
{
	transform_->RotateEular({ -Input::GetLStick_Y(playerNum_) * 30.0f, Input::GetLStick_X(playerNum_) * 30.0f, 0 });
	XMVECTOR dir = XMVector3Rotate(target_, transform_->rotate_);
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
		ModeChange();

	if (Input::GetRTriggerDown(playerNum_))
	{
		((Shooting_Gun*)FindChild("Shooting_Gun"))->Shot(dir);
	}
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_Y))
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
	Shooting_Gun* gun = (Shooting_Gun*)FindObject("Shooting_Gun");
	int score = gun->GetShotCount();
	gun->Reload();
	((Shooting*)FindObject("Shooting"))->ScoreUpdate(playerNum_, -score);
}

void Shooter::Release()
{
}
