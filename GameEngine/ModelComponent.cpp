#include "ModelComponent.h"
#include"Engine/ResourceManager/Model.h"
ModelComponent::ModelComponent(Object* atcObj)
	:Component(atcObj),
	hModel_(-1)
{
}

ModelComponent::ModelComponent()
{
}

ModelComponent::~ModelComponent()
{
}

void ModelComponent::Draw()
{
}
