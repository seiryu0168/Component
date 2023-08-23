#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowCone_ToppingSumple : public GameObject
{
private:
public:
	SnowCone_ToppingSumple(Object* parent);
	~SnowCone_ToppingSumple();

	void Initialize() override;
	void ChangeSumple(int num);
	void Update() override;
	void Release() override;

};

