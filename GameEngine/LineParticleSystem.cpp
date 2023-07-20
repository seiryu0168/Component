#include "LineParticleSystem.h"
#include"Coordinator.h"
LineParticleSystem::LineParticleSystem() : System()
{
}

void LineParticleSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<LineParticle>(entity).Draw();
	}
}

void LineParticleSystem::Release()
{
	//std::set<Entity> ent = entities_;
	for (Entity entity : entities_)
	{
		//entities_
		Coordinator::RemoveComponent<LineParticle>(entity);
		Coordinator::DestroyEntity(entity);
		//if (itr != entities_.end())
		//	itr++;
		//itr = entities_.erase(itr);
	}

}
