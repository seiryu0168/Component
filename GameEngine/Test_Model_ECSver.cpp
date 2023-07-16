#include "Test_Model_ECSver.h"
#include"ModelManager_ECSver.h"
Test_Model_ECSver::Test_Model_ECSver()
{
}

Test_Model_ECSver::Test_Model_ECSver(GameObject* object)
	:attachObject_(object),
	type(SHADER_TYPE::SHADER_3D),
	animationFrame_(0)
{
}

Test_Model_ECSver::Test_Model_ECSver(const Test_Model_ECSver& object)
{
	hModel_ = object.hModel_;
	type = object.type;
	animationFrame_ = object.animationFrame_;
	fbx_ = object.fbx_;
	materialList_ = object.materialList_;
	meshEntity_ = object.meshEntity_;
	attachObject_ = object.attachObject_;
}

bool Test_Model_ECSver::Load(std::string fileName)
{
	fbx_=ModelManager_ECSver::Load(fileName);
	return true;
}

void Test_Model_ECSver::RayCast(RayCastData& rayData)
{
	fbx_->RayCast(rayData, *attachObject_->GetTransform());
}

void Test_Model_ECSver::Draw()
{
	fbx_->Draw(*attachObject_->GetTransform(), type, animationFrame_);
}
