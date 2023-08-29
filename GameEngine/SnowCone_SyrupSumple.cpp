#include "SnowCone_SyrupSumple.h"
#include"Engine/Systems/ModelSystem.h"
#include"Engine/Systems/ImageSystem.h"
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
		Image image(2, 1);
		image.Load("Assets/Image/SnowCone_Syrup_RedImage.png");
		image.SetPositionAtPixel({ 0,180, 0 });
		image.SetAlpha(0);
		AddComponent<Image>(image);
	}
	{
		Image image(2, 1);
		image.Load("Assets/Image/SnowCone_Syrup_BlueImage.png");
		image.SetPositionAtPixel({ 0,180, 0 });
		image.SetAlpha(0);
		AddComponent<Image>(image);
	}
	{
		Image image(2, 1);
		image.Load("Assets/Image/SnowCone_Syrup_GreenImage.png");
		image.SetPositionAtPixel({ 0,180, 0 });
		image.SetAlpha(0);
		AddComponent<Image>(image);
	}
	//{
	//	Test_Model_ECSver model(this);
	//	model.Load("Assets/Model/SnowCone_Syrup_Blue.fbx");
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

void SnowCone_SyrupSumple::ChangeSumple(int num)
{
	for (auto& imageNum : GetComponentList<Image>())
		Coordinator::GetComponent<Image>(imageNum).SetAlpha(0);

	if (num < GetComponentList<Image>().size())
		GetComponent<Image>(num).SetAlpha(1);
}

void SnowCone_SyrupSumple::SetSyrupSize(float size)
{
	for (auto& imageNum : GetComponentList<Image>())
		Coordinator::GetComponent<Image>(imageNum).SetSize({ 1,1+size,0 });
}

void SnowCone_SyrupSumple::Reset()
{
	for (auto& imageNum : GetComponentList<Image>())
	{
		Coordinator::GetComponent<Image>(imageNum).SetSize({ 1,1,0 });
		Coordinator::GetComponent<Image>(imageNum).SetAlpha(0);
	}
}

void SnowCone_SyrupSumple::Release()
{
}
