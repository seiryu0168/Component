#include "SnowCone_Table.h"
#include"Engine/Systems/ModelSystem.h"
#include"SnowCone_Cup.h"

SnowCone_Table::SnowCone_Table(Object* parent)
	:GameObject(parent,"SnoeCone_Table")
{
}

SnowCone_Table::~SnowCone_Table()
{
}

void SnowCone_Table::Initialize()
{
	//Instantiate<SnowCone_Cup>(GetParent());

}

void SnowCone_Table::Release()
{
}
