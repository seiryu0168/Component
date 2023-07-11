#include "RootObject.h"
#include"Engine/GameObject/Transform.h"

RootObject::RootObject()
{
	Transform transform;
	AddComponent<Transform>(transform);
}

RootObject::~RootObject()
{
}

void RootObject::Initialize()
{
}

void RootObject::Release()
{
}
