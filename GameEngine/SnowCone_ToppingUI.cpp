#include "SnowCone_ToppingUI.h"
#include"Engine/Systems/ImageSystem.h"
#include"SnowCone_SyrupSelect.h"
namespace
{
	const XMFLOAT3 IMAGEPOS[] = { {-1000,500,0},{-1000,0,0} };
}

SnowCone_ToppingUI::SnowCone_ToppingUI(Object* parent)
	:GameObject(parent,"SnowCone_ToppingUI"),
	syrupSelect_(nullptr),
	toppingSelect_(nullptr)
{
}

SnowCone_ToppingUI::~SnowCone_ToppingUI()
{
}

void SnowCone_ToppingUI::Initialize()
{
	//{
	//	Image image(1);
	//	image.Load("Assets/Image/SnowCone_Syrup_Red.png");
	//	image.SetPositionAtPixel(IMAGEPOS[0]);
	//	AddComponent<Image>(image);
	//}
	//{
	//	Image image(1);
	//	image.Load("Assets/Image/SnowCone_Syrup_Blue.png");
	//	image.SetPositionAtPixel(IMAGEPOS[1]);
	//	AddComponent<Image>(image);
	//}
	//{
	//	Image image(1);
	//	image.Load("Assets/Image/SnowCone_SelectImage.png");
	//	image.SetPositionAtPixel(IMAGEPOS[0]);
	//	AddComponent<Image>(image);
	//}

	syrupSelect_ = Instantiate<SnowCone_SyrupSelect>(this);

}

void SnowCone_ToppingUI::Update()
{

}

void SnowCone_ToppingUI::Release()
{
}
