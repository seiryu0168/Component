#include "ModelSystem.h"
#include"Coordinator.h"
ModelSystem::ModelSystem() : System()
{
}

void ModelSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<Test_Model_ECSver>(entity).Draw();
	}
}

void ModelSystem::Release()
{
	//std::set<Entity> ent = entities_;
	for (Entity entity : entities_)
	{
		//entities_
		Coordinator::RemoveComponent<Test_Model_ECSver>(entity);
		Coordinator::DestroyEntity(entity);
		//if (itr != entities_.end())
		//	itr++;
		//itr = entities_.erase(itr);
	}
}
