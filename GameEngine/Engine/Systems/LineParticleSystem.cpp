#include "LineParticleSystem.h"
#include"../Coordinator.h"
LineParticleSystem::LineParticleSystem() : System()
{
}

void LineParticleSystem::Update()
{
	std::set<Entity> subEntities = entities_;
	for (Entity entity : subEntities)
	{
		LineParticle& lineParticle = Coordinator::GetComponent<LineParticle>(entity);
		if (lineParticle.GetAttachedObject() == nullptr)
			Coordinator::RemoveComponent<LineParticle>(entity);
		else
			lineParticle.Draw();
	}
}

void LineParticleSystem::Release()
{
	//for文内で値を消すのでコピーして回す
	std::set<Entity> subEntity = entities_;
	for (Entity entity : subEntity)
	{
		Coordinator::RemoveComponent<LineParticle>(entity);
		Coordinator::DestroyEntity(entity);
	}

}
