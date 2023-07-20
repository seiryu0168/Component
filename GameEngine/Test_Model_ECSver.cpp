#include "Test_Model_ECSver.h"
#include"ModelManager_ECSver.h"
Test_Model_ECSver::Test_Model_ECSver()
	:Test_Model_ECSver(nullptr)
{
}

Test_Model_ECSver::Test_Model_ECSver(GameObject* object)
	:attachObject_(object),
	type_(SHADER_TYPE::SHADER_3D),
	animationFrame_(0),
	hModel_(-1),
	meshEntity_(0)
{
}

bool Test_Model_ECSver::Load(const std::string& fileName)
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
	fbx_->Draw(*attachObject_->GetTransform(), type_, animationFrame_);
}
