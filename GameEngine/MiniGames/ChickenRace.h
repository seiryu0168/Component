#pragma once
#include "Framework.h"
#include "../Engine/Components/Text.h"

class ChickenRace : public Framework
{
private:
	int TargetTime;	//–Ú•W‚Æ‚È‚éŽžŠÔ
	std::vector<float> PlayersTime_;
	Text* text_;

	void Finish() override;
public:
	ChickenRace(Object* parent);
	~ChickenRace() {}

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	void SendTime(Object* target, float time);
};

