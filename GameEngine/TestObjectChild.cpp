#include "TestObjectChild.h"
#include"PhysicsSystem.h"
#include"Engine/ResourceManager/Model.h"
#include"Test_Collider_ECSver.h"
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
	Test_Collider_ECSver	boxCollider({ 0,0,0 }, { 1,1,1 });
	AddComponent<Test_Collider_ECSver>(boxCollider);
	hModel_ = ModelManager::Load("Assets\\Model\\AAA.fbx");
	assert(hModel_ >= 0);
}

void TestObjectChild::Update()
{
	time_++;
	transform_->position_ = XMVectorSet(0,sinf(XMConvertToRadians(time_)*2),0,0)*4.0f;
	
}

void TestObjectChild::Draw()
{
	ModelManager::SetTransform(hModel_, *transform_);
	ModelManager::Draw(hModel_);
}

void TestObjectChild::Release()
{
}

void TestObjectChild::OnCollision(Object* target)
{
	int a = 0;
}
