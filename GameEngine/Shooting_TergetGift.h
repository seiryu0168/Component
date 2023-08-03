#pragma once
#include"Engine/GameObject/GameObject.h"
class Shooting_TergetGift : public GameObject
{
public:
	Shooting_TergetGift(Object* parent);
	~Shooting_TergetGift();

	void Initialize() override;
	void OnCollision(Object* target) override;
	void Release();
};

