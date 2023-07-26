#pragma once
#include"../ECS/System.h"
#include"../Coordinator.h"
#include"../Components/Collider.h"
class ColliderSystem : public System
{
public:
	ColliderSystem();
	~ColliderSystem() {};
	void Update() override;
	void Release() override;
	void CheckRemove() override;
	void CheckCollision(Collider* firstTarget, Collider* secondTarget) const;
	
	bool IsHitBox_Box(Collider* firstTarget, Collider* secondTarget) const;
	bool IsHitBox_Sphere(Collider* firstTarget, Collider* secondTarget) const;
	bool IsHitSphere_Sphere(Collider* firstTarget, Collider* secondTarget) const;

};

