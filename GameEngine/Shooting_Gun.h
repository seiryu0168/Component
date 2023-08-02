#pragma once
#include"Engine/GameObject/GameObject.h"
class Shooting_Gun : public GameObject
{
	XMVECTOR frontVec_;
public:
	Shooting_Gun(Object* parent);
	~Shooting_Gun();
	void Initialize() override;
	void Update() override;
	void Shot(const XMVECTOR& dir);
	void Release() override;
};

