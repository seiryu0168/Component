#pragma once
#include<set>
#include"ECS.h"

class System
{
public:
	std::set<Entity> entities_;
	virtual void Init() {};
	virtual void Update() {};
	virtual void Release() {};
};

