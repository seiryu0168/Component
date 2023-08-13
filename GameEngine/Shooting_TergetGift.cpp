#include "Shooting_TergetGift.h"
#include"Engine/Systems/ModelSystem.h"
#include"Engine/Systems/ColliderSystem.h"
Shooting_TergetGift::Shooting_TergetGift(Object* parent)
	:GameObject(parent,"Shooting_TargetGift")
{
	SetTag("TargetGift");
}

Shooting_TergetGift::~Shooting_TergetGift()
{
}

void Shooting_TergetGift::Initialize()
{

	//XMVECTOR pos = transform_->position_;
	//pos += XMVectorSet(0, transform_->scale_.y, 0, 0);
	//transform_->position_ = pos;
	//Test_Model_ECSver model(this);
	//model.Load("Assets/Model/AAA.fbx");
	//AddComponent<Test_Model_ECSver>(model);
	
	//HitBox colShape({ 5.0f, 5.0f, 5.0f });

	//Collider collision({ 0,0,0 }, colShape);
	//collision.SetAttachObject(this);
	//AddComponent<Collider>(collision);

}

void Shooting_TergetGift::OnCollision(Object* target)
{
	KillMe();
}

void Shooting_TergetGift::Release()
{
}
