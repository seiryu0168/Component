#include "SnowCone_Cup.h"
#include"Engine/Systems/ModelSystem.h"
#include"SnowCone_Ice.h"

SnowCone_Cup::SnowCone_Cup(Object* parent)
	:GameObject(parent, "SnowCone_Cup")
{
}

SnowCone_Cup::~SnowCone_Cup()
{
}

void SnowCone_Cup::Initialize()
{
	Test_Model_ECSver model(this);
	model.Load("Assets/Model/SnowCone_Cup.fbx");
	AddComponent<Test_Model_ECSver>(model);
	transform_->position_ = XMVectorSet(-40, 0, -30, 0);

	Instantiate<SnowCone_Ice>(this);
}

void SnowCone_Cup::SetColor(const XMFLOAT4& color)
{
	((SnowCone_Ice*)FindChild("SnowCone_Ice"))->SetColor(color);
}

void SnowCone_Cup::SetTopping(int topNum)
{
	((SnowCone_Ice*)FindChild("SnowCone_Ice"))->SetTopping(0);
}

void SnowCone_Cup::RemoveIce()
{
	((SnowCone_Ice*)FindChild("SnowCone_Ice"))->RemoveTopping();
}

void SnowCone_Cup::Release()
{
}