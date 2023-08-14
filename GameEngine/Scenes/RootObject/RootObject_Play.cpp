#include "RootObject_Play.h"
#include "../../MiniGames/ChickenRace.h"
#include "../../MiniGames/Commandmemory.h"
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
		using enum GAME_ID;
	case (int)SHOOTING:
		Instantiate<Shooting>(this);
		break;

	case (int)CHICKENRACE:
		Instantiate<ChickenRace>(this);
		break;

	case (int)COMMANDMEMORY:
		Instantiate<CommandMemory>(this);
		break;
	default:
		break;
	}
}

void RootObject_Play::Release()
{
}
