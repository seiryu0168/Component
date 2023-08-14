#include "ChickenRace.h"
#include "Player_ChickenRace.h"
#include <format>
#include <random>
#include "../Engine/Components/Particle.h"
#include "../Engine/Components/Image.h"

ChickenRace::ChickenRace(Object* parent)
	: Framework(parent, "ChickenRace") , TargetTime(0), PlayersTime_(), text_()
{
}

void ChickenRace::Initialize()
{
	//‰Â•Ï‚É‚Å‚«‚é‚æ‚¤‚ÉŒã‚Å‚·‚é
	Players_ = 2;

	//—”‚ğ¶¬‚µA–Ú•WŠÔ‚ğŒˆ’è‚·‚é
	{
		std::random_device seed_gen;
		std::mt19937 engine(seed_gen());
		std::uniform_int_distribution tar(10, 25);
		TargetTime = tar(engine);
	}

	PlayerInitialize<Player_ChickenRace>();
	for (int i = 0; i < Players_; i++)
	{
		PlayersTime_.push_back(0);
	}

	Text text;
	text.SetText(std::format("{:d}•bƒMƒŠƒMƒŠ‚Å~‚ß‚ë!", TargetTime));
	text.SetRatio(0.3f,0);
	AddComponent<Text>(text);

	text_ = &GetComponent<Text>();

	Image i;
	i.Load("Assets\\Image\\Timer.png", "ChickenRace");
	AddComponent(i);
	i.Load("Assets\\Image\\Timer.png", "ChickenRace");
	AddComponent(i);
}

void ChickenRace::Update()
{
}

void ChickenRace::Draw()
{
}

void ChickenRace::Release()
{
}

void ChickenRace::SendTime(Object* target, float time)
{
	int element = 0;
	for (auto&& itr : childList_)
	{
		if (itr.get() == target)
		{
			PlayersTime_[element] = time;
		}
		++element;
	}
	

	if (std::find(PlayersTime_.begin(), PlayersTime_.end(), 0) == end(PlayersTime_))
	{
		Finish();
	}
}

void ChickenRace::Finish()
{
	if ((PlayersTime_[0] > TargetTime && PlayersTime_[1] > TargetTime) || PlayersTime_[0] == PlayersTime_[1])
	{
		text_->SetText("Draw");
	}
	else if (PlayersTime_[0] > TargetTime || PlayersTime_[1] > PlayersTime_[0])
	{
		text_->SetText("Player2 Win!");
	}
	else
	{
		text_->SetText("Player1 Win!");
	}
}