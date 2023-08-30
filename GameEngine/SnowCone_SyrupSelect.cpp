#include "SnowCone_SyrupSelect.h"
#include"Engine/Systems/ImageSystem.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/DirectX_11/Input.h"
#include"SnowCone_SyrupSumple.h"
#include"SnowCone_ToppingUI.h"

namespace
{
	const XMFLOAT3 IMAGEPOS[] = { {-1400,500,0},{-1400,0,0},{-1400,-500,0} };
	const XMFLOAT3 SELECTED_COLOR = { 100,100,100 };
	const XMFLOAT3 DEFAULT_COLOR = {0,0,0};
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
	Text selectText("ÉVÉçÉbÉv", "ÇËÇ¢ÇƒÇ™Ç´ïM", { 0,0,200,50 }, CAMERANUM);
	selectText.SetPosition({ 50,10 });
	selectText.SetTextSize(40);
	AddComponent<Text>(selectText);

	{
		Image backImage(CAMERANUM);
		backImage.Load("Assets/Image/SnowCone_Select_BuckGroundImage.png");
		backImage.SetPositionAtPixel(IMAGEPOS[0]);
		AddComponent<Image>(backImage);
	
		Image image(CAMERANUM);
		image.Load("Assets/Image/SnowCone_Syrup_RedImage.png");
		image.SetPositionAtPixel(IMAGEPOS[0]);
		AddComponent<Image>(image);


	}
	{
		Image backImage(CAMERANUM);
		backImage.Load("Assets/Image/SnowCone_Select_BuckGroundImage.png");
		backImage.SetPositionAtPixel(IMAGEPOS[1]);
		AddComponent<Image>(backImage);
		
		Image image(CAMERANUM);
		image.Load("Assets/Image/SnowCone_Syrup_BlueImage.png");
		image.SetPositionAtPixel(IMAGEPOS[1]);
		AddComponent<Image>(image);

	}
	{
		Image backImage(CAMERANUM);
		backImage.Load("Assets/Image/SnowCone_Select_BuckGroundImage.png");
		backImage.SetPositionAtPixel(IMAGEPOS[2]);
		AddComponent<Image>(backImage);

		Image image(CAMERANUM);
		image.Load("Assets/Image/SnowCone_Syrup_GreenImage.png");
		image.SetPositionAtPixel(IMAGEPOS[2]);
		AddComponent<Image>(image);
	}
	{
		Image image(CAMERANUM);
		image.Load("Assets/Image/SnowCone_SelectImage.png");
		image.SetPositionAtPixel(IMAGEPOS[0]);
		image.SetColor(DEFAULT_COLOR);
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
	GetComponent<Image>(selectFrame_).SetPositionAtPixel(IMAGEPOS[selectNum_]);
	if (time_->GetSeconds<float>() >= 0.2f)
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
		selectNum_++;
		selectNum_ = selectNum_ % SYRUP_LIMIT;
		state_ = SELECT_STATE::MOVE;
		time_->UnLock();

		((SnowCone_SyrupSumple*)FindObject("SnowCone_SyrupSumple"))->ChangeSumple(selectNum_);
	}

	else if (Input::IsPadButtonDown(XINPUT_GAMEPAD_DPAD_UP,1))
	{
		selectNum_--;
		if (selectNum_ < 0)
			selectNum_ = 2;

		selectNum_ = selectNum_ % SYRUP_LIMIT;
		state_ = SELECT_STATE::MOVE;
		time_->UnLock();
		((SnowCone_SyrupSumple*)FindObject("SnowCone_SyrupSumple"))->ChangeSumple(selectNum_);
	}
	else if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A,1))
	{
		state_ = SELECT_STATE::STAY;
		GetComponent<Image>(selectFrame_).SetAlpha(0.4f);
		((SnowCone_ToppingUI*)GetParent())->ModeChange(SELECT_MODE::MODE_TOPPING);
	}
}

void SnowCone_SyrupSelect::UIReset()
{
	selectNum_ = 0;
	GetComponent<Image>(selectFrame_).SetPositionAtPixel(IMAGEPOS[selectNum_]);
	GetComponent<Image>(selectFrame_).SetAlpha(1);
	state_ = SELECT_STATE::INPUT;
}

void SnowCone_SyrupSelect::Release()
{
}
