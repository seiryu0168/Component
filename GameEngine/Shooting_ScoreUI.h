#pragma once
#include<string>
#include"Engine/ECS/ECS.h"
class Shooting_ScoreUI
{
	std::vector<Entity> uiEntities_;
public:
	Shooting_ScoreUI();
	~Shooting_ScoreUI();
	void Init(const unsigned short& playerCount, std::string initText);
	void TextUpdate(const unsigned short& playerNum, std::string text);
};

