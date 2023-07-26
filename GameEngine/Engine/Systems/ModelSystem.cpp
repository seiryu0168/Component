#include "ModelSystem.h"
ModelSystem::ModelSystem() : System()
{
}

void ModelSystem::Update()
{
	std::set<Entity> subEntities = entities_;
	for (Entity entity : subEntities)
	{
		Test_Model_ECSver& model = Coordinator::GetComponent<Test_Model_ECSver>(entity);
		if (model.GetAttachedObject() == nullptr)
			Coordinator::RemoveComponent<Test_Model_ECSver>(entity);
		else
			model.Draw();
	}
}

void ModelSystem::Release()
{
	//for文内で値を消すのでコピーして回す
	std::set<Entity> subEntity = entities_;
	for (Entity entity : subEntity)
	{
		
		Coordinator::RemoveComponent<Test_Model_ECSver>(entity);
		Coordinator::DestroyEntity(entity);
	}
}
