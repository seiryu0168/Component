#include "CommandMemory.h"
#include "P_CommandMemory.h"
#include <format>

CommandMemory::CommandMemory(Object* parent)
	: Framework(parent, "CommandMemory"), cmList_(), NowPlayer_(0), itr_(), text_(nullptr)
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
	text.SetText(std::format("プレイヤー{:d}のターン", NowPlayer_ + 1));
	text.SetPosition({ -500,1000 });
	AddComponent<Text>(text);

	text_ = &GetComponent<Text>();
}

void CommandMemory::sendCommand(int Button, int Playerid)
{
	//操作権を持つプレイヤーか確かめる
	if (NowPlayer_ == Playerid)
	{
		if (itr_ == cmList_.end())
		{
			//要素を追加し、イテレータを初期位置に戻す
			cmList_.push_back(Button);
			itr_ = cmList_.begin();

			//プレイヤーの操作権を変更
			if (++NowPlayer_ + 1 >= Players_)
				NowPlayer_ -= (Players_ - 1);

			text_->SetText(std::format("プレイヤー{:d}のターン", NowPlayer_ + 1));
		}
		else
		{
			if (*itr_ == Button)
			{
				++itr_;
			}
			else
			{
				KillAllChildren();
			}
		}
	}
}
