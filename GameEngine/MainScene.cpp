#include "MainScene.h"
#include"TestObject.h"
MainScene::MainScene(GameObject* parent)
	:GameObject(parent,"MainScene")
{
}

MainScene::~MainScene()
{
}

void MainScene::Initialize()
{
	Instantiate<TestObject>(this);
}

void MainScene::Update()
{
	
}

void MainScene::Release()
{
}
