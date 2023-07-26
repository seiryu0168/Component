#pragma once
#include<set>
#include"ECS.h"

class System
{
public:
	std::set<Entity> entities_;
	System() :entities_(){};
	~System() {};
	virtual void Init() {};
	virtual void Update() {};
	virtual void Release() {};
};

