#include "ModelSystem.h"
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
	//for�����Œl�������̂ŃR�s�[���ĉ�
	std::set<Entity> subEntity = entities_;
	for (Entity entity : subEntity)
	{
		
		Coordinator::RemoveComponent<Test_Model_ECSver>(entity);
		Coordinator::DestroyEntity(entity);
	}
}
