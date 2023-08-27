#include "SnowCone_SyrupSumple.h"
#include"Engine/Systems/ModelSystem.h"
SnowCone_SyrupSumple::SnowCone_SyrupSumple(Object* parent)
	:GameObject(parent,"SnowCone_SyrupSumple")
{
}

SnowCone_SyrupSumple::~SnowCone_SyrupSumple()
{
}

void SnowCone_SyrupSumple::Initialize()
{
	{
		Test_Model_ECSver model(this);
		model.Load("Assets/Model/SnowCone_Syrup_Blue.fbx");
		model.SetDraw(false);
		AddComponent<Test_Model_ECSver>(model);
	}
	{
		Test_Model_ECSver model(this);
		model.Load("Assets/Model/AAA.fbx");
		model.SetDraw(false);
		AddComponent<Test_Model_ECSver>(model);
	}
	{
		Test_Model_ECSver model(this);
		model.Load("Assets/Model/AAA.fbx");
		model.SetDraw(false);
		AddComponent<Test_Model_ECSver>(model);
	}
}

void SnowCone_SyrupSumple::ChangeSumple(int num)
{
	for (auto& modelNum : GetComponentList<Test_Model_ECSver>())
		Coordinator::GetComponent<Test_Model_ECSver>(modelNum).SetDraw(false);

	if (num < GetComponentList<Test_Model_ECSver>().size())
		GetComponent<Test_Model_ECSver>(num).SetDraw(true);
}

void SnowCone_SyrupSumple::Release()
{
}
