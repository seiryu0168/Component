#include "TestObject.h"
#include"Engine/ResourceManager/Model.h"
#include"TransformComponent.h"
TestObject::TestObject(GameObject* poarent)
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
}

void TestObject::Draw()
{
	ModelManager::SetTransform(hModel_, *GetComponent<TransformComponent>());
	ModelManager::Draw(hModel_);
}

void TestObject::Release()
{
}
