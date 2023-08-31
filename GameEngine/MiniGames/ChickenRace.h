#pragma once
#include "Framework.h"
#include "../Engine/Components/Image.h"

class GameObject;

class ChickenRace : public Framework
{
private:
	enum class STATE
	{
		prologue = 0,
		countdown,
		play,
		finish
	} state_;
	int TargetTime;	//�ڕW�ƂȂ鎞��
	std::vector<float> PlayersTime_;
	Text* text_;

	std::unique_ptr<Time::Watch> watch_;

	Image* BG_;

	void Prologue();
	void Countdown();
	void Play();
	void Finish();
public:
	ChickenRace(Object* parent);
	~ChickenRace();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	void SendTime(Object* target, float time);
	int GetTarget() const { return TargetTime; }
};

