#include "MainScene.h"
#include"TestObject.h"
#include"TestObjectChild.h"
//#include"DrawComponent.h"
#include"Engine/DirectX_11/Input.h"
//#include"Engine/SceneManager.h"
#include"newSceneManager.h"
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
	
}

void MainScene::Release()
{
}
