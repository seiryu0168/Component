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
	virtual void Draw(int drawLayer = 0) {};
	virtual void CheckRemove() {};
	virtual void Release() {};
};

