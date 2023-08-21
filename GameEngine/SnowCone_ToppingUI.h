#pragma once
#include"Engine/GameObject/GameObject.h"

class SnowCone_SyrupSelect;
class SnowCone_ToppingSelect;
class SnowCone_ToppingUI : public GameObject
{
private:
	SnowCone_SyrupSelect* syrupSelect_;
	SnowCone_ToppingSelect* toppingSelect_;
public:
	SnowCone_ToppingUI(Object* parent);
	~SnowCone_ToppingUI();

	void Initialize() override;
	void Update() override;
	void Release() override;
};

