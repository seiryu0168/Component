#include "TestObjectChild.h"
#include"PhysicsSystem.h"
#include"Engine/ResourceManager/Model.h"
TestObjectChild::TestObjectChild(Object* parent)
	:GameObject(parent,"TestObjectChild"),
	hModel_(-1),
	time_(0)
{
	Entity entity = Coordinator::CreateEntity();
	entityList_.push_back(entity);
	Gravity g;
	g.force_ = XMVectorSet(0, 0.24f, 0, 0);
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
	for (Entity entity : entityList_)
		transform_->position_ = StoreFloat3(Coordinator::GetComponent<TransformData>(entity).position_);
	//transform_->position_.x = sinf(XMConvertToRadians(time_)*2);
	//transform_->position_.z = cosf(XMConvertToRadians(time_)*2);
}

void TestObjectChild::Draw()
{
	ModelManager::SetTransform(hModel_, *transform_);
	ModelManager::Draw(hModel_);
}

void TestObjectChild::Release()
{
}
