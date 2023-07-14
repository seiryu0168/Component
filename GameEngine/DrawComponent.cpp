#include "DrawComponent.h"
#include"Test_Model_ECSver.h"
#include"Engine/ResourceManager/Text.h"
DrawComponent::DrawComponent()
{
	
}

DrawComponent::DrawComponent(GameObject* object)
{
	attachObject_ = object;
}

auto DrawComponent::GetDrawObjdect(std::string name)
{
	if (name == "class Test_Model_ECSver")
		return Coordinator::GetComponent<Test_Model_ECSver>(drawEntity_);
}

void DrawComponent::SetDrawType(std::string name)
{
	if (name == "class Test_Model_ECSver")
	{
		type_ = DrawType::TYPE_MODEL;
		return;
	}
	if (name == "class Text")
	{
		type_ = DrawType::TYPE_TEXT;
		return;
	}
	if (name == "class Particle")
	{
		type_ = DrawType::TYPE_PARTICLE;
		return;
	}
}

void DrawComponent::SetAttachObject(GameObject* object)
{
	attachObject_ = object;
}

void DrawComponent::Draw()
{

	//GetDrawObjdect(typeName_).Draw();
	switch (type_)
	{
	case DrawType::TYPE_MODEL:
		Coordinator::GetComponent<Test_Model_ECSver>(drawEntity_).Draw();
		break;
	case DrawType::TYPE_PARTICLE:
		Coordinator::GetComponent<Particle>(drawEntity_).Draw();
		break;
	case DrawType::TYPE_TEXT:
		Coordinator::GetComponent<Text>(drawEntity_).Draw();
		break;
	default:
		break;
	}
}
