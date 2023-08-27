#include "SnowConeMaker_Topping.h"
#include"Engine/GameObject/CameraManager.h"
#include"Engine/Systems/ModelSystem.h"
#include"Engine/DirectX_11/Input.h"
#include"MiniGames/SnowConeMaking.h"
#include"SnowCone_Cup.h"
#include"SnowCone_ToppingUI.h"
#include"SnowCone_ToppingSumple.h"
#include"SnowCone_SyrupSumple.h"

namespace
{
	const XMVECTOR DEFAULT_POS = XMVectorSet(40, 10, -40, 0);
	const XMVECTOR TARGET_POS = XMVectorSet(40, 0, -30, 0);
	const XMVECTOR DEFAULT_SUMPLE_POS= XMVectorSet(0, 0, -60, 0);
}

SnowConeMaker_Topping::SnowConeMaker_Topping(Object* parent)
	:GameObject(parent,"SnowConeMaker_Topping"),
	snowCone_(nullptr),
	playerNum_(0),
	toppingSumple_(nullptr)
{
}

SnowConeMaker_Topping::~SnowConeMaker_Topping()
{
}

void SnowConeMaker_Topping::Initialize()
{
	
	transform_->position_ = DEFAULT_POS;

	CameraManager::GetCamera(playerNum_+1).SetPosition(transform_->position_);
	CameraManager::GetCamera(playerNum_+1).SetTarget(TARGET_POS);
	Instantiate<SnowCone_ToppingUI>(this);
	toppingSumple_ = Instantiate<SnowCone_ToppingSumple>(GetParent());
	toppingSumple_->GetTransform()->position_ = DEFAULT_SUMPLE_POS;
	syrupSumple_ = Instantiate<SnowCone_SyrupSumple>(GetParent());
	syrupSumple_->GetTransform()->position_ = DEFAULT_SUMPLE_POS;

}

void SnowConeMaker_Topping::Update()
{
	switch (Input::GetPadAnyDown(playerNum_))
	{
	case XINPUT_GAMEPAD_X:
		//‚©‚«•X‚ðo‚·
		if (snowCone_)
		{
			//‚©‚«•X‚Ì•]‰¿
			SnowCone_ToppingUI* ui = (SnowCone_ToppingUI*)FindChild("SnowCone_ToppingUI");
			((SnowConeMaking*)GetParent())->Evaluation(snowCone_->GetConeSize(),
													   ui->GetSyrupData(),
													   ui->GetToppingData());
			//•]‰¿‚ªI‚í‚Á‚½‚çÁ‚·
			snowCone_->KillMe();
			snowCone_->RemoveIce();
			snowCone_ = nullptr;
			ResetSelectUI();
		}
		snowCone_ = ((SnowConeMaking*)GetParent())->GetCup();

		if (snowCone_)
		{
			snowCone_->GetTransform()->position_ = TARGET_POS;
			syrupSumple_->GetTransform()->scale_.y = 1+snowCone_->GetConeSize();
			SetToppingSumple();
			SetSyrupSumple();
		}
		break;
	default:
		break;
	}

}

void SnowConeMaker_Topping::SetTopping()
{
	snowCone_->SetTopping(0);
}

void SnowConeMaker_Topping::SetToppingSumple()
{
	toppingSumple_->GetTransform()->position_ = snowCone_->GetIceBonePos("Bone");
}

void SnowConeMaker_Topping::SetSyrupSumple()
{
	syrupSumple_->GetTransform()->position_ = snowCone_->GetIceBonePos("Bone");
}

void SnowConeMaker_Topping::ResetSelectUI()
{
	toppingSumple_->GetTransform()->position_ = DEFAULT_SUMPLE_POS;
	toppingSumple_->ChangeSumple(0);
	syrupSumple_->GetTransform()->position_ = DEFAULT_SUMPLE_POS;
	syrupSumple_->ChangeSumple(0);
	((SnowCone_ToppingUI*)FindChild("SnowCone_ToppingUI"))->ResetUI();
}

void SnowConeMaker_Topping::Release()
{
}
