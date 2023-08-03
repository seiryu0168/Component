#include "Shooting_Table.h"
#include"Engine/Systems/ModelSystem.h"
Shooting_Table::Shooting_Table(Object* parent)
	:GameObject(parent,"Shooting_Table")
{
}

Shooting_Table::~Shooting_Table()
{
}

void Shooting_Table::Initialize()
{
	transform_->position_ = XMVectorSet(0, 0, 30, 0);
	//Test_Model_ECSver model(this);
	//model.Load("Assets/Model/Shooting_Table.fbx");
	//AddComponent<Test_Model_ECSver>(model);
}

void Shooting_Table::Release()
{
}
