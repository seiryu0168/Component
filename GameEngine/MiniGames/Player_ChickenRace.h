#pragma once
#include "Player.h"
#include "../Engine/Components/Text.h"
#include "../Engine/Time.h"

class Player_ChickenRace : public Player
{
private:
	Time::Watch watch_;

	Text* text_;
public:
	Player_ChickenRace(Object* parent);
	~Player_ChickenRace() {}

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

