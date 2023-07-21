#include "Component.h"
#include"Object.h"
Component::Component(Object* atcObj, Component* parent)
	:attacheObject_(atcObj),
	parent_(parent),
	componentID_()
{
}

Component::Component()
	:Component(nullptr, nullptr)
{
}

void Component::SetParent(Component* parent)
{
	parent_ = parent;
}

Component* Component::GetParent() const
{
	return parent_;
}
