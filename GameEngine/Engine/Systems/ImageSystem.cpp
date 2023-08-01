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
	//for�����Œl�������̂ŃR�s�[���ĉ�
	std::set<Entity> subEntity = entities_;
	for (Entity entity : subEntity)
	{
		Coordinator::RemoveComponent<Image>(entity);
		Coordinator::DestroyEntity(entity);
	}
}

int ImageSystem::IsHitCursorAny()
{
	for (Entity entity : entities_)
	{
		if (Coordinator::GetComponent<Image>(entity).IsHitCursor())
			return entity;
	}
	return -1;
}
