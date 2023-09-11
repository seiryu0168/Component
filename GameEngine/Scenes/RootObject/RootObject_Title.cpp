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
	Image image(-1, 2);
	image.StaticLoad("Assets/Image/Filter.png");
	image.SetSize({ 1920,1080,0 });
	image.SetAlpha(0);
	StaticResource::AddImage("Filter",image);
	Instantiate<Title>(this);
}

void RootObject_Title::Release()
{
}
