#pragma once
#include"Framework.h"
#include"../Engine/Time.h"
#include"../SnowCone_ScoreManager.h"

class SnowCone_Cup;
class SnowConeMaking : public Framework
{
private:
	enum class PLAY_STATE
	{
		STATE_STAY = 0,
		STATE_PLAY,
		STATE_FINISH,
	};
	std::queue<SnowCone_Cup*> cupList_;
	std::unique_ptr<Time::Watch> time_;
	std::vector<int> shavedCupList_;
	std::vector<int> shavedCupSize_;
	PLAY_STATE state_;
	SnowCone_ScoreManager scoreManager_;
	int progressImageNum_;
	int blackImageNum_;
	int timeText_;
	

public:
	SnowConeMaking(Object* parent);
	~SnowConeMaking();
	void Initialize() override;
	void Update() override;
	void StaticUpdate() override;
	void Stay();
	void Play();
	void AddCup(SnowCone_Cup* cup);
	void ScoreUpdate(int score);
	void Evaluation(float size,int syrup,int topping);
	SnowCone_Cup* GetCup();
	void Release()override;
};

