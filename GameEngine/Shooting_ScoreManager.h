#pragma once
#include"ScoreManager.h"
class Shooting_ScoreManager : public ScoreManager<int>
{
public:
	Shooting_ScoreManager();
	Shooting_ScoreManager(const unsigned short& playerCount,int initScore);
	~Shooting_ScoreManager();
	void Init(const unsigned short& playerCount, int initScore);
	void ScoreUpdate(const unsigned short& playerNum, int score);
	int GetScore(const unsigned short& playerNum);

};

