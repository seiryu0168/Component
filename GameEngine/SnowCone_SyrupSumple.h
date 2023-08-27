#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowCone_SyrupSumple : public GameObject
{
public:
	SnowCone_SyrupSumple(Object* parent);
	~SnowCone_SyrupSumple();

	void Initialize() override;
	void ChangeSumple(int num);
	void Release() override;
};

