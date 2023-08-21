#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowCone_SyrupSelect : public GameObject
{
private:
public:
	SnowCone_SyrupSelect(Object* parent);
	~SnowCone_SyrupSelect();

	void Initialize() override;
	void Update() override;
	void Release() override;
};

