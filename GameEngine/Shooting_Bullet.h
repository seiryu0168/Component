#pragma once
#include"Engine/GameObject/GameObject.h"
#include"Engine/Time.h"
class Shooting_Bullet: public GameObject
{
	XMVECTOR dir_;
	float startTime_;
	std::shared_ptr<Time::Watch> time_;
public:
	Shooting_Bullet(Object* parent);
	~Shooting_Bullet();
	void Initialize() override;
	void Update() override;
	void SetDir(XMVECTOR dir) { dir_ = dir; }
	void Release() override;

	void OnCollision(Object* target) override;
};

