#pragma once
#include"System.h"
#include"Coordinator.h"
#include"Engine/DirectX_11/Math.h"
struct Gravity
{
	XMVECTOR force_;
};

struct RigidBody
{
	XMVECTOR vector_;
	XMVECTOR acceleration_;
};

struct TransformData
{
	XMVECTOR position_;
	XMVECTOR rotation_;
	XMFLOAT3 scale_;
};
class PhysicsSystem : public System
{
	int time_;
public:
	PhysicsSystem();
	void Update() override;
	void PhysicsUpdate(float deltaTime);
};

