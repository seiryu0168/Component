#include "ColliderSystem.h"
#include"Engine/GameObject/GameObject.h"
void ColliderSystem::Update()
{
	for (auto const& firstEntity : entities_)
	{
		auto& firstCollision = Coordinator::GetComponent<BoxCollider>(firstEntity);
		for (auto const& secondEntity : entities_)
		{
			if (firstEntity == secondEntity)
			{
				continue;
			}
			auto& secondCollision = Coordinator::GetComponent<BoxCollider>(secondEntity);
			
			CheckCollision(&firstCollision,&secondCollision);
		}
	}
}

void ColliderSystem::CheckCollision(Collider* firstTarget, Collider* secondTarget)
{
	bool isCollision = false;
	switch (firstTarget->GetType())
	{
	case ColliderType::BOX_COLLIDER:
		switch (secondTarget->GetType())
		{
		case ColliderType::BOX_COLLIDER:
			isCollision = IsHitBox_Box((BoxCollider*)firstTarget, (BoxCollider*)secondTarget);
			break;
		case ColliderType::SPHERE_COLLIDER:
			break;
		default:
			break;
		}
		break;
	case ColliderType::SPHERE_COLLIDER:
		break;
	default:
		break;
	}

	if (isCollision)
		firstTarget->GetAttachObject()->OnCollision(secondTarget->GetAttachObject());

}

bool ColliderSystem::IsHitBox_Box(BoxCollider* firstTarget, BoxCollider* secondTarget)
{
	XMFLOAT3 boxPos1 = StoreFloat3(firstTarget->GetAttachObject()->GetComponent<Transform>().position_ + XMLoadFloat3(&firstTarget->GetCenter()));
	XMFLOAT3 boxPos2 = StoreFloat3(secondTarget->GetAttachObject()->GetComponent<Transform>().position_ + XMLoadFloat3(&secondTarget->GetCenter()));

	if ((boxPos1.x + firstTarget->GetSize().x) > (boxPos2.x - secondTarget->GetSize().x) &&
		(boxPos1.x - firstTarget->GetSize().x) < (boxPos2.x + secondTarget->GetSize().x) &&
		(boxPos1.y + firstTarget->GetSize().y) > (boxPos2.y - secondTarget->GetSize().y) &&
		(boxPos1.y - firstTarget->GetSize().y) < (boxPos2.y + secondTarget->GetSize().y) &&
		(boxPos1.z + firstTarget->GetSize().z) > (boxPos2.z - secondTarget->GetSize().z) &&
		(boxPos1.z - firstTarget->GetSize().z) < (boxPos2.z + secondTarget->GetSize().z))
	{
		return true;
	}

	return false;
}
