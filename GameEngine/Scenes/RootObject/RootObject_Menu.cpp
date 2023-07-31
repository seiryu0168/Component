#include "RootObject_Menu.h"
#include"../../Engine/Components/Transform.h"
#include"../../SelectUI.h"

RootObject_Menu::RootObject_Menu()
{
	Transform transform;
	AddComponent<Transform>(transform);
}

RootObject_Menu::~RootObject_Menu()
{
}

void RootObject_Menu::Initialize()
{
	Instantiate<SelectUI>(this);
	
}

void RootObject_Menu::SetTransform()
{
	Transform transform;
	AddComponent<Transform>(transform);
}

void RootObject_Menu::Release()
{
}
