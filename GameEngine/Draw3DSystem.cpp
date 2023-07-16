#include "Draw3DSystem.h"
#include"Coordinator.h"

Draw3DSystem::Draw3DSystem()
{
	Coordinator::RegisterComponent<Test_Model_ECSver>();
	Coordinator::RegisterComponent<Particle>();
}

void Draw3DSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<Draw3DComponent>(entity).Draw();
	}
}
