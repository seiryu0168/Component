#include "TestObject.h"
#include"Engine/ResourceManager/Model.h"
#include"PhysicsSystem.h"
#include"TestObjectChild.h"
#include"EntityManager.h"

TestObject::TestObject(Object* parent)
	:GameObject(parent,"TestObject"),
	hModel_(-1),
	time_(0)
{
}

TestObject::~TestObject()
{
}

void TestObject::Initialize()
{
	GameObject* p = Instantiate<TestObjectChild>(this);
	//p->SetPosition({ 0,2,0 });
	hModel_ = ModelManager::Load("Assets\\Model\\AAA.fbx");
	assert(hModel_ >= 0);
}

void TestObject::Update()
{
	for (Entity entity : entityList_)
	{
		transform_->position_ = StoreFloat3(Coordinator::GetComponent<TransformData>(entity).position_);

	}
	time_++;
	transform_->position_.x = sinf(XMConvertToRadians(time_));
	transform_->position_.z = cosf(XMConvertToRadians(time_));
}

void TestObject::Draw()
{
	ModelManager::SetTransform(hModel_, *transform_);
	ModelManager::Draw(hModel_);
}

void TestObject::Release()
{
}
