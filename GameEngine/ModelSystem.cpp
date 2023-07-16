#include "ModelSystem.h"
#include"Coordinator.h"
ModelSystem::ModelSystem()
{
	//Coordinator::RegisterComponent<Test_Model_ECSver>();
	//Coordinator::RegisterComponent<Particle>();
	//Coordinator::RegisterComponent<Text>();
}

void ModelSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<DrawComponent>(entity).Draw();
	}
}
