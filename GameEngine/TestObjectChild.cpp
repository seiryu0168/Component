#include "TestObjectChild.h"
#include"Engine/ResourceManager/Model.h"
TestObjectChild::TestObjectChild(Object* parent)
	:GameObject(parent,"TestObjectChild"),
	hModel_(-1),
	time_(0)
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
	time_++;
	transform_->position_.x = sinf(XMConvertToRadians(time_)*2);
	transform_->position_.z = cosf(XMConvertToRadians(time_)*2);
}

void TestObjectChild::Draw()
{
	ModelManager::SetTransform(hModel_, *transform_);
	ModelManager::Draw(hModel_);
}

void TestObjectChild::Release()
{
}
