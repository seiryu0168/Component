#include "Test_Model_ECSver.h"
#include"Engine/ResourceManager/Model.h"
Test_Model_ECSver::Test_Model_ECSver()
{
}

Test_Model_ECSver::Test_Model_ECSver(GameObject* object)
	:attachObject_(object)
{
}

bool Test_Model_ECSver::Load(std::string fileName)
{
	hModel_ = ModelManager::Load(fileName);
}

void Test_Model_ECSver::RayCast(RayCastData& rayData)
{
	ModelManager::RayCast(hModel_, rayData);
}

void Test_Model_ECSver::Draw()
{
	ModelManager::SetTransform(hModel_, attachObject_->GetComponent<Transform>());
	ModelManager::Draw(hModel_);
}
