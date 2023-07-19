#include "TransformSystem.h"
#include"Coordinator.h"
void TransformSystem::Release()
{
	std::set<Entity> ent = entities_;
	for (Entity entity : ent)
	{
		Coordinator::RemoveComponent<Transform>(entity);
		Coordinator::DestroyEntity(entity);
	}
}
