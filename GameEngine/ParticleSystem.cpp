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
	//for文内で値を消すのでコピーして回す
	std::set<Entity> subEntity = entities_;
	for (Entity entity : subEntity)
	{
		Coordinator::RemoveComponent<Particle>(entity);
		Coordinator::DestroyEntity(entity);
	}
}
