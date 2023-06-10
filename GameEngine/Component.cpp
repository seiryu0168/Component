#include "Component.h"
#include"Object.h"
Component::Component(Object* atcObj, Component* parent)
	:attacheObject_(atcObj),
	parent_(parent)
{
}

Component::Component()
	:attacheObject_(nullptr),
	parent_(nullptr)
{
}

void Component::SetParent(Component* parent)
{
	parent_ = parent;
}

Component* Component::GetParent()
{
	return parent_;
}
