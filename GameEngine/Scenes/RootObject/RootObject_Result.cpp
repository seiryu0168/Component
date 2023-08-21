#include "RootObject_Result.h"
#include"../../Engine/Components/Transform.h"
#include"../../InterSceneData.h"
#include"../../Result_Shooting.h"
#include"../../Result_Multi.h"
RootObject_Result::RootObject_Result()
{
	Transform transform;
	AddComponent<Transform>(transform);
}

RootObject_Result::~RootObject_Result()
{
}

void RootObject_Result::Initialize()
{
	switch (InterSceneData::GetData<int>("GameNumber"))
	{
		using enum GAME_ID;
	case (int)SHOOTING:
		Instantiate<Result_Shooting>(this);
		break;

	case (int)CHICKENRACE:
	case (int)COMMANDMEMORY:
		Instantiate<Result_Multi>(this);
		break;
	default:
		break;
	}
}

void RootObject_Result::Release()
{
}
