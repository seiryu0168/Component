#include "ChickenRace.h"
#include "Player_ChickenRace.h"
#include <format>
#include <random>
#include "../Engine/Components/Particle.h"

ChickenRace::ChickenRace(Object* parent)
	: Framework(parent, "ChickenRace") , TargetTime(0), PlayersTime_(), text_()
{
	Transform transform;
	AddComponent<Transform>(transform);
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
	std::string str = "–Ú•WŠÔ : " + std::to_string(TargetTime) + "•b";
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
			if (time > TargetTime)
			{
				Failed((GameObject*)itr.get());
			}
			else
			{
				Text text;
				text.SetText(std::format("Player{:d} : {:g}•b", element + 1 ,PlayersTime_[element]));
				switch (element)
				{
				case 0:
					text.SetRatio(0.15f, 0.5f);
					break;
				case 1:
					text.SetRatio(0.65f, 0.5f);
					break;
				default:
					break;
				}
				AddComponent<Text>(text);
			}
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
	//text_->SetText(std::format("Player1 : {:g}•b  Player2 : {:g}•b", PlayersTime_[0], PlayersTime_[1]));
}

void ChickenRace::Failed(GameObject* obj)
{
	//‰Î‰Ô
	Particle particle(obj);
	EmitterData data;
	data.position = StoreFloat3(obj->GetTransform()->position_);
	data.delay = 0;
	data.number = 400;
	data.lifeTime = 200;
	data.dir = XMFLOAT3(0, 1, 0);
	data.dirErr = XMFLOAT3(150, 150, 90);
	data.gravity = 0.001f;
	data.speedErr = 5;
	data.size = XMFLOAT2(1, 1);
	data.sizeErr = XMFLOAT2(0.4f, 0.4f);
	data.scale = XMFLOAT2(1, 1);
	data.color = XMFLOAT4(1, 1, 0.1f, 1);
	data.deltaColor = XMFLOAT4(0, -1.0f / 20, 0, -1.0f / 20);
	data.textureFileName = "Assets\\Image\\Cloud.png";
	data.firstSpeed = 0.5f;
	data.blendMode = BLEND_MODE::BLEND_ADD;
	particle.SetData(data);
	AddComponent<Particle>(particle);
}