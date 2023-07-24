#include "Player_ChickenRace.h"
#include "ChickenRace.h"
#include "../Engine/DirectX_11/Input.h"

Player_ChickenRace::Player_ChickenRace(Object* parent)
	: Player(parent, "Player_ChickenRace"), watch_()
{
}

void Player_ChickenRace::Initialize()
{
}

void Player_ChickenRace::Update()
{
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
			c->SendTime(this, watch_.GetSeconds<float>());
		}
	}
}

void Player_ChickenRace::Draw()
{
}

void Player_ChickenRace::Release()
{
	watch_.~Watch();
}
