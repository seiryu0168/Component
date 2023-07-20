#pragma once
#include<bitset>
#include"ECS.h"
//using Entity = unsigned int;
//const Entity MAX_ENTITIES = 5000;
//using ComponentType = unsigned int;
//const ComponentType MAX_COMPONENTS = 32;
//using Signature = std::bitset<MAX_COMPONENTS>;

class IComponentArray
{
public:
	virtual ~IComponentArray()=default;
	virtual void EntityDestroyed(const Entity& entity) = 0;
	virtual void Clear() = 0;
};

