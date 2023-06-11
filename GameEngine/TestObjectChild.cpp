#include "TestObjectChild.h"
#include"Engine/ResourceManager/Model.h"
TestObjectChild::TestObjectChild(Object* parent)
	:GameObject(parent,"TestObjectChild")
{
}

TestObjectChild::~TestObjectChild()
{
}

void TestObjectChild::Initialize()
{
	hModel_ = ModelManager::Load("Assets\\Model\\AAA.fbx");
	assert(hModel_ >= 0);
}

void TestObjectChild::Update()
{
	transform_.position_.x -= 0.3f;
}

void TestObjectChild::Draw()
{
	ModelManager::SetTransform(hModel_, transform_);
	ModelManager::Draw(hModel_);
}

void TestObjectChild::Release()
{
}
