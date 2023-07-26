#include "RootObject_Play.h"
#include "../../MiniGames/ChickenRace.h"

RootObject_Play::RootObject_Play()
{
}

RootObject_Play::~RootObject_Play()
{
}

void RootObject_Play::Initialize()
{
	Instantiate<ChickenRace>(this);
}

void RootObject_Play::Release()
{
}
