#include "DrawComponent.h"
#include"Test_Model_ECSver.h"
DrawComponent::DrawComponent()
{
	
}

DrawComponent::DrawComponent(GameObject* object)
{
	attachObject_ = object;
}

void DrawComponent::SetAttachObject(GameObject* object)
{
	attachObject_ = object;
}

void DrawComponent::Draw()
{
	
}
