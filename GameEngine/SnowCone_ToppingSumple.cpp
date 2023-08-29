#include "SnowCone_ToppingSumple.h"
#include"Engine/Systems/ModelSystem.h"
#include"Engine/Systems/ImageSystem.h"


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
		Image image(2, 0);
		image.Load("Assets/Image/SnowCone_Topping_Adzuki.png");
		AddComponent<Image>(image);
	}
	{
		Image image(2, 0);
		image.Load("Assets/Image/SnowCone_Topping_Adzuki.png");
		AddComponent<Image>(image);
	}
	{
		Image image(2, 0);
		image.Load("Assets/Image/SnowCone_Topping_Adzuki.png");
		AddComponent<Image>(image);
	}


	//{
	//	Test_Model_ECSver model(this);
	//	model.Load("Assets/Model/SnowCone_Topping_Adzuki.fbx");
	//	model.SetDraw(false);
	//	AddComponent<Test_Model_ECSver>(model);
	//}
	//{
	//	Test_Model_ECSver model(this);
	//	model.Load("Assets/Model/AAA.fbx");
	//	model.SetDraw(false);
	//	AddComponent<Test_Model_ECSver>(model);
	//}
	//{
	//	Test_Model_ECSver model(this);
	//	model.Load("Assets/Model/AAA.fbx");
	//	model.SetDraw(false);
	//	AddComponent<Test_Model_ECSver>(model);
	//}
}

void SnowCone_ToppingSumple::ChangeSumple(int num)
{
	for (auto& imageNum : GetComponentList<Image>())
		Coordinator::GetComponent<Image>(imageNum).SetAlpha(0);
	
	if (num < GetComponentList<Image>().size())
		GetComponent<Image>(num).SetAlpha(1);
}

void SnowCone_ToppingSumple::Release()
{
}
