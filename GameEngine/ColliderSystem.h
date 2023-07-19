#pragma once
#include"System.h"
#include"Coordinator.h"
#include"Engine/Collider/Collider.h"
class ColliderSystem : public System
{
public:
	ColliderSystem();
	void Update() override;
	void Release() override;
	void CheckCollision(Collider* firstTarget, Collider* secondTarget);
	
	bool IsHitBox_Box(Collider* firstTarget, Collider* secondTarget);
	bool IsHitBox_Sphere(Collider* firstTarget, Collider* secondTarget);
	bool IsHitSphere_Sphere(Collider* firstTarget, Collider* secondTarget);

};

