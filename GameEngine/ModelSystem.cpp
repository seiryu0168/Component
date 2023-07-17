#include "ModelSystem.h"
#include"Coordinator.h"
ModelSystem::ModelSystem()
{
}

void ModelSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<Test_Model_ECSver>(entity).Draw();
	}
}
