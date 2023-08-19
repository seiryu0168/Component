#include "Title.h"
#include"Engine/DirectX_11/Input.h"
#include"Engine/Systems/ImageSystem.h"
#include"Engine/newSceneManager.h"
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
}

void Title::Update()
{
	if (Input::IsPadAnyButtonDown())
	{
		newSceneManager::ChangeScene(SCENE_ID::MENU);
	}
}

void Title::Release()
{
}
