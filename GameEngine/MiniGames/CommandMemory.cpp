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
	text.SetText(std::format("�v���C���[{:d}�̃^�[��", NowPlayer_ + 1));
	text.SetPosition({ -500,1000 });
	AddComponent<Text>(text);

	text_ = &GetComponent<Text>();
}

void CommandMemory::sendCommand(int Button, int Playerid)
{
	//���쌠�����v���C���[���m���߂�
	if (NowPlayer_ == Playerid)
	{
		if (itr_ == cmList_.end())
		{
			//�v�f��ǉ����A�C�e���[�^�������ʒu�ɖ߂�
			cmList_.push_back(Button);
			itr_ = cmList_.begin();

			//�v���C���[�̑��쌠��ύX
			if (++NowPlayer_ + 1 >= Players_)
				NowPlayer_ -= (Players_ - 1);

			text_->SetText(std::format("�v���C���[{:d}�̃^�[��", NowPlayer_ + 1));
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
