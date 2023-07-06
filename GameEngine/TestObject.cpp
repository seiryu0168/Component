#include "TestObject.h"
#include"Engine/ResourceManager/Model.h"
#include"PhysicsSystem.h"
#include"TestObjectChild.h"
#include"EntityManager.h"
#include"Engine/Collider/BoxCollider.h"
#include"AssimpLoader.h"
#include"Mesh.h"

TestObject::TestObject(Object* parent)
	:GameObject(parent,"TestObject"),
	hModel_(-1),
	time_(0),
	vPos_(XMVectorSet(0,0,2.1f,0))
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
	
	Collider coll({0,0,0});
	HitSphere sphere(1.0f);
	coll.SetCollider<HitSphere>(sphere);
	coll.SetAttachObject(this);
	AddComponent<Collider>(coll);
}

TestObject::~TestObject()
{
}

void TestObject::Initialize()
{
	AssimpLoader loader;
	Mesh mesh;
	mesh.vertices.push_back( VERTEX(XMVectorZero(), XMVectorZero(), XMVectorZero(), XMVectorZero()));
	mesh.indices.push_back(1);
	mesh.diffuseMap="";
	std::vector<Mesh> meshes;
	meshes.push_back(mesh);
	ImportSetting set("Assets\\Model\\AAA.fbx", meshes, false, false);
	loader.Load(set);
	hModel_ = ModelManager::Load("Assets\\Model\\AAA.fbx");
	assert(hModel_ >= 0);
}

void TestObject::Update()
{
	time_++;
	vPos_ = XMVector3Rotate(vPos_, XMQuaternionRotationAxis(XMVectorSet(0, 1.0f, 0, 0), XMConvertToRadians(1)));
	transform_->position_ = vPos_;
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
