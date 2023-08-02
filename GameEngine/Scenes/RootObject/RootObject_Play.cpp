#include "RootObject_Play.h"
#include "../../MiniGames/ChickenRace.h"
#include"../../MiniGames/Shooting.h"

RootObject_Play::RootObject_Play()
{
}

RootObject_Play::~RootObject_Play()
{
}

void RootObject_Play::Initialize()
{
	Instantiate<Shooting>(this);
}

void RootObject_Play::Release()
{
}
