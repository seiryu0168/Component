#include "TextSystem.h"
#include"Coordinator.h"
TextSystem::TextSystem()
{
}

void TextSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<Text>(entity).Draw();
	}
}

void TextSystem::Release()
{

	std::set<Entity> ent = entities_;
	for (Entity entity : ent)
	{
		//entities_
		Coordinator::RemoveComponent<Text>(entity);
		Coordinator::DestroyEntity(entity);
		//if (itr != entities_.end())
		//	itr++;
		//itr = entities_.erase(itr);
	}
}
