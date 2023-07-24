#pragma once
#include "Framework.h"
class ChickenRace : public Framework
{
private:
	int TargetTime;	//目標となる時間
	std::vector<float> PlayersTime_;
public:
	ChickenRace(Object* parent);
	~ChickenRace() {}

	void Initialize() override;
	void Update() override;
	void Release() override;

	void SendTime(Object* target, float time);
};

