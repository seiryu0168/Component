#include "TestObject.h"
#include"Engine/ResourceManager/Model.h"
#include"TransformComponent.h"
TestObject::TestObject(Object* parent)
	:GameObject(parent,"TestObject")
{
	AddComponent<TransformComponent>(this);
}

TestObject::~TestObject()
{
}

void TestObject::Initialize()
{
	hModel_ = ModelManager::Load("Assets\\Model\\AAA.fbx");
	assert(hModel_ >= 0);
}

void TestObject::Update()
{
	transform_.position_.x += 0.3f;
}

void TestObject::Draw()
{
	ModelManager::SetTransform(hModel_, transform_);
	ModelManager::Draw(hModel_);
}

void TestObject::Release()
{
}
