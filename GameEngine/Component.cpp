#include "Component.h"

Component::Component(GameObject* atcObj, Component* parent)
	:attacheObject_(atcObj),
	parent_(parent)
{
}

Component::Component()
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
