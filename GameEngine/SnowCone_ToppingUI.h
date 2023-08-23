#pragma once
#include"Engine/GameObject/GameObject.h"

class SnowCone_SyrupSelect;
class SnowCone_ToppingSelect;

enum class SELECT_MODE
{
	MODE_SYRUP = 0,
	MODE_TOPPING,
	MODE_COMPLETE,
};
class SnowCone_ToppingUI : public GameObject
{
private:
	SnowCone_SyrupSelect* syrupSelect_;
	SnowCone_ToppingSelect* toppingSelect_;
	SELECT_MODE mode_;
public:
	SnowCone_ToppingUI(Object* parent);
	~SnowCone_ToppingUI();

	void Initialize() override;
	void Update() override;
	int GetSyrupData();
	int GetToppingData();
	void ModeChange(SELECT_MODE mode);
	void Release() override;
};

