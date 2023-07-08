#include "TestObject.h"
#include"Engine/ResourceManager/Model.h"
#include"PhysicsSystem.h"
#include"TestObjectChild.h"
#include"EntityManager.h"
#include"Engine/Collider/BoxCollider.h"
#include"Test_Model_ECSver.h"
#include"AssimpLoader.h"
#include"DrawComponent.h"
#include"Mesh.h"

TestObject::TestObject(Object* parent)
	:GameObject(parent,"TestObject"),
	hModel_(-1),
	time_(0),
	vPos_(XMVectorSet(0,0,2.1f,0))
{
	//DrawComponent<Test_Model_ECSver>()
	
}

TestObject::~TestObject()
{
}

void TestObject::Initialize()
{
	//AssimpLoader loader;
	//std::vector<Mesh> mesh;
	//Mesh m;
	//mesh.push_back(m);
	//ImportSetting set("",mesh, true,true);
	//loader.Load(set);
	Collider coll({0,0,0});
	HitSphere sphere(1.0f);
	coll.SetCollider<HitSphere>(sphere);
	coll.SetAttachObject(this);
	AddComponent<Collider>(coll);

	Test_Model_ECSver model(this);
	model.Load("Assets\\Model\\AAA.fbx");
	AddComponent<Test_Model_ECSver>(model);
}

void TestObject::Update()
{
	time_++;
	vPos_ = XMVector3Rotate(vPos_, XMQuaternionRotationAxis(XMVectorSet(0, 1.0f, 0, 0), XMConvertToRadians(1)));
	transform_->position_ = vPos_;
}

void TestObject::Draw()
{
	//ModelManager::SetTransform(hModel_, *transform_);
	//ModelManager::Draw(hModel_);
}

void TestObject::Release()
{
}

void TestObject::OnCollision(Object* target)
{
	int a = 0;
}
