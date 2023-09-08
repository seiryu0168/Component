#pragma once
#include"Engine/GameObject/GameObject.h"
#include"Engine/Time.h"

class SnowCone_Cup;
class SnowConeMaker_Shave : public GameObject
{
private:
	std::shared_ptr<Time::Watch> timer_;
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

