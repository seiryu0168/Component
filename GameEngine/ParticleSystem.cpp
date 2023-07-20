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
	//for�����Œl�������̂ŃR�s�[���ĉ�
	std::set<Entity> subEntity = entities_;
	for (Entity entity : subEntity)
	{
		Coordinator::RemoveComponent<Particle>(entity);
		Coordinator::DestroyEntity(entity);
	}
}
