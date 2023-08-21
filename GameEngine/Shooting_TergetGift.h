#pragma once
#include"Engine/GameObject/GameObject.h"
class Shooting_TergetGift : public GameObject
{
	int score_;
public:
	Shooting_TergetGift(Object* parent);
	~Shooting_TergetGift();

	void Initialize() override;
	void OnCollision(Object* target) override;
	void SetScore(const int& score) { score_ = score; }
	int& GetScore() { return score_; }
	void Release();
};

