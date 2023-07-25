#include "Player_ChickenRace.h"
#include "ChickenRace.h"
#include "../Engine/DirectX_11/Input.h"
#include <format>

Player_ChickenRace::Player_ChickenRace(Object* parent)
	: Player(parent, "Player_ChickenRace"), watch_(), text_(nullptr)
{
}

void Player_ChickenRace::Initialize()
{
	Text text;
	AddComponent<Text>(text);

	//�R���|�[�l���g��������A���H�\�ɂ���
	text_ = &GetComponent<Text>();
}

void Player_ChickenRace::Update()
{
	float f = watch_.GetSeconds<float>();

	//�]�v�Ȍ���\�����Ȃ�
	text_->SetText(std::format("{:g}", f));

	if (Input::IsMouseButtonDown(0))
	{
		if (watch_.IsLock())
		{
			watch_.UnLock();
		}
		else
		{
			watch_.Lock();
			ChickenRace* c = (ChickenRace*)GetParent();
			c->SendTime(this, f);
		}
	}

	//1�b�����Ď��Ԃ������Ȃ�����
	if (f >= 2)
	{
		text_->SetColor({ 1,1,1, std::lerp(1.0f, 0.0f, f - 2)});
	}
}

void Player_ChickenRace::Draw()
{
}

void Player_ChickenRace::Release()
{
	watch_.~Watch();
}
