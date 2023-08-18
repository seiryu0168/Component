#include "Select_StaticUI.h"
#include"Engine/Systems/ImageSystem.h"
#include"Engine/Systems/TextSystem.h"
Select_StaticUI::Select_StaticUI(Object* parent)
	:GameObject(parent,"Select_StaticUI")
{
}

Select_StaticUI::~Select_StaticUI()
{
}

void Select_StaticUI::Initialize()
{

	Text selectText("ゲームセレクト","りいてがき筆",{0,0,900,50});
	selectText.SetTextSize(100);
	selectText.SetPosition({610,0});
	AddComponent<Text>(selectText);

	Image image;
	image.Load("Assets/Image/SelectUI_Shooting_BackGroundImage.jpg");
	AddComponent<Image>(image);

}

void Select_StaticUI::Release()
{
}
