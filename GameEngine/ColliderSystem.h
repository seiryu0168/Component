#pragma once
#include"System.h"
#include"Coordinator.h"
#include"Test_Collider_ECSver.h"
class ColliderSystem : public System
{
	void Update();
	void CheckCollision(Test_Collider_ECSver* target);
};

