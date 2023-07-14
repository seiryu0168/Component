#include "RootObject.h"
#include"Engine/GameObject/Transform.h"

RootObject::RootObject()
{
}

RootObject::~RootObject()
{
}

void RootObject::Initialize()
{
}

void RootObject::SetTransform()
{
	Transform transform;
	AddComponent<Transform>(transform);
}

void RootObject::Release()
{
}
