#include "RootObject_Result.h"
#include"../../Engine/Components/Transform.h"
#include"../../InterSceneData.h"
#include"../../Result_Shooting.h"
#include"../../Result_SnowCone.h"
#include"../../StaticResource.h"
#include"../../Result_Multi.h"
#include "../../R_ChickenRace.h"
RootObject_Result::RootObject_Result()
{
	isSceneChange_ = false;
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
		Instantiate<R_ChickenRace>(this);
		break;
	case (int)COMMANDMEMORY:
		Instantiate<Result_Multi>(this);
		break;
	case (int)SNOWCONE:
		Instantiate<Result_SnowCone>(this);
		break;
	default:
		break;
	}

	AddComponent<Image>(StaticResource::GetImage("Filter"));
	timer_ = std::make_shared<Time::Watch>();
}

void RootObject_Result::Update()
{
	if (isSceneChange_)
	{
		float t = timer_->GetSeconds<float>();
		GetComponent<Image>().SetAlpha(t);
	}
}

void RootObject_Result::SceneChange()
{
	GetComponent<Image>().SetAlpha(0);
	GetComponent<Image>().SetDraw(true);
	isSceneChange_ = true;
	timer_->UnLock();
}

void RootObject_Result::Release()
{
}
