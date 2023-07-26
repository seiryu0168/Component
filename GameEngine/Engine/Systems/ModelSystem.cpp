#include "ModelSystem.h"
ModelSystem::ModelSystem() : System()
{
}

//void ModelSystem::Update()
//{
//	
//}

void ModelSystem::Draw()
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

void ModelSystem::CheckRemove()
{
	std::set<Entity> subEntities = entities_;
	for (Entity entity : subEntities)
	{
		if (Coordinator::GetComponent<Test_Model_ECSver>(entity).GetAttachedObject() == nullptr)
			Coordinator::RemoveComponent<Test_Model_ECSver>(entity);
	}
}
