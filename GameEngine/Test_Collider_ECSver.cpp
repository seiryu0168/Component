#include "Test_Collider_ECSver.h"
#include"Test_BoxCollider_ECSver.h"
Test_Collider_ECSver::Test_Collider_ECSver()
{
}

bool Test_Collider_ECSver::IsHitBox_Box(Test_BoxCollider_ECSver* boxA, Test_BoxCollider_ECSver* boxB)
{
	XMFLOAT3 boxPos1 = StoreFloat3(boxA->attachObject_->GetComponent<Transform>().position_ + XMLoadFloat3(&boxA->center_));
	XMFLOAT3 boxPos2 = StoreFloat3(boxB->attachObject_->GetComponent<Transform>().position_ + XMLoadFloat3(&boxB->center_));

	if ((boxPos1.x + boxA->size_.x / 2) > (boxPos2.x - boxB->size_.x / 2) &&
		(boxPos1.x - boxA->size_.x / 2) < (boxPos2.x + boxB->size_.x / 2) &&
		(boxPos1.y + boxA->size_.y / 2) > (boxPos2.y - boxB->size_.y / 2) &&
		(boxPos1.y - boxA->size_.y / 2) < (boxPos2.y + boxB->size_.y / 2) &&
		(boxPos1.z + boxA->size_.z / 2) > (boxPos2.z - boxB->size_.z / 2) &&
		(boxPos1.z - boxA->size_.z / 2) < (boxPos2.z + boxB->size_.z / 2))
	{
		return true;
	}

	return false;
}
