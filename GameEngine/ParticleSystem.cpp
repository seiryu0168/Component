#include "ParticleSystem.h"
#include"Coordinator.h"

ParticleSystem::ParticleSystem()
{

}

void ParticleSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<Particle>(entity).Draw();
	}
}
