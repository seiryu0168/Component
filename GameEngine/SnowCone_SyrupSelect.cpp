#include "SnowCone_SyrupSelect.h"
#include"Engine/Systems/ImageSystem.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/DirectX_11/Input.h"
#include"SnowCone_ToppingUI.h"

namespace
{
	const XMFLOAT3 IMAGEPOS[] = { {-1400,500,0},{-1400,0,0},{-1400,-500,0} };
	const int SYRUP_LIMIT = 3;
	const int CAMERANUM = 2;
}

SnowCone_SyrupSelect::SnowCone_SyrupSelect(Object* parent)
	:SnowCone_ToppingMenu(parent,"SnowCone_SyrupSelect"),
	selectFrame_(0)
{
}

SnowCone_SyrupSelect::~SnowCone_SyrupSelect()
{
}

void SnowCone_SyrupSelect::Initialize()
{
	Text selectText("シロップ", "りいてがき筆", { 0,0,200,50 }, CAMERANUM);
	selectText.SetPosition({ 50,10 });
	selectText.SetTextSize(40);
	AddComponent<Text>(selectText);
	{
		Image image(CAMERANUM);
		image.Load("Assets/Image/SnowCone_Syrup_Red.png");
		image.SetPositionAtPixel(IMAGEPOS[0]);
		AddComponent<Image>(image);
	}
	{
		Image image(CAMERANUM);
		image.Load("Assets/Image/SnowCone_Syrup_Blue.png");
		image.SetPositionAtPixel(IMAGEPOS[1]);
		AddComponent<Image>(image);
	}
	{
		Image image(CAMERANUM);
		image.Load("Assets/Image/SnowCone_SelectImage.png");
		image.SetPositionAtPixel(IMAGEPOS[0]);
		selectFrame_ = AddComponent<Image>(image);
	}
}

void SnowCone_SyrupSelect::Update()
{
	switch (state_)
	{
	case SELECT_STATE::INPUT:
		Input();
		break;
	case SELECT_STATE::MOVE:
		Move();
		break;
	case SELECT_STATE::STAY:
		break;
	default:
		break;
	}
}

void SnowCone_SyrupSelect::Move()
{
	GetComponent<Image>(selectFrame_).SetPositionAtPixel(IMAGEPOS[syrupNum_]);
	if (time_->GetSeconds<float>() >= 0.3f)
	{
		time_->Lock();
		time_->Reset();
		state_ = SELECT_STATE::INPUT;
	}
}

void SnowCone_SyrupSelect::Input()
{
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_DPAD_DOWN,1))
	{
		syrupNum_++;
		syrupNum_ = syrupNum_ % SYRUP_LIMIT;
		state_ = SELECT_STATE::MOVE;
		time_->UnLock();
	}

	else if (Input::IsPadButtonDown(XINPUT_GAMEPAD_DPAD_UP,1))
	{
		syrupNum_--;
		if (syrupNum_ < 0)
			syrupNum_ = 2;

		syrupNum_ = syrupNum_ % SYRUP_LIMIT;
		state_ = SELECT_STATE::MOVE;
		time_->UnLock();
	}
	else if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A,1))
	{
		state_ = SELECT_STATE::STAY;
		((SnowCone_ToppingUI*)GetParent())->ModeChange(SELECT_MODE::MODE_TOPPING);
	}
}

void SnowCone_SyrupSelect::Release()
{
}
