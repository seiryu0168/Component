#include "RootObject_Title.h"
#include"../../Engine/Components/Transform.h"
#include"../../TestObject.h"
#include"../../SelectUI.h"
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
	Instantiate<SelectUI>(this);
}

void RootObject_Title::SetTransform()
{
	
}

void RootObject_Title::Release()
{
}
