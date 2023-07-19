#include "LineParticleSystem.h"
#include"Coordinator.h"
LineParticleSystem::LineParticleSystem()
{
}

void LineParticleSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<LineParticle>(entity).Draw();
	}
}
