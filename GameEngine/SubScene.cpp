#include "SubScene.h"
#include"TestObject.h"
SubScene::SubScene(Object* parent)
{
}

SubScene::~SubScene()
{
}

void SubScene::Initialize()
{
	Instantiate<TestObject>(this);
}

void SubScene::Update()
{
}

void SubScene::Release()
{
}
