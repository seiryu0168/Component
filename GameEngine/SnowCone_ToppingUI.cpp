#include "SnowCone_ToppingUI.h"
#include"Engine/Systems/ImageSystem.h"
#include"SnowCone_SyrupSelect.h"
#include"SnowCone_ToppingSelect.h"

namespace
{
	const XMFLOAT3 IMAGEPOS[] = { {-1000,500,0},{-1000,0,0} };
}

SnowCone_ToppingUI::SnowCone_ToppingUI(Object* parent)
	:GameObject(parent,"SnowCone_ToppingUI"),
	syrupSelect_(nullptr),
	toppingSelect_(nullptr),
	mode_(SELECT_MODE::MODE_SYRUP)
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

	toppingSelect_ = Instantiate<SnowCone_ToppingSelect>(this);
	syrupSelect_ = Instantiate<SnowCone_SyrupSelect>(this);
	toppingSelect_->SetUpdate(false);

}

void SnowCone_ToppingUI::Update()
{

}

int SnowCone_ToppingUI::GetSyrupData()
{
	return syrupSelect_->GetSyrupNum();
}

int SnowCone_ToppingUI::GetToppingData()
{
	return toppingSelect_->GetToppingNum();
}

void SnowCone_ToppingUI::ModeChange(SELECT_MODE mode)
{
	switch (mode)
	{
	case SELECT_MODE::MODE_SYRUP:
		syrupSelect_->SetUpdate(true);
		toppingSelect_->SetUpdate(false);
		break;
	case SELECT_MODE::MODE_TOPPING:
		syrupSelect_->SetUpdate(false);
		toppingSelect_->SetUpdate(true);
		break;
	case SELECT_MODE::MODE_COMPLETE:
		syrupSelect_->SetUpdate(false);
		toppingSelect_->SetUpdate(false);
		break;
	default:
		break;
	}
}

void SnowCone_ToppingUI::Release()
{
}
