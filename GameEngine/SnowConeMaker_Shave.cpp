#include "SnowConeMaker_Shave.h"
#include"Engine/GameObject/CameraManager.h"
namespace
{
	const XMVECTOR DEFAULT_POS = XMVectorSet(-40, 0, -40, 0);
}

SnowConeMaker_Shave::SnowConeMaker_Shave(Object* parent)
	:GameObject(parent, "SnowConeMaker_Shave")
{
}

SnowConeMaker_Shave::~SnowConeMaker_Shave()
{
}

void SnowConeMaker_Shave::Initialize()
{
	transform_->position_ = DEFAULT_POS;
	CameraManager::GetCamera(playerNum_).SetPosition(transform_->position_);
}

void SnowConeMaker_Shave::Update()
{
}

void SnowConeMaker_Shave::Release()
{
}
