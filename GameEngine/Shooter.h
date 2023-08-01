#pragma once
#include"Engine/GameObject/GameObject.h"
class Shooter : public GameObject
{
public:
	Shooter(Object* parent);
	~Shooter();
	void Initialize() override;
	void Update() override;
	void Release() override;
};

