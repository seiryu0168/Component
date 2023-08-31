#include "ChickenRace.h"
#include <format>
#include <random>
#include "Player_ChickenRace.h"
#include "../Engine/Components/Particle.h"
#include "../Engine/newSceneManager.h"
#include "../InterSceneData.h"

namespace
{
	static const int PROLOGUE = 4;
	static const float IMG_BTM = 4;
	static const float IMG_TOP = -4;
	static const int DEF_TEXT = 288;	//カウントダウン中の文字サイズの基準となる値
	static const int TO_TOP = 5;			//プレイ中に画面上に行くまでにかける時間

	static const int TAR_MAX = 15;
	static const int TAR_MIN = 10;
}

ChickenRace::ChickenRace(Object* parent)
	: Framework(parent, "ChickenRace") , TargetTime(0), PlayersTime_(), text_(), state_(STATE::prologue), watch_(nullptr), BG_(nullptr)
{
}

ChickenRace::~ChickenRace()
{
}

void ChickenRace::Initialize()
{
	//可変にできるように後でする
	Players_ = 2;

	//乱数を生成し、目標時間を決定する
	{
		std::random_device seed_gen;
		std::mt19937 engine(seed_gen());
		std::uniform_int_distribution tar(TAR_MIN, TAR_MAX);
		TargetTime = tar(engine);
	}

	
	for (int i = 0; i < Players_; i++)
	{
		PlayersTime_.push_back(0);
	}

	Text text;
	text.SetAlignmentType(ALIGNMENT_TYPE::CENTER_TOP);
	text.SetRect({ 0,0,1100,200 });
	text.SetRatio(0.2f,0.5f);
	text.SetText(std::format("目標時間 : {:d}秒", TargetTime));
	text.SetFont("りいてがき筆");
	AddComponent<Text>(text);
	text_ = &GetComponent<Text>();

	{
		Image i;
		i.Load("Assets\\Image\\BG_ChickenRace.png");
		i.SetSize({ 3,3,1 });
		i.SetPosition({ 0,IMG_TOP,0 });
		int I = AddComponent<Image>(i);
		BG_ = &GetComponent<Image>(I);
	}

	watch_ = std::make_unique<Time::Watch>();
	watch_->UnLock();
}

void ChickenRace::Update()
{
	switch (state_)
	{
	case STATE::prologue:
		Prologue();
		break;
	case STATE::countdown:
		Countdown();
		break;
	case STATE::play:
		Play();
		break;
	case STATE::finish:
		Finish();
		break;
	default:
		break;
	}
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

void ChickenRace::Prologue()
{
	float time = watch_->GetSeconds<float>();
	BG_->SetPosition({ 0, std::lerp(IMG_TOP, IMG_BTM, time / PROLOGUE) , 0 });
	if (time > PROLOGUE)
	{
		watch_->SetSecond(3);
		watch_->SetCountdown(true);
		state_ = STATE::countdown;
	}
}

void ChickenRace::Countdown()
{
	float timef = watch_->GetSeconds<float>();
	int time = timef;

	//text_->SetAlignmentType(ALIGNMENT_TYPE::CENTER_CENTER);
	text_->SetText(std::to_string(time + 1));
	text_->SetTextSize(DEF_TEXT * (timef - time));
	//text_->SetFont("りいてがき筆");

	if (timef <= 0)
	{
		watch_->Reset();
		watch_->SetCountdown(false);
		state_ = STATE::play;
		PlayerInitialize<Player_ChickenRace>();
	}
}

void ChickenRace::Play()
{
	float timef = watch_->GetSeconds<float>();
	
	
	BG_->SetPosition({ 0, std::lerp(IMG_BTM, IMG_TOP, std::tanhf(timef / TO_TOP)) , 0 });
	
}

void ChickenRace::Finish()
{
	int winner;
	if ((PlayersTime_[0] > TargetTime && PlayersTime_[1] > TargetTime) || PlayersTime_[0] == PlayersTime_[1])
	{
		winner = -1;
		//text_->SetText("Draw");
	}
	else if (PlayersTime_[0] > TargetTime || PlayersTime_[1] > PlayersTime_[0])
	{
		winner = 0;
		//text_->SetText("Player2 Win!");
	}
	else
	{
		winner = 1;
		//text_->SetText("Player1 Win!");
	}
	InterSceneData::AddData("ResultData", winner);
	newSceneManager::ChangeScene(SCENE_ID::RESULT);
}