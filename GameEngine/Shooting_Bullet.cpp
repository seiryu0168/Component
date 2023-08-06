#include "Shooting_Bullet.h"
#include"Engine/Systems/ModelSystem.h"
#include"Engine/Systems/LineParticleSystem.h"
#include"Engine/Systems/ColliderSystem.h"
#include"Engine/Time.h"
#include"MiniGames/Shooting.h"
#include"Shooting_TergetGift.h"
Shooting_Bullet::Shooting_Bullet(Object* parent)
	:GameObject(parent,"Shooting_Bullet"),dir_(XMVectorZero())
{
}

Shooting_Bullet::~Shooting_Bullet()
{
}

void Shooting_Bullet::Initialize()
{
	time_ = std::make_shared<Time::Watch>();
	time_->UnLock();
	//startTime_ = time_->GetSeconds<float>();
	//LineParticle lineParticle(this);
	//LineData data;
	//data.length = 30;
	//data.textureName = "Assets/Image/bluefire.png";
	//data.width = 0.5f;
	//data.endWidth = 0;
	//lineParticle.SetLineParameter(data);
	//AddComponent<LineParticle>(lineParticle);
	Test_Model_ECSver model(this);
	model.Load("Assets/Model/Shooting_Bullet.fbx");
	AddComponent<Test_Model_ECSver>(model);

	HitSphere colShape = { 1.0f };
	Collider collision({ 0,0,0 }, colShape);
	collision.SetAttachObject(this);
	AddComponent<Collider>(collision);

}

void Shooting_Bullet::Update()
{
	transform_->position_ += dir_ * 0.1f;

	if ( time_->GetSeconds<float>() >= 5.0f)
	{
		KillMe();
	}
}

void Shooting_Bullet::Release()
{
}

void Shooting_Bullet::OnCollision(Object* target)
{
	if (target->GetTag() == "TargetGift")
	{
		KillMe();
		((Shooting*)GetParent())->ScoreUpdate(playerNum_, ((Shooting_TergetGift*)target)->GetScore());
	}
}
