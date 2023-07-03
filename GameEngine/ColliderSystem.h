#pragma once
#include"System.h"
#include"Coordinator.h"
#include"Engine/Collider/BoxCollider.h"
class ColliderSystem : public System
{
public:
	ColliderSystem();
	void Update() override;
	void CheckCollision(Collider* firstTarget, Collider* secondTarget);
	bool IsHitBox_Box(Collider* firstTarget, Collider* secondTarget);
};

