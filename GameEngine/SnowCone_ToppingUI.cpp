#include "SnowCone_ToppingUI.h"
#include"Engine/Systems/ImageSystem.h"
#include"Engine/Systems/TextSystem.h"
#include"SnowCone_SyrupSelect.h"
#include"SnowCone_ToppingSelect.h"

namespace
{
	const XMFLOAT2 COMMANDTEXT_POS[] = { { 150,850 },{ 150,900 } ,{ 1050,850 }, { 1450,850 },{ 1050,900 },{ 1450,900 } };
	const XMFLOAT3 COMMANDIMAGE_POS[] = { {-1700,-675,0},{-1700,-700,0},{100,-675,0} };
	
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
	
	////プレイヤー1のコマンド
	//{
	//	Text text("削る", "りいてがき筆", { 0,0,500,50 });
	//	text.SetPosition(COMMANDTEXT_POS[0]);
	//	text.SetTextSize(40);
	//	AddComponent<Text>(text);
	//	
	//	Image image(0);
	//	image.Load("Assets/Image/Buttons/BTN_B.png");
	//	image.SetPositionAtPixel(COMMANDIMAGE_POS[0]);
	//	image.SetSize({ 0.7f,0.7f,0 });
	//	AddComponent<Image>(image);
	//}
	//
	//{
	//	Text text("かき氷を渡す", "りいてがき筆", { 0,0,500,50 });
	//	text.SetPosition(COMMANDTEXT_POS[1]);
	//	text.SetTextSize(40);
	//	AddComponent<Text>(text);
	//
	//	Image image(0);
	//	image.Load("Assets/Image/Buttons/BTN_A.png");
	//	image.SetPositionAtPixel(COMMANDIMAGE_POS[1]);
	//	image.SetSize({ 0.7f,0.7f,0 });
	//	AddComponent<Image>(image);
	//}
	//
	////プレイヤー2のコマンド
	//{
	//	Text text("決定", "りいてがき筆", { 0,0,500,50 });
	//	text.SetPosition(COMMANDTEXT_POS[2]);
	//	text.SetTextSize(40);
	//	AddComponent<Text>(text);
	//
	//	Image image(0);
	//	image.Load("Assets/Image/Buttons/BTN_A.png");
	//	image.SetPositionAtPixel(COMMANDIMAGE_POS[2]);
	//	image.SetSize({ 0.7f,0.7f,0 });
	//	AddComponent<Image>(image);
	//}
	//
	//{
	//	Text text("選択", "りいてがき筆", { 0,0,500,50 });
	//	text.SetPosition(COMMANDTEXT_POS[3]);
	//	text.SetTextSize(40);
	//	AddComponent<Text>(text);
	//
	//	Image image(0);
	//	image.Load("Assets/Image/Buttons/BTN_A.png");
	//	image.SetPositionAtPixel(COMMANDIMAGE_POS[1]);
	//	image.SetSize({ 0.7f,0.7f,0 });
	//	AddComponent<Image>(image);
	//}
	//{
	//	Text text("かき氷を出す", "りいてがき筆", { 0,0,500,50 });
	//	text.SetPosition(COMMANDTEXT_POS[4]);
	//	text.SetTextSize(40);
	//	AddComponent<Text>(text);
	//
	//	Image image(0);
	//	image.Load("Assets/Image/Buttons/BTN_A.png");
	//	image.SetPositionAtPixel(COMMANDIMAGE_POS[1]);
	//	image.SetSize({ 0.7f,0.7f,0 });
	//	AddComponent<Image>(image);
	//}
	//{
	//	Text text("かき氷を受け取る", "りいてがき筆", { 0,0,500,50 });
	//	text.SetPosition(COMMANDTEXT_POS[5]);
	//	text.SetTextSize(40);
	//	AddComponent<Text>(text);
	//
	//	Image image(0);
	//	image.Load("Assets/Image/Buttons/BTN_A.png");
	//	image.SetPositionAtPixel(COMMANDIMAGE_POS[1]);
	//	image.SetSize({ 0.7f,0.7f,0 });
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

void SnowCone_ToppingUI::ResetUI()
{
	syrupSelect_->Reset();
	toppingSelect_->Reset();
	ModeChange(SELECT_MODE::MODE_SYRUP);
}

void SnowCone_ToppingUI::Release()
{
}
