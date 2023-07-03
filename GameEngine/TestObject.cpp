#include "TestObject.h"
#include"Engine/ResourceManager/Model.h"
#include"PhysicsSystem.h"
#include"TestObjectChild.h"
#include"EntityManager.h"
#include"Engine/Collider/BoxCollider.h"

TestObject::TestObject(Object* parent)
	:GameObject(parent,"TestObject"),
	hModel_(-1),
	time_(0)
{
	
	Gravity g;
	g.force_ = XMVectorSet(0, -0.4f, 0, 0);
	AddComponent<Gravity>(g);
	RigidBody rb;
	rb.acceleration_ = XMVectorZero();
	rb.vector_ = XMVectorZero();
	AddComponent<RigidBody>(rb);

	TransformData transform;
	transform.position_ = XMVectorZero();
	transform.rotation_ = XMVectorZero();
	transform.scale_ = { 0,0,0 };
	AddComponent<TransformData>(transform);
	
	BoxCollider boxCollider({ 0,0,0 }, { 1,1,1 });
	boxCollider.SetAttachObject(this);
	AddComponent<BoxCollider>(boxCollider);
}

TestObject::~TestObject()
{
}

void TestObject::Initialize()
{
	//GameObject* p = Instantiate<TestObjectChild>(this);
	hModel_ = ModelManager::Load("Assets\\Model\\AAA.fbx");
	assert(hModel_ >= 0);
}

void TestObject::Update()
{
	time_++;
	transform_->position_ = XMVectorSet(sin(time_ / 60.0f), 0, 0, 0) * 5.0f;
}

void TestObject::Draw()
{
	ModelManager::SetTransform(hModel_, *transform_);
	ModelManager::Draw(hModel_);
}

void TestObject::Release()
{
}

void TestObject::OnCollision(Object* target)
{
	int a = 0;
}
