#include "ParticleSystem.h"
#include"../Coordinator.h"

ParticleSystem::ParticleSystem() : System()
{

}

void ParticleSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<Particle>(entity).Update();
	}
}

void ParticleSystem::Draw()
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

void ParticleSystem::CheckRemove()
{
	std::set<Entity> subEntities = entities_;
	for (Entity entity : subEntities)
	{
		if (Coordinator::GetComponent<Particle>(entity).GetAttachedObject() == nullptr)
			Coordinator::RemoveComponent<Particle>(entity);
	}
}
