#include "SnowConeMaker_Topping.h"
#include"Engine/GameObject/CameraManager.h"
namespace
{
	const XMVECTOR DEFAULT_POS = XMVectorSet(40, 0, -40, 0);
}

SnowConeMaker_Topping::SnowConeMaker_Topping(Object* parent)
	:GameObject(parent,"SnowConeMaker_Topping")
{
}

SnowConeMaker_Topping::~SnowConeMaker_Topping()
{
}

void SnowConeMaker_Topping::Initialize()
{
	transform_->position_ = DEFAULT_POS;
	CameraManager::GetCamera(playerNum_).SetPosition(transform_->position_);
}

void SnowConeMaker_Topping::Update()
{
}

void SnowConeMaker_Topping::Release()
{
}
