#include "TestObject.h"
#include"Engine/ResourceManager/Model.h"
#include"TestObjectChild.h"
//#include"TransformComponent.h"

TestObject::TestObject(Object* parent)
	:GameObject(parent,"TestObject")
{
}

TestObject::~TestObject()
{
}

void TestObject::Initialize()
{
	GameObject* p = Instantiate<TestObjectChild>(this);
	p->SetPosition({ 0,2,0 });
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
