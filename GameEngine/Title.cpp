#include "Title.h"
#include"Engine/DirectX_11/Input.h"
#include"Engine/Systems/ImageSystem.h"
#include"Engine/newSceneManager.h"
#include"Engine/Systems/TextSystem.h"
Title::Title(Object* parent)
	:GameObject(parent,"Title")
{
}

Title::~Title()
{
}

void Title::Initialize()
{
	Image image;
	image.Load("Assets/Image/Ennichi_TitleImage.jpg");
	AddComponent<Image>(image);
	
	Text messageText("ƒ{ƒ^ƒ“‚ð‰Ÿ‚µ‚Ä‚­‚¾‚³‚¢\nPush Any Button", "‚è‚¢‚Ä‚ª‚«•M", {0,0,1100,200});
	messageText.SetAlinmentType(ALINMENT_TYPE::CENTER_TOP);
	messageText.SetRatio(0.23f, 0.72f);
	messageText.SetTextSize(100);
	AddComponent<Text>(messageText);

	time_ = std::make_unique<Time::Watch>();
	time_->UnLock();
}

void Title::Update()
{
	if (Input::IsPadAnyButtonDown())
	{
		newSceneManager::ChangeScene(SCENE_ID::MENU);
	}
	
	GetComponent<Text>().SetColor({ 0,0,0,(sinf(time_->GetSeconds<float>())*0.5f)+0.5f });
}

void Title::Release()
{
}
