#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowConeMaker_Topping : public GameObject
{
private:
	int playerNum_;
public:
	SnowConeMaker_Topping(Object* parent);
	~SnowConeMaker_Topping();

	void Initialize() override;
	void Update() override;
	void SetPlayerNumber(int num) { playerNum_ = num; }
	void Release() override;

};

