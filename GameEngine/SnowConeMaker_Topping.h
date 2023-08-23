#pragma once
#include"Engine/GameObject/GameObject.h"

class SnowCone_Cup;
class SnowCone_ToppingSumple;
class SnowConeMaker_Topping : public GameObject
{
private:
	int playerNum_;
	SnowCone_Cup* snowCone_;
	SnowCone_ToppingSumple* sumple_;
public:
	SnowConeMaker_Topping(Object* parent);
	~SnowConeMaker_Topping();

	void Initialize() override;
	void Update() override;
	void SetTopping();
	void SetSumple();
	void SetPlayerNumber(int num) { playerNum_ = num; }
	void ResetSelectUI();
	void Release() override;

};

