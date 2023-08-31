#pragma once
#include"SnowCone_ToppingMenu.h"

class SnowCone_ToppingSelect : public SnowCone_ToppingMenu
{
private:
	int selectFrame_;
	int toppingText_;
public:
	SnowCone_ToppingSelect(Object* parent);
	~SnowCone_ToppingSelect();

	void Initialize() override;
	void Update() override;
	void Input();
	void Move();
	int GetToppingNum() { return selectNum_; }
	void UIReset();
	void Release() override;
};

