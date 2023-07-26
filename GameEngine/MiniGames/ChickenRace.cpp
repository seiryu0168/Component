#include "ChickenRace.h"
#include "Player_ChickenRace.h"
#include <format>
#include <random>

ChickenRace::ChickenRace(Object* parent)
	: Framework(parent, "ChickenRace") , TargetTime(0), PlayersTime_(), text_()
{
	Transform transform;
	AddComponent<Transform>(transform);
}

void ChickenRace::Initialize()
{
	//可変にできるように後でする
	Players_ = 2;

	//乱数を生成し、目標時間を決定する
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
	std::string str = "目標時間 : " + std::to_string(TargetTime) + "秒";
	text.SetText(str);
	text.SetPosition({ -500,1000 });
	AddComponent<Text>(text);

	text_ = &GetComponent<Text>();
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
	text_->SetRatio(0.3f, 0.3f);
	text_->SetText(std::format("Player1 : {:g}秒  Player2 : {:g}秒", PlayersTime_[0], PlayersTime_[1]));
}
