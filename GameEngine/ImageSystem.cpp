#include "ImageSystem.h"
#include"Coordinator.h"
ImageSystem::ImageSystem()
{
}

void ImageSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<Image>(entity).Draw();
	}
}

void ImageSystem::Release()
{
	std::set<Entity> ent = entities_;
	for (Entity entity : ent)
	{
		//entities_
		Coordinator::RemoveComponent<Image>(entity);
		Coordinator::DestroyEntity(entity);
		//if (itr != entities_.end())
		//	itr++;
		//itr = entities_.erase(itr);
	}
}
