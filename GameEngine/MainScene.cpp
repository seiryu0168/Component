#include "MainScene.h"
#include"TestObject.h"
#include"TestObjectChild.h"
#include"DrawComponent.h"
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
