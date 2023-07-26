#include "ParticleSystem.h"
#include"../Coordinator.h"

ParticleSystem::ParticleSystem() : System()
{

}

void ParticleSystem::Update()
{
	std::set<Entity> subEntities = entities_;
	for (Entity entity : subEntities)
	{
		Particle& particle = Coordinator::GetComponent<Particle>(entity);
		if (particle.GetAttachedObject() == nullptr)
			Coordinator::RemoveComponent<Particle>(entity);
		else
			particle.Draw();
	}
}

void ParticleSystem::Release()
{
	//for文内で値を消すのでコピーして回す
	std::set<Entity> subEntity = entities_;
	for (Entity entity : subEntity)
	{
		Coordinator::RemoveComponent<Particle>(entity);
		Coordinator::DestroyEntity(entity);
	}
}
