#include "TestObjectChild.h"
#include"PhysicsSystem.h"
#include"Engine/ResourceManager/Model.h"
#include"Engine/Collider/BoxCollider.h"
#include"Test_Model_ECSver.h"
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
	//Collider coll({ 0,0,0 });
	//coll.SetAttachObject(this);
	//HitBox box({ 1,1,1 });
	//coll.SetCollider<HitBox>(box);
	//AddComponent<Collider>(coll);

	DrawComponent dObj;
	Test_Model_ECSver model(this);
	model.Load("Assets\\Model\\AAA.fbx");
	dObj.SetDrawObject<Test_Model_ECSver>(model);
	AddComponent<DrawComponent>(dObj);
	//hModel_ = ModelManager::Load("Assets\\Model\\AAA.fbx");
	//assert(hModel_ >= 0);
}

void TestObjectChild::Update()
{
	//time_++;
	//transform_->position_ = XMVectorSet(0,sinf(XMConvertToRadians(time_)*2),0,0)*4.0f;
	
}

void TestObjectChild::Draw()
{
	//ModelManager::SetTransform(hModel_, *transform_);
	//ModelManager::Draw(hModel_);
}

void TestObjectChild::Release()
{
}

void TestObjectChild::OnCollision(Object* target)
{
	int a = 0;
}
