#include "RootObject_Result.h"
#include"../../Engine/Components/Transform.h"
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

}

void RootObject_Result::SetTransform()
{
}

void RootObject_Result::Release()
{
}
