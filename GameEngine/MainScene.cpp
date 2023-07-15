#include "MainScene.h"
#include"TestObject.h"
#include"TestObjectChild.h"
#include"DrawComponent.h"
#include"Engine/DirectX_11/Input.h"
#include"Engine/SceneManager.h"
MainScene::MainScene(Object* parent)
	:GameObject(parent,"MainScene")
{
}

MainScene::~MainScene()
{
}

void MainScene::Initialize()
{
	Instantiate<TestObject>(this);
	Instantiate<TestObjectChild>(this);
}

void MainScene::Update()
{
	if(Input::IsKeyDown(DIK_A))
	{
		((SceneManager*)FindObject("SceneManager"))->ChangeScene(SCENE_ID::SCENE_ID_SUB);
	}
	
}

void MainScene::Release()
{
}
