#include "RootObject_Play.h"
#include "../../MiniGames/ChickenRace.h"
#include"../../MiniGames/Shooting.h"
#include"../../InterSceneData.h"
RootObject_Play::RootObject_Play()
{
}

RootObject_Play::~RootObject_Play()
{
}

void RootObject_Play::Initialize()
{
	switch (InterSceneData::GetData<int>("GameNumber"))
	{
	case 0:
	Instantiate<Shooting>(this);
	break;
	default:
		break;
	}
}

void RootObject_Play::Release()
{
}
