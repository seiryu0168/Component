#pragma once
#include"Engine/GameObject/GameObject.h"

class SnowCone_Cup;
class SnowConeMaker_Topping : public GameObject
{
private:
	int playerNum_;
	SnowCone_Cup* snowCone_;
public:
	SnowConeMaker_Topping(Object* parent);
	~SnowConeMaker_Topping();

	void Initialize() override;
	void Update() override;
	void SetPlayerNumber(int num) { playerNum_ = num; }
	void Release() override;

};

