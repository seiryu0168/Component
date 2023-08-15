#include "SnowCone_Table.h"
#include"Engine/Systems/ModelSystem.h"

SnowCone_Table::SnowCone_Table(Object* parent)
	:GameObject(parent,"SnoeCone_Table")
{
}

SnowCone_Table::~SnowCone_Table()
{
}

void SnowCone_Table::Initialize()
{
	Test_Model_ECSver model(this);
	model.Load("Assets/Model/AAA.fbx");
	AddComponent<Test_Model_ECSver>(model);

}

void SnowCone_Table::Release()
{
}
