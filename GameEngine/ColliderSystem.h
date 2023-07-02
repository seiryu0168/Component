#pragma once
#include"System.h"
#include"Coordinator.h"
#include"Test_Collider_ECSver.h"
#include"Test_BoxCollider_ECSver.h"
class ColliderSystem : public System
{
	void Update();
	void CheckCollision(Test_Collider_ECSver* firstTarget, Test_Collider_ECSver* secondTarget);
	bool IsHitBox_Box(Test_Collider_ECSver* firstTarget, Test_Collider_ECSver* secondTarget);
};

