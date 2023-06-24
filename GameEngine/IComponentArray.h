#pragma once
#include<bitset>
#include<queue>
#include<array>
using Entity = unsigned int;
const Entity MAX_ENTITIES = 5000;
using ComponentType = unsigned int;
const ComponentType MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;

class IComponentArray
{
public:
	virtual ~IComponentArray()=default;
	virtual void EntityDestroyed(Entity entity) = 0;
};

