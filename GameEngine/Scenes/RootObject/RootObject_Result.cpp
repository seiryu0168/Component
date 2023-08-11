#include "RootObject_Result.h"
#include"../../Engine/Components/Transform.h"
#include"../../InterSceneData.h"
#include"../../Result_Shooting.h"
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
	case 0:
		Instantiate<Result_Shooting>(this);
		break;
	default:
		break;
	}
}

void RootObject_Result::SetTransform()
{
}

void RootObject_Result::Release()
{
}
