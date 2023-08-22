#include "SnowCone_ToppingSelect.h"
#include"Engine/Systems/ImageSystem.h"
#include"Engine/DirectX_11/Input.h"

namespace
{
	const XMFLOAT3 IMAGEPOS[] = { {1000,500,0},{1000,0,0},{1000,-500,0} };
	const int SYRUP_LIMIT = 3;
}

SnowCone_ToppingSelect::SnowCone_ToppingSelect(Object* parent)
	:SnowCone_ToppingMenu(parent,"SnowCone_ToppingSelect"),
	selectFrame_(0)
{
}

SnowCone_ToppingSelect::~SnowCone_ToppingSelect()
{
}

void SnowCone_ToppingSelect::Initialize()
{
	{
		Image image(1);
		image.Load("Assets/Image/SnowCone_Topping_Adzuki.png");
		AddComponent<Image>(image);
	}

	{
		Image image(1);
		image.Load("Assets/Image/SnowCone_Toppin_Blueberry.png");
		AddComponent<Image>(image);
	}

	{
		Image image(1);
		image.Load("Assets/Image/SnowCone_SelectImage.png");
		AddComponent<Image>(image);
	}
}

void SnowCone_ToppingSelect::Update()
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
void SnowCone_ToppingSelect::Move()
{
	GetComponent<Image>(selectFrame_).SetPositionAtPixel(IMAGEPOS[syrupNum_]);
	if (time_->GetSeconds<float>() >= 0.3f)
	{
		time_->Lock();
		time_->Reset();
		state_ = SELECT_STATE::INPUT;
	}
}

void SnowCone_ToppingSelect::Input()
{
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_DPAD_DOWN, 1))
	{
		syrupNum_++;
		syrupNum_ = syrupNum_ % SYRUP_LIMIT;
		state_ = SELECT_STATE::MOVE;
		time_->UnLock();
	}

	else if (Input::IsPadButtonDown(XINPUT_GAMEPAD_DPAD_UP, 1))
	{
		syrupNum_--;
		if (syrupNum_ < 0)
			syrupNum_ = 2;

		syrupNum_ = syrupNum_ % SYRUP_LIMIT;
		state_ = SELECT_STATE::MOVE;
		time_->UnLock();
	}
	else if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
	{

	}
}

void SnowCone_ToppingSelect::Release()
{
}
