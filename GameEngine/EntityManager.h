#pragma once


using Entity = unsigned int;
class EntityManager
{
private:

public:
	EntityManager();
	~EntityManager();

	Entity CreateEntity();
	void DestroyEntity(Entity entity);
	void SetSignature(Entity entity,)
};

