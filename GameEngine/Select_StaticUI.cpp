#include "Select_StaticUI.h"
#include "Engine/DirectX_11/Math.h"
#include"Engine/Systems/ImageSystem.h"
#include"Engine/Systems/TextSystem.h"

namespace
{
	static const int Period = 3840;
}

Select_StaticUI::Select_StaticUI(Object* parent)
	:GameObject(parent,"Select_StaticUI"), Frame_(0), backGroundImageList_()
{
}

Select_StaticUI::~Select_StaticUI()
{
}

void Select_StaticUI::Initialize()
{

	Text selectText("ゲームセレクト","りいてがき筆",{0,0,900,50});
	selectText.SetTextSize(100);
	selectText.SetRatio(0.3f, 0.0f);
	//selectText.SetPosition({610,0});
	AddComponent<Text>(selectText);

	//Image image;
	//image.Load("Assets/Image/SelectUI_Shooting_BackGroundImage.jpg");
	//AddComponent<Image>(image);

	{
		Image i;
		i.Load("Assets/Image/BG_fes.png", "Select_Static");
		int I = AddComponent(i);
		backGroundImageList_.push_back(&GetComponent<Image>(I));
	}

	/*{
		Image i;
		i.Load("Assets/Image/seigaiha.png", "Select_Static");
		int I = AddComponent(i);
		backGroundImageList_.push_back(&GetComponent<Image>(I));
	}*/
}

void Select_StaticUI::Update()
{
	float Ratio = ++Frame_ / (float)Period;
	float sin = Math::Sincurve(Ratio);
	for (auto&& itr : backGroundImageList_)
	{
		itr->SetScroll({ Ratio, sin });
	}
}

void Select_StaticUI::Release()
{
}
