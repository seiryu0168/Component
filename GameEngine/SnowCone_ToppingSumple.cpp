#include "SnowCone_ToppingSumple.h"
#include"Engine/Systems/ModelSystem.h"
SnowCone_ToppingSumple::SnowCone_ToppingSumple(Object* parent)
	:GameObject(parent ,"SnowCone_ToppingSumple")
{
}

SnowCone_ToppingSumple::~SnowCone_ToppingSumple()
{
}

void SnowCone_ToppingSumple::Initialize()
{
	{
		Test_Model_ECSver model(this);
		model.Load("Assets/Model/SnowCone_Topping_Adzuki.fbx");
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

void SnowCone_ToppingSumple::ChangeSumple(int num)
{
	for (auto& modelNum : GetComponentList<Test_Model_ECSver>())
		Coordinator::GetComponent<Test_Model_ECSver>(modelNum).SetDraw(false);
	
	if (num < GetComponentList<Test_Model_ECSver>().size())
		GetComponent<Test_Model_ECSver>(num).SetDraw(true);
}

void SnowCone_ToppingSumple::Release()
{
}
