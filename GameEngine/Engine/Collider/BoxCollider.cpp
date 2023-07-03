#include "BoxCollider.h"

BoxCollider::BoxCollider()
	:Collider()
{
}

BoxCollider::BoxCollider(XMFLOAT3 basePos, XMFLOAT3 size)
{
	SetCenter(basePos);
	size_ = size;
}

BoxCollider::~BoxCollider()
{
}

//�Փ˔���
//���������I�u�W�F�N�g�̓����蔻�肪target�ɓ���
//bool BoxCollider::IsHit(Collider* target)
//{
//	switch (target->type_)
//	{
//	case BOX_COLLIDER:
//		return IsHitBox_Box((BoxCollider*)target, this);
//
//	case SPHERE_COLLIDER:
//		return IsHitBox_Sphere(this, (SphereCollider*)target);
//	}
//}