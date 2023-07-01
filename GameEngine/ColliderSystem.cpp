#include "ColliderSystem.h"

void ColliderSystem::Update()
{
	for (auto const& firstEntity : entities_)
	{
		auto& firstCollision = Coordinator::GetComponent<Test_Collider_ECSver>(firstEntity);
		for (auto const& secondEntity : entities_)
		{
			if (firstEntity == secondEntity)
			{
				continue;
			}
			auto& secondCollision = Coordinator::GetComponent<Test_Collider_ECSver>(secondEntity);
			
			CheckCollision(&firstCollision);
		}
	}
}

void ColliderSystem::CheckCollision(Test_Collider_ECSver* target)
{
	//target->GetAttachObject()->OnCollisionEnter();

}
