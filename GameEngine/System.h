#pragma once
#include<set>

using Entity = unsigned int;
const Entity MAX_ENTITIES = 5000;
using ComponentType = unsigned int;
const ComponentType MAX_COMPONENTS = 32;

class System
{
public:
	std::set<Entity> entities_;
};

