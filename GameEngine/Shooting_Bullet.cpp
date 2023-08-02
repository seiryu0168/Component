#include "Shooting_Bullet.h"
#include"Engine/Systems/ModelSystem.h"
#include"Engine/Systems/LineParticleSystem.h"
#include"Engine/Time.h"
Shooting_Bullet::Shooting_Bullet(Object* parent)
	:GameObject(parent,"Shooting_Bullet"),dir_(XMVectorZero()), startTime_(0)
{
}

Shooting_Bullet::~Shooting_Bullet()
{
}

void Shooting_Bullet::Initialize()
{
	startTime_ = Time::GetSeconds<float>();
	//LineParticle lineParticle(this);
	//LineData data;
	//data.length = 30;
	//data.textureName = "Assets/Image/bluefire.png";
	//data.width = 0.5f;
	//data.endWidth = 0;
	//lineParticle.SetLineParameter(data);
	//AddComponent<LineParticle>(lineParticle);
	Test_Model_ECSver model(this);
	model.Load("Assets/Model/AAA.fbx");
	AddComponent<Test_Model_ECSver>(model);
}

void Shooting_Bullet::Update()
{
	transform_->position_ += dir_ * 0.3f;
	if (Time::GetSeconds<float>() - startTime_ >= 5.0f)
	{
		KillMe();
	}
}

void Shooting_Bullet::Release()
{
}
