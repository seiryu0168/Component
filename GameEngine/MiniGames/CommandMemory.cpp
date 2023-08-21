#include "CommandMemory.h"
#include "P_CommandMemory.h"
#include "../Engine/Components/Image.h"
#include "../InterSceneData.h"
#include <format>
#include <Xinput.h>
#include "../Engine/newSceneManager.h"

namespace
{
	static const std::string dir = "Assets\\Image\\Buttons\\";
	static const std::vector<std::string> imageNames_ =
	{
		"BTN_A.png",
		"BTN_B.png",
		"BTN_X.png",
		"BTN_Y.png",
		"BTN_LB.png",
		"BTN_RB.png",
		"STK_L.png",
		"STK_R.png",
		"DIR_D.png",
		"DIR_U.png",
		"DIR_L.png",
		"DIR_R.png"
	};
	static const std::vector<WORD> buttonNames_ =
	{
		XINPUT_GAMEPAD_A,
		XINPUT_GAMEPAD_B,
		XINPUT_GAMEPAD_X,
		XINPUT_GAMEPAD_Y,
		XINPUT_GAMEPAD_LEFT_SHOULDER,
		XINPUT_GAMEPAD_RIGHT_SHOULDER,
		XINPUT_GAMEPAD_LEFT_THUMB,
		XINPUT_GAMEPAD_RIGHT_THUMB,
		XINPUT_GAMEPAD_DPAD_DOWN,
		XINPUT_GAMEPAD_DPAD_UP,
		XINPUT_GAMEPAD_DPAD_LEFT,
		XINPUT_GAMEPAD_DPAD_RIGHT,
	};

	static const float ImageSize = 1.35f;
	static const float MaxSize = 2.35f;
	static const float MaxMove = 30;

	static const std::string Choices = "コマンドを追加してください";
}

CommandMemory::CommandMemory(Object* parent)
	: Framework(parent, "CommandMemory"), cmList_(), NowPlayer_(0), itr_(), text_(nullptr), Images_(),
	now_(NULL), prev_(XINPUT_GAMEPAD_A), RemainingText_(nullptr), choiced_(false), moveCount_(0)
{
}

CommandMemory::~CommandMemory()
{
}

void CommandMemory::Initialize()
{
	Players_ = 2;
	PlayerInitialize<P_CommandMemory>();

	itr_ = cmList_.begin();

	Text text;
	text.SetText(std::format("プレイヤー{:d}の番", NowPlayer_ + 1));
	text.SetRatio(0.25f,0);
	AddComponent<Text>(text);

	text_ = &GetComponent<Text>(0);
	ImageLoad();

	Text t;
	t.SetText(Choices);
	t.SetRatio(0.25f, 0.25f);
	AddComponent<Text>(t);
	RemainingText_ = &GetComponent<Text>(1);
}

void CommandMemory::Update()
{
	if (choiced_)
	{
		float size = (float)std::lerp(ImageSize, MaxSize, ++moveCount_ / MaxMove);
		Images_[now_]->SetSize({ size, size, 1 });
		float alpha = (float)std::lerp(1, 0, moveCount_ / MaxMove);
		Images_[now_]->SetAlpha(alpha);

		if (moveCount_ >= MaxMove)
		{
			choiced_ = false;
			moveCount_ = 0;
		}
	}
}

void CommandMemory::Draw()
{
}

void CommandMemory::Release()
{
}

void CommandMemory::sendCommand(int Button, int Playerid)
{
	//操作権を持つプレイヤーか確かめる
	if (NowPlayer_ == Playerid)
	{
		if (itr_ == cmList_.end())
		{
			choiced_ = true;
			moveCount_ = 0;
			prev_ = now_;
			now_ = Button;

			if (!cmList_.empty())
			{
				Images_[prev_]->SetAlpha(0);
				Images_[prev_]->SetSize({ ImageSize,ImageSize,1 });
			}

			//要素を追加し、イテレータを初期位置に戻す
			cmList_.push_back(Button);
			itr_ = cmList_.begin();

			//プレイヤーの操作権を変更
			if (++NowPlayer_ >= Players_)
				NowPlayer_ = (Players_ - 2);

			text_->SetText(std::format("プレイヤー{:d}の番", NowPlayer_ + 1));
			RemainingText_->SetText(std::format("あと{:d}コマンド", cmList_.size()));
		}
		else
		{
			if (*itr_ == Button)
			{
				choiced_ = true;
				moveCount_ = 0;
				prev_ = now_;
				now_ = Button;
				Images_[prev_]->SetAlpha(0);
				Images_[prev_]->SetSize({ ImageSize,ImageSize,1 });
				++itr_;
				RemainingText_->SetText(std::format("あと{:d}コマンド", std::distance(itr_, cmList_.end())));
			}
			else
			{
				if (++NowPlayer_ >= Players_)
					NowPlayer_ = (Players_ - 2);
				InterSceneData::AddData("ResultData", NowPlayer_);
				newSceneManager::ChangeScene(SCENE_ID::RESULT);
			}
		}
	}
}

void CommandMemory::ImageLoad()
{
	Image image;
	for (int i = 0; i != imageNames_.size(); i++)
	{
		image.Load(dir + imageNames_[i]);
		image.SetAlpha(0);
		image.SetSize({ ImageSize,ImageSize,1 });
		AddComponent(image);
		Images_.insert({ buttonNames_[i], &GetComponent<Image>(i)});
	}
}
