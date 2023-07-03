#include "ColliderSystem.h"
#include"Engine/GameObject/GameObject.h"
ColliderSystem::ColliderSystem()
{
	Coordinator::RegisterComponent<HitBox>();
	Coordinator::RegisterComponent<HitSphere>();
	Signature collSignature;
	collSignature.set(Coordinator::GetComponentType<HitBox>());
	collSignature.set(Coordinator::GetComponentType<HitSphere>());

	//Coordinator::SetSystemSignature<ColliderSystem>(collSignature);
}

void ColliderSystem::Update()
{
	for (auto const& firstEntity : entities_)
	{
		auto& firstCollision = Coordinator::GetComponent<Collider>(firstEntity);
		for (auto const& secondEntity : entities_)
		{
			if (firstEntity == secondEntity)
			{
				continue;
			}
			auto& secondCollision = Coordinator::GetComponent<Collider>(secondEntity);
			
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

bool ColliderSystem::IsHitBox_Box(Collider* firstTarget,Collider* secondTarget)
{
	XMFLOAT3 boxPos1 = StoreFloat3(firstTarget->GetAttachObject()->GetComponent<Transform>().position_ + XMLoadFloat3(&firstTarget->GetCenter()));
	XMFLOAT3 boxPos2 = StoreFloat3(secondTarget->GetAttachObject()->GetComponent<Transform>().position_ + XMLoadFloat3(&secondTarget->GetCenter()));

	if ((boxPos1.x + firstTarget->GetCollisionShape<HitBox>().size_.x) > (boxPos2.x - secondTarget->GetCollisionShape<HitBox>().size_.x) &&
		(boxPos1.x - firstTarget->GetCollisionShape<HitBox>().size_.x) < (boxPos2.x + secondTarget->GetCollisionShape<HitBox>().size_.x) &&
		(boxPos1.y + firstTarget->GetCollisionShape<HitBox>().size_.y) > (boxPos2.y - secondTarget->GetCollisionShape<HitBox>().size_.y) &&
		(boxPos1.y - firstTarget->GetCollisionShape<HitBox>().size_.y) < (boxPos2.y + secondTarget->GetCollisionShape<HitBox>().size_.y) &&
		(boxPos1.z + firstTarget->GetCollisionShape<HitBox>().size_.z) > (boxPos2.z - secondTarget->GetCollisionShape<HitBox>().size_.z) &&
		(boxPos1.z - firstTarget->GetCollisionShape<HitBox>().size_.z) < (boxPos2.z + secondTarget->GetCollisionShape<HitBox>().size_.z))
	{
		return true;
	}

	return false;
}
