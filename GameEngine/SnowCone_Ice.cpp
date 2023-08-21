#include "SnowCone_Ice.h"
#include"Engine/Systems/ModelSystem.h"

SnowCone_Ice::SnowCone_Ice(Object* parent)
	:GameObject(parent,"SnowCone_Ice")
{
}

SnowCone_Ice::~SnowCone_Ice()
{
}

void SnowCone_Ice::Initialize()
{
	Test_Model_ECSver model(this);
	model.Load("Assets/Model/SnowCone_Ice.fbx");
	AddComponent<Test_Model_ECSver>(model);
	transform_->position_ = XMVectorSet(0, 2, 0, 0);
}

void SnowCone_Ice::SetColor(const XMFLOAT4& color)
{
}

void SnowCone_Ice::Release()
{
}
