#include "SnowConeMaker_Topping.h"
#include"Engine/GameObject/CameraManager.h"
#include"Engine/Systems/ModelSystem.h"

namespace
{
	const XMVECTOR DEFAULT_POS = XMVectorSet(40, 10, -40, 0);
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

	
	//{
	//
	//	Test_Model_ECSver model(this);
	//	model.Load("Assets/Model/SnowCone_Cup.fbx");
	//	AddComponent<Test_Model_ECSver>(model);
	//	transform_->position_ = XMVectorSet(40, 0, -30, 0);
	//}
	//{
	//
	//	Test_Model_ECSver model(this);
	//	model.Load("Assets/Model/SnowCone_Ice.fbx");
	//	AddComponent<Test_Model_ECSver>(model);
	//	transform_->position_ = XMVectorSet(40, 5, -30, 0);
	//}
	CameraManager::GetCamera(playerNum_).SetTarget(XMVectorSet(40, 0, -30, 0));
}

void SnowConeMaker_Topping::Update()
{
}

void SnowConeMaker_Topping::Release()
{
}
