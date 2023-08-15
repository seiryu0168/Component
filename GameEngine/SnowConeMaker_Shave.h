#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowConeMaker_Shave : public GameObject
{
private:
	int playerNum_;
public:
	SnowConeMaker_Shave(Object* parent);
	~SnowConeMaker_Shave();
	void Initialize() override;
	void Update() override;
	void SetPlayerNumber(int num) { playerNum_ = num; }
	void Release() override;

};

