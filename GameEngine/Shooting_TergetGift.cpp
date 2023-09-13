#include "Shooting_TergetGift.h"
#include"Engine/ResourceManager/Audio.h"
namespace
{
	XMVECTOR KNOCKBACK_VEC = XMVectorSet(0, 0, 1, 0);
}
Shooting_TergetGift::Shooting_TergetGift(Object* parent)
	:GameObject(parent,"Shooting_TargetGift"),
	isHit_(false),
	fallSpeed_(0.0f)
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
	hAudio_CollisionSound_ = Audio::Load("Assets/Audio/Shooting_CollisionSound.wav");
	assert(hAudio_CollisionSound_ >= 0);
}

void Shooting_TergetGift::Update()
{
	if (isHit_)
	{
		Fall();
	}
}

void Shooting_TergetGift::Fall()
{
	transform_->position_ += KNOCKBACK_VEC + XMVectorSet(0, -fallSpeed_, 0, 0);
	fallSpeed_ += 0.1f;
	if (transform_->GetPositionY() <= 0)
		KillMe();
}

void Shooting_TergetGift::OnCollision(Object* target)
{
	//Audio::Play(hAudio_CollisionSound_);
	isHit_ = true;
}


void Shooting_TergetGift::Release()
{
}
