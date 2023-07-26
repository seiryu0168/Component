#include "ImageSystem.h"
#include"../Coordinator.h"
ImageSystem::ImageSystem() : System()
{
}

//void ImageSystem::Update()
//{
//}

void ImageSystem::Draw()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<Image>(entity).Draw();
	}
}

void ImageSystem::Release()
{
	//for文内で値を消すのでコピーして回す
	std::set<Entity> subEntity = entities_;
	for (Entity entity : subEntity)
	{
		Coordinator::RemoveComponent<Image>(entity);
		Coordinator::DestroyEntity(entity);
	}
}
