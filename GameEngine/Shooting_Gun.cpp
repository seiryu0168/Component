#include "Shooting_Gun.h"
#include"Engine/Systems/ModelSystem.h"
#include"Shooting_Bullet.h"
Shooting_Gun::Shooting_Gun(Object* parent)
	:GameObject(parent,"Shooting_Gun")
{
}

Shooting_Gun::~Shooting_Gun()
{
}

void Shooting_Gun::Initialize()
{
	transform_->position_ = XMVectorSet(0, -5, 20, 0);
	Test_Model_ECSver model(this);
	model.Load("Assets/Model/Shooting_Gun.fbx");
	AddComponent<Test_Model_ECSver>(model);
}

void Shooting_Gun::Update()
{
}

void Shooting_Gun::Shot(const XMVECTOR& dir)
{
	Shooting_Bullet* bullet = Instantiate<Shooting_Bullet>(GetParent()->GetParent());
	bullet->SetPlayerNum(playerNum_);
	bullet->GetTransform()->position_ = GetComponent<Test_Model_ECSver>().GetBone("Bone");
	bullet->GetTransform()->rotate_ = ((GameObject*)GetParent())->GetTransform()->rotate_;
	bullet->SetDir(dir);
}

XMVECTOR Shooting_Gun::GetShotPos()
{
	return GetComponent<Test_Model_ECSver>().GetBone("Bone");
}

void Shooting_Gun::SetDraw(bool isDraw)
{
	GetComponent<Test_Model_ECSver>().SetDraw(isDraw);
}

void Shooting_Gun::Release()
{
}
