#include "PhysicsSystem.h"
#include"Coordinator.h"


void PhysicsSystem::Update(float dt)
{
	for (auto const& entity : entities_)
	{
		auto& rigidBody = Coordinator::GetComponent<RigidBody>(entity);
		auto& transform = Coordinator::GetComponent<TransformData>(entity);
		auto& gravity = Coordinator::GetComponent<Gravity>(entity);

		transform.position_ += rigidBody.vector_ * dt;
		rigidBody.vector_ += gravity.force_ * dt;

	}
}
