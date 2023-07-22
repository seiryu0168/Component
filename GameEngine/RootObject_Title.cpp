#include "RootObject_Title.h"
#include"Engine/GameObject/Transform.h"
#include"TestObject.h"
RootObject_Title::RootObject_Title()
{
	Transform transform;
	AddComponent<Transform>(transform);
}

RootObject_Title::~RootObject_Title()
{
}

void RootObject_Title::Initialize()
{
	Instantiate<TestObject>(this);
}

void RootObject_Title::SetTransform()
{
	
}

void RootObject_Title::Release()
{
}
