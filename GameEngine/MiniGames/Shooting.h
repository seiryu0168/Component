#pragma once
#include"Framework.h"
#include"../Engine/Time.h"
class Shooting : public Framework
{
	enum class PLAY_STATE
	{
		STATE_PLAY=0,
		STATE_FINISH,
	};
	std::unique_ptr<Time::Watch> time_;
	PLAY_STATE state_;
public:
	Shooting(Object* parent);
	~Shooting();

	void Initialize() override;
	void Update() override;
	void Play();
	void Finish();
	void Release() override;
};

