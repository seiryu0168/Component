#include "LineParticleSystem.h"
#include"../Coordinator.h"
LineParticleSystem::LineParticleSystem() : System()
{
}

void LineParticleSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<LineParticle>(entity).Update();
	}
}

void LineParticleSystem::Draw()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<LineParticle>(entity).Draw();
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

void LineParticleSystem::CheckRemove()
{
	std::set<Entity> subEntities = entities_;
	for (Entity entity : subEntities)
	{
		if (Coordinator::GetComponent<LineParticle>(entity).GetAttachedObject() == nullptr)
			Coordinator::RemoveComponent<LineParticle>(entity);
	}
}
