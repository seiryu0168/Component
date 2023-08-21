#pragma once
#include"Engine/GameObject/GameObject.h"
class Result_Multi : public GameObject
{
	int Winner_;
public:
	Result_Multi(Object* parent) : GameObject(parent, "Result_Multi") {}
	~Result_Multi() {}

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

