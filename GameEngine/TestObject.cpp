#include "TestObject.h"
#include"Engine/ResourceManager/Model.h"
#include"PhysicsSystem.h"
#include"TestObjectChild.h"
#include"EntityManager.h"
#include"Engine/Collider/BoxCollider.h"
#include"Test_Model_ECSver.h"
#include"Engine/ResourceManager/Text.h"
#include"Draw2DComponent.h"
#include"AssimpLoader.h"
#include"DrawComponent.h"
#include"newSceneManager.h"
#include"Engine/DirectX_11/Input.h"
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


	Draw2DComponent textObj;
	Text txt;
	txt.Load("asdfg", "Sitka Text", { 0,0,100,100 }, LEFT_TOP);
	txt.SetPosition({ 0,0 });
	textObj.SetDrawObject<Text>(txt);
	AddComponent<Draw2DComponent>(textObj);

	DrawComponent dObj;
	Test_Model_ECSver model(this);
	model.Load("Assets\\Model\\AAA.fbx");
	dObj.SetDrawObject<Test_Model_ECSver>(model);
	AddComponent<DrawComponent>(dObj);
	 
	//DrawComponent particle;
	//Particle pa(this);
	//EmitterData data;
	//data.acceleration = 0.03f;
	//data.delay = 30;
	//data.position = { 0,0,0 };
	//data.positionErr = { 10,10,10 };
	//data.gravity = -0.001f;
	//data.firstSpeed = 0;
	//data.lifTime = 100;
	//data.number = 10;
	//data.scale = { 1.0f,1.0f };
	//data.size = { 1,1 };
	//data.sizeErr = { 0,0 };
	//data.textureFileName = "Assets\\Image\\Effect01.png";
	//pa.SetData(data);
	//particle.SetDrawObject<Particle>(pa);
	//AddComponent<DrawComponent>(particle);

}

void TestObject::Update()
{
	time_++;
	vPos_ = XMVector3Rotate(vPos_, XMQuaternionRotationAxis(XMVectorSet(0, 1.0f, 0, 0), XMConvertToRadians(1)));
	transform_->position_ = vPos_;
	if (Input::IsKeyDown(DIK_A))
	{
		newSceneManager::ChangeScene(SCENE_ID::SCENE_ID_SUB);
	}
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
