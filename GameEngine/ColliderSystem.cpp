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
			
			CheckCollision(&firstCollision,&secondCollision);
		}
	}
}

void ColliderSystem::CheckCollision(Test_Collider_ECSver* firstTarget, Test_Collider_ECSver* secondTarget)
{
	bool isCollision = false;
	switch (firstTarget->GetType())
	{
	case COLLIDERTYPE::TYPE_BOX:
		switch (secondTarget->GetType())
		{
		case COLLIDERTYPE::TYPE_BOX:
			isCollision = IsHitBox_Box(firstTarget, secondTarget);
			break;
		case COLLIDERTYPE::TYPE_SPHERE:
			break;
		default:
			break;
		}
		break;
	case COLLIDERTYPE::TYPE_SPHERE:
		break;
	default:
		break;
	}

	if (isCollision)
		firstTarget->GetAttachObject()->OnCollision(secondTarget->GetAttachObject());

}

bool ColliderSystem::IsHitBox_Box(Test_Collider_ECSver* firstTarget, Test_Collider_ECSver* secondTarget)
{
	XMFLOAT3 boxPos1 = StoreFloat3(firstTarget->GetAttachObject()->GetComponent<Transform>().position_ + XMLoadFloat3(&firstTarget->GetCenter()));
	XMFLOAT3 boxPos2 = StoreFloat3(secondTarget->GetAttachObject()->GetComponent<Transform>().position_ + XMLoadFloat3(&secondTarget->GetCenter()));

	if ((boxPos1.x + firstTarget->GetSize().x / 2) > (boxPos2.x - secondTarget->GetSize().x / 2) &&
		(boxPos1.x - firstTarget->GetSize().x / 2) < (boxPos2.x + secondTarget->GetSize().x / 2) &&
		(boxPos1.y + firstTarget->GetSize().y / 2) > (boxPos2.y - secondTarget->GetSize().y / 2) &&
		(boxPos1.y - firstTarget->GetSize().y / 2) < (boxPos2.y + secondTarget->GetSize().y / 2) &&
		(boxPos1.z + firstTarget->GetSize().z / 2) > (boxPos2.z - secondTarget->GetSize().z / 2) &&
		(boxPos1.z - firstTarget->GetSize().z / 2) < (boxPos2.z + secondTarget->GetSize().z / 2))
	{
		return true;
	}

	return false;
}
