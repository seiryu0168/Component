#include "SnowConeMaker_Topping.h"
#include"Engine/GameObject/CameraManager.h"
#include"Engine/Systems/ModelSystem.h"
#include"Engine/DirectX_11/Input.h"
#include"MiniGames/SnowConeMaking.h"
#include"SnowCone_Cup.h"
#include"SnowCone_ToppingUI.h"

namespace
{
	const XMVECTOR DEFAULT_POS = XMVectorSet(40, 10, -40, 0);
	const XMVECTOR TARGET_POS = XMVectorSet(40, 0, -30, 0);
}

SnowConeMaker_Topping::SnowConeMaker_Topping(Object* parent)
	:GameObject(parent,"SnowConeMaker_Topping"),
	snowCone_(nullptr),
	playerNum_(0)
{
}

SnowConeMaker_Topping::~SnowConeMaker_Topping()
{
}

void SnowConeMaker_Topping::Initialize()
{
	
	transform_->position_ = DEFAULT_POS;

	CameraManager::GetCamera(playerNum_).SetPosition(transform_->position_);
	CameraManager::GetCamera(playerNum_).SetTarget(TARGET_POS);
	Instantiate<SnowCone_ToppingUI>(this);
}

void SnowConeMaker_Topping::Update()
{
	switch (Input::GetPadAnyDown(playerNum_))
	{
	case XINPUT_GAMEPAD_X:
		//‚©‚«•X‚ðo‚·
		if (snowCone_)
		{
			snowCone_->KillMe();
			snowCone_->RemoveIce();
			snowCone_ = nullptr;
		}
		snowCone_ = ((SnowConeMaking*)GetParent())->GetCup();

		if (snowCone_)
			snowCone_->GetTransform()->position_ = TARGET_POS;
		break;

	case XINPUT_GAMEPAD_A:
		if (snowCone_)
		{
			snowCone_->SetTopping(0);
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

void SnowConeMaker_Topping::Release()
{
}
