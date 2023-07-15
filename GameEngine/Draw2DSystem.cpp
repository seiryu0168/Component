#include "Draw2DSystem.h"
#include"Coordinator.h"
Draw2DSystem::Draw2DSystem()
{
	Coordinator::RegisterComponent<Text>();
}

void Draw2DSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<Draw2DComponent>(entity).Draw();
	}
}
