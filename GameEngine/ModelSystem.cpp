#include "ModelSystem.h"
#include"Coordinator.h"
ModelSystem::ModelSystem()
{
	Coordinator::RegisterComponent<Test_Model_ECSver>();
}

void ModelSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<Test_Model_ECSver>(entity).Draw();
	}
}
