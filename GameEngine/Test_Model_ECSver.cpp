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

bool Test_Model_ECSver::Load(std::string fileName)
{
	fbx_=ModelManager_ECSver::Load(fileName);
	return true;
}

void Test_Model_ECSver::RayCast(RayCastData& rayData)
{
	fbx_->RayCast(rayData, attachObject_->GetComponent<Transform>());
}

void Test_Model_ECSver::Draw()
{
	fbx_->Draw(attachObject_->GetComponent<Transform>(), type, animationFrame_);
}
