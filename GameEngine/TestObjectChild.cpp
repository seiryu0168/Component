#include "TestObjectChild.h"
#include"Engine/Systems/PhysicsSystem.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/Systems/ImageSystem.h"
#include"Engine/Systems/ModelSystem.h"
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
	Text text;
	text.SetText("destroy");
	//text.SetPosition({ 0,0 });
	text.SetColor({ 0,0,1,1 });
	AddComponent<Text>(text);
	
	Image image;
	image.Load("Assets\\Image\\Line.png");
	AddComponent<Image>(image);

	Test_Model_ECSver model(this);
	model.Load("Assets\\Model\\BlueBall.fbx");
	model.SetShaderType(SHADER_TYPE::SHADER_OUTLINE);
	AddComponent<Test_Model_ECSver>(model);
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
