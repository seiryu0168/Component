#include "SnowCone_ToppingSumple.h"
#include"Easing.h"
#include"Engine/Systems/ModelSystem.h"
#include"Engine/Systems/ImageSystem.h"

namespace
{
	const XMFLOAT3 SYRUPPOS = { 0,180,0 };
	const XMFLOAT3 DEFAULT_POS = { 0,1200.0f,0 };
}

SnowCone_ToppingSumple::SnowCone_ToppingSumple(Object* parent)
	:GameObject(parent ,"SnowCone_ToppingSumple"),
	sumplePos_({0,0,0}),
	currentNum_(0),
	offsetPosY_(0), 
	easingTime_(1.0f),
	isMove_(false)
{
}

SnowCone_ToppingSumple::~SnowCone_ToppingSumple()
{
}

void SnowCone_ToppingSumple::Initialize()
{
	{
		Image image(2, 1);
		image.Load("Assets/Image/SnowCone_Topping_Adzuki.png");
		image.SetPositionAtPixel(SYRUPPOS);
		image.SetAlpha(0);
		AddComponent<Image>(image);
	}
	{
		Image image(2, 1);
		image.Load("Assets/Image/SnowCone_Topping_Blueberry.png");
		image.SetPositionAtPixel(SYRUPPOS);
		image.SetAlpha(0);
		AddComponent<Image>(image);
	}
	{
		Image image(2, 1);
		image.Load("Assets/Image/SnowCone_Topping_Raspberry.png");
		image.SetPositionAtPixel(SYRUPPOS);
		image.SetAlpha(0);
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

void SnowCone_ToppingSumple::Update()
{
	if (isMove_)
	{
		MoveSumple((DEFAULT_POS.y*Easing::EaseLinear(easingTime_)) + offsetPosY_);
		easingTime_ -= 0.03f;
	}
}

void SnowCone_ToppingSumple::ChangeSumple(int num)
{
	for (auto& imageNum : GetComponentList<Image>())
		Coordinator::GetComponent<Image>(imageNum).SetAlpha(0);
	
	if (num < GetComponentList<Image>().size())
	{
		GetComponent<Image>(num).SetAlpha(1);
		currentNum_ = num;
	}
}

void SnowCone_ToppingSumple::SetSumpleSize(float size, float pos)
{

	size += 1.0f;
	float toppingPosition = SYRUPPOS.y + (256.0f * size) -30.0f;
	for (auto& imageNum : GetComponentList<Image>())
	{
		Coordinator::GetComponent<Image>(imageNum).SetPositionAtPixel({ 0,toppingPosition,0 });
		Coordinator::GetComponent<Image>(imageNum).SetSize({ 1 / size,1 ,0});
		Coordinator::GetComponent<Image>(imageNum).SetAlpha(0);
	}
	offsetPosY_ = toppingPosition;
}

void SnowCone_ToppingSumple::MoveSumple(float deltaPos)
{
	sumplePos_.y = deltaPos;
	for (auto& imageNum : GetComponentList<Image>())
	{
		Coordinator::GetComponent<Image>(imageNum).SetPositionAtPixel(sumplePos_);
	}
	if (easingTime_ <= 0)
	{
		isMove_ = false;
		easingTime_ = 1.0f;
	}
}

void SnowCone_ToppingSumple::Reset()
{
	for (auto& imageNum : GetComponentList<Image>())
	{
		Coordinator::GetComponent<Image>(imageNum).SetPositionAtPixel(DEFAULT_POS);
		Coordinator::GetComponent<Image>(imageNum).SetSize({ 1,1,0 });
		Coordinator::GetComponent<Image>(imageNum).SetAlpha(0);
	}

	sumplePos_ = { 0,0,0 };
}

void SnowCone_ToppingSumple::Release()
{
}
