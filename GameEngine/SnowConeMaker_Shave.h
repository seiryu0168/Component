#pragma once
#include"Engine/GameObject/GameObject.h"

class SnowCone_Cup;
class SnowConeMaker_Shave : public GameObject
{
private:
	int playerNum_;
	float snowConeSize_;
	SnowCone_Cup* snowCone_;
public:
	SnowConeMaker_Shave(Object* parent);
	~SnowConeMaker_Shave();
	void Initialize() override;
	void Update() override;
	void Shave();
	void SetPlayerNumber(int num) { playerNum_ = num; }
	void Release() override;

};

