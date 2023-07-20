#include "ParticleSystem.h"
#include"Coordinator.h"

ParticleSystem::ParticleSystem() : System()
{

}

void ParticleSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<Particle>(entity).Draw();
	}
}

void ParticleSystem::Release()
{
	//std::set<Entity> ent = entities_;
	for (Entity entity : entities_)
	{
		//entities_
		Coordinator::RemoveComponent<Particle>(entity);
		Coordinator::DestroyEntity(entity);
		//if (itr != entities_.end())
		//	itr++;
		//itr = entities_.erase(itr);
	}
}
