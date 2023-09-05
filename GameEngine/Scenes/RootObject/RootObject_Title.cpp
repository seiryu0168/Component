#include "RootObject_Title.h"
#include"../../Engine/Components/Transform.h"
#include"../../StaticResource.h"
#include"../../TestObject.h"
#include"../../SelectUI.h"
#include"../../Title.h"
RootObject_Title::RootObject_Title()
{
	//Transform transform;
	//AddComponent<Transform>(transform);
}

RootObject_Title::~RootObject_Title()
{
}

void RootObject_Title::Initialize()
{
	//StaticResource::StaticImageLoad("image01", "Assets/Image/Effect01.png", -1, 2);
	Instantiate<Title>(this);
}

void RootObject_Title::Release()
{
}
