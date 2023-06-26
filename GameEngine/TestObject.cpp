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

	Entity entity = Coordinator::CreateEntity();
	entityList_.push_back(entity);
	Gravity g;
	g.force_ = XMVectorSet(0, -0.4f, 0, 0);
	Coordinator::AddComponent(entity, g);
	RigidBody rb;
	rb.acceleration_ = XMVectorZero();
	rb.vector_ = XMVectorZero();
	Coordinator::AddComponent(entity, rb);

	TransformData transform;
	transform.position_ = XMVectorZero();
	transform.rotation_ = XMVectorZero();
	transform.scale_ = { 0,0,0 };
	Coordinator::AddComponent(entity, transform);
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
