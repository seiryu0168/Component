#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowCone_ToppingSelect : public GameObject
{
private:
public:
	SnowCone_ToppingSelect(Object* parent);
	~SnowCone_ToppingSelect();

	void Initialize() override;
	void Update() override;
	void Release() override;
};

