#include "TestObjectChild.h"
#include"PhysicsSystem.h"
#include"Engine/ResourceManager/Model.h"
#include"Engine/Collider/BoxCollider.h"
#include"Test_Model_ECSver.h"
#include"Draw3DComponent.h"
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
	//Text text;
	//text.SetText("ASDFGHJKL");
	//AddComponent<Text>(text);
	//Text text2;
	//text2.SetColor({ 0,1,1,1 });
	//text2.SetFontWeight(DWRITE_FONT_WEIGHT_BOLD, 0,50);
	//AddComponent<Text>(text2);
}

void TestObjectChild::Update()
{
	time_++;
	transform_->position_ = XMVectorSet(0,sinf(XMConvertToRadians(time_)*2),0,0)*4.0f;
	
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
