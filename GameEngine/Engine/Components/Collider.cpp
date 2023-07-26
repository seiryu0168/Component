#include "Collider.h"
#include"../../DebugUI.h"

Collider::Collider() : Collider({0,0,0})
{
}

Collider::Collider(const XMFLOAT3& centerPos)
	:attachObject_(nullptr),
	center_(centerPos),
	isKill_(false),
	colliderType_(ColliderType::BOX_COLLIDER),
	colliderEntity_(0),
	nowHit_(false),
	prevHit_(false)
{
}

Collider::~Collider()
{
}

void Collider::SetCollisionType(const std::string& name)
{
	if (name == "struct HitBox")
		colliderType_ = ColliderType::BOX_COLLIDER;
	else if (name == "struct HitSphere")
		colliderType_ = ColliderType::SPHERE_COLLIDER;
}





//bool Collider::IsHitBox_Box(BoxCollider* boxB, BoxCollider* boxA)
//{
//	//BoxPos��Float3Add�̖߂�l������
//	//����
//	//�����̍��W
//	//����̍��W
//
//	XMFLOAT3 boxPos1 = StoreFloat3(boxA->pColObject_->GetComponent<Transform>().position_+XMLoadFloat3(&boxA->center_));
//	XMFLOAT3 boxPos2 = StoreFloat3(boxB->pColObject_->GetComponent<Transform>().position_ + XMLoadFloat3(&boxB->center_));
//
//	if ((boxPos1.x + boxA->size_.x/ 2) > (boxPos2.x - boxB->size_.x / 2) &&
//		(boxPos1.x - boxA->size_.x / 2) < (boxPos2.x + boxB->size_.x / 2) &&
//		(boxPos1.y + boxA->size_.y / 2) > (boxPos2.y - boxB->size_.y / 2) &&
//		(boxPos1.y - boxA->size_.y / 2) < (boxPos2.y + boxB->size_.y / 2) &&
//		(boxPos1.z + boxA->size_.z / 2) > (boxPos2.z - boxB->size_.z / 2) &&
//		(boxPos1.z - boxA->size_.z / 2) < (boxPos2.z + boxB->size_.z / 2))
//	{
//		return true;
//	}
//
//	return false;
//
//}
//
//bool Collider::IsHitBox_Sphere(BoxCollider* box, SphereCollider* sphere)
//{
//	XMFLOAT3 boxPos =StoreFloat3(box->pColObject_->GetComponent<Transform>().position_ + XMLoadFloat3(&box->center_));
//	XMFLOAT3 spherePos= StoreFloat3(sphere->pColObject_->GetComponent<Transform>().position_+ XMLoadFloat3(&sphere->center_));
//
//	if (spherePos.x > boxPos.x - box->size_.x/2 - sphere->size_.x &&
//		spherePos.x < boxPos.x + box->size_.x/2 + sphere->size_.x &&
//		spherePos.y > boxPos.y - box->size_.y/2 - sphere->size_.x &&
//		spherePos.y < boxPos.y + box->size_.y/2 + sphere->size_.x &&
//		spherePos.z > boxPos.z - box->size_.z/2 - sphere->size_.x &&
//		spherePos.z < boxPos.z + box->size_.z/2 + sphere->size_.x)
//	{
//		return true;
//	}
//
//	return false;
//}
//
//bool Collider::IsHitSphere_Sphere(SphereCollider* sphereA, SphereCollider* sphereB)
//{
//	XMFLOAT3 spherePosA = sphereA->center_;
//	XMFLOAT3 positionA = sphereA->pColObject_->GetWorldPosition();
//	XMFLOAT3 spherePosB = sphereB->center_;
//	XMFLOAT3 positionB = sphereB->pColObject_->GetWorldPosition();
//
//	XMVECTOR vec = (XMLoadFloat3(&spherePosA) + XMLoadFloat3(&positionA)) - 
//				   (XMLoadFloat3(&spherePosB) + XMLoadFloat3(&positionB));
//
//	if (XMVector3Length(vec).m128_f32[0] <= sphereA->size_.x + sphereB->size_.x)
//	{
//		return true;
//	}
//	return false;
//
//}
//
////bool Collider::IsHitSphere_Polygon(SphereCollider* sphereA, std::vector<XMVECTOR> polyList)
////{
////	return false;
////}
//
//bool Collider::IsHitOBB_OBB(OBBCollider* obbA, OBBCollider* obbB)
//{
//	XMFLOAT3 obbAPos = StoreFloat3(obbA->pColObject_->GetComponent<Transform>().position_);
//	XMFLOAT3 obbBPos = StoreFloat3(obbB->pColObject_->GetComponent<Transform>().position_);
//	
//	XMVECTOR betweenCenterPoint = XMLoadFloat3(&obbBPos) - XMLoadFloat3(&obbAPos);
//
//	obbA->CalcAxisVec();
//	obbB->CalcAxisVec();
//
//	
//	
//	float rA = XMVectorGetX(XMVector3Length(obbA->OBB_X));								    //obbA�̒��S�_����̒���
//	float rB = obbA->prjLine(&obbA->OBB_X, &obbB->OBB_X, &obbB->OBB_Y, &obbB->OBB_Z);		//obbB�̒��S�_����̒���
//	float  L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, XMVector3Normalize(obbA->OBB_X))));//���S�_�Ԃ̒���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	rA = XMVectorGetX(XMVector3Length(obbA->OBB_Y));								    //obbA�̒��S�_����̒���
//	rB = obbA->prjLine(&obbA->OBB_Y, &obbB->OBB_X, &obbB->OBB_Y, &obbB->OBB_Z);			//obbB�̒��S�_����̒���
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, XMVector3Normalize(obbA->OBB_Y))));//���S�_�Ԃ̒���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	rA = XMVectorGetX(XMVector3Length(obbA->OBB_Z));								    //obbA�̒��S�_����̒���
//	rB = obbA->prjLine(&obbA->OBB_Z, &obbB->OBB_X, &obbB->OBB_Y, &obbB->OBB_Z);			//obbB�̒��S�_����̒���
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, XMVector3Normalize(obbA->OBB_Z))));//���S�_�Ԃ̒���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	rA = XMVectorGetX(XMVector3Length(obbB->OBB_X));								    //obbA�̒��S�_����̒���
//	rB = obbA->prjLine(&obbB->OBB_X, &obbA->OBB_X, &obbA->OBB_Y, &obbA->OBB_Z);			//obbB�̒��S�_����̒���
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, XMVector3Normalize(obbB->OBB_X))));//���S�_�Ԃ̒���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	rA = XMVectorGetX(XMVector3Length(obbB->OBB_Y));								    //obbA�̒��S�_����̒���
//	rB = obbA->prjLine(&obbB->OBB_Y, &obbA->OBB_X, &obbA->OBB_Y, &obbA->OBB_Z);			//obbB�̒��S�_����̒���
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, XMVector3Normalize(obbB->OBB_Y))));//���S�_�Ԃ̒���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	rA = XMVectorGetX(XMVector3Length(obbB->OBB_Z));								    //obbA�̒��S�_����̒���
//	rB = obbA->prjLine(&obbB->OBB_Z, &obbA->OBB_X, &obbA->OBB_Y, &obbA->OBB_Z);			//obbB�̒��S�_����̒���
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, XMVector3Normalize(obbB->OBB_Z))));//���S�_�Ԃ̒���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	///////////////////////////////��������O�ώ��ɂ��Փ˔���//////////////////////////////////////
//
//	XMVECTOR cross;
//	//obbA��X����obbB��X���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nX, obbB->nX));
//	rA = obbA->prjLine(&cross, &obbA->OBB_Y, &obbA->OBB_Z);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_Y, &obbB->OBB_Z);				//obbB�̒���
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));	//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��X����obbB��Y���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nX, obbB->nY));
//	rA = obbA->prjLine(&cross, &obbA->OBB_Y, &obbA->OBB_Z);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_X, &obbB->OBB_Z);				//obbB�̒���
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));	//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��X����obbB��Z���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nX, obbB->nZ));
//	rA = obbA->prjLine(&cross, &obbA->OBB_Y, &obbA->OBB_Z);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_X, &obbB->OBB_Y);				//obbB�̒���
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��Y����obbB��X���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nY, obbB->nX));
//	rA = obbA->prjLine(&cross, &obbA->OBB_X, &obbA->OBB_Z);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_Y, &obbB->OBB_Z);				//obbB�̒���
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��Y����obbB��Y���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nY, obbB->nY));
//	rA = obbA->prjLine(&cross, &obbA->OBB_X, &obbA->OBB_Z);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_X, &obbB->OBB_Z);				//obbB�̒���
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));	//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��Y����obbB��Z���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nY, obbB->nZ));
//	rA = obbA->prjLine(&cross, &obbA->OBB_X, &obbA->OBB_Z);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_X, &obbB->OBB_Y);				//obbB�̒���
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));	//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��Z����obbB��X���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nZ, obbB->nX));
//	rA = obbA->prjLine(&cross, &obbA->OBB_X, &obbA->OBB_Y);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_Y, &obbB->OBB_Z);				//obbB�̒���
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));	//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��Z����obbB��Y���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nZ, obbB->nY));
//	rA = obbA->prjLine(&cross, &obbA->OBB_X, &obbA->OBB_Y);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_X, &obbB->OBB_Z);				//obbB�̒���
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));	//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��Z����obbB��Z���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nZ, obbB->nZ));
//	rA = obbA->prjLine(&cross, &obbA->OBB_X, &obbA->OBB_Y);
//	rB = obbA->prjLine(&cross, &obbB->OBB_X, &obbB->OBB_Y);
//	L  = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//���S�_�Ԃ̋���������rA + rB�ȏ�ɂȂ�Ȃ������̂œ������Ă���
//	return true;
//}
//
//bool Collider::IsHitOBB_Sphere(OBBCollider* obb, SphereCollider* sphere)
//{
//	XMFLOAT3 obbPos = StoreFloat3(obb->pColObject_->GetComponent<Transform>().position_);
//	XMFLOAT3 spherePos = StoreFloat3(sphere->pColObject_->GetComponent<Transform>().position_);
//
//	XMVECTOR betweenCenterPoint = XMLoadFloat3(&spherePos) - XMLoadFloat3(&obbPos);
//
//	obb->CalcAxisVec();
//	
//	float L;
//	double rA = XMVectorGetX(XMVector3Length(obb->OBB_X));								    //obb�̒��S�_����̒���
//	double rB = sphere->size_.x;															//sphere�̒��S�_����̒���
//	L = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, XMVector3Normalize(obb->OBB_X))));//���S�_�Ԃ̒���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	rA = XMVectorGetX(XMVector3Length(obb->OBB_Y));								    //obbA�̒��S�_����̒���
//	rB = sphere->size_.x;															//obbB�̒��S�_����̒���
//	L = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, XMVector3Normalize(obb->OBB_Y))));//���S�_�Ԃ̒���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	rA = XMVectorGetX(XMVector3Length(obb->OBB_Z));								    //obbA�̒��S�_����̒���
//	rB = sphere->size_.x;															//obbB�̒��S�_����̒���
//	L = fabsf(XMVectorGetX(XMVector3Dot(betweenCenterPoint, XMVector3Normalize(obb->OBB_Z))));//���S�_�Ԃ̒���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//#if false
//	rA = XMVectorGetX(XMVector3Length(obbB->OBB_X));								    //obbA�̒��S�_����̒���
//	rB = sphere->size_.x;														//obbB�̒��S�_����̒���
//	L = fabs(XMVectorGetX(XMVector3Dot(betweenCenterPoint, XMVector3Normalize(obbB->OBB_X))));//���S�_�Ԃ̒���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	rA = XMVectorGetX(XMVector3Length(obbB->OBB_Y));								    //obbA�̒��S�_����̒���
//	rB = obbA->prjLine(&obbB->OBB_Y, &obbA->OBB_X, &obbA->OBB_Y, &obbA->OBB_Z);			//obbB�̒��S�_����̒���
//	L = fabs(XMVectorGetX(XMVector3Dot(betweenCenterPoint, XMVector3Normalize(obbB->OBB_Y))));//���S�_�Ԃ̒���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	rA = XMVectorGetX(XMVector3Length(obbB->OBB_Z));								    //obbA�̒��S�_����̒���
//	rB = obbA->prjLine(&obbB->OBB_Z, &obbA->OBB_X, &obbA->OBB_Y, &obbA->OBB_Z);			//obbB�̒��S�_����̒���
//	L = fabs(XMVectorGetX(XMVector3Dot(betweenCenterPoint, XMVector3Normalize(obbB->OBB_Z))));//���S�_�Ԃ̒���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	///////////////////////////////��������O�ώ��ɂ��Փ˔���//////////////////////////////////////
//
//	XMVECTOR cross;
//	//obbA��X����obbB��X���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nX, obbB->nX));
//	rA = obbA->prjLine(&cross, &obbA->OBB_Y, &obbA->OBB_Z);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_Y, &obbB->OBB_Z);				//obbB�̒���
//	L = fabs(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));	//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��X����obbB��Y���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nX, obbB->nY));
//	rA = obbA->prjLine(&cross, &obbA->OBB_Y, &obbA->OBB_Z);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_X, &obbB->OBB_Z);				//obbB�̒���
//	L = fabs(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));	//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��X����obbB��Z���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nX, obbB->nZ));
//	rA = obbA->prjLine(&cross, &obbA->OBB_Y, &obbA->OBB_Z);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_X, &obbB->OBB_Y);				//obbB�̒���
//	L = fabs(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��Y����obbB��X���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nY, obbB->nX));
//	rA = obbA->prjLine(&cross, &obbA->OBB_X, &obbA->OBB_Z);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_Y, &obbB->OBB_Z);				//obbB�̒���
//	L = fabs(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��Y����obbB��Y���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nY, obbB->nY));
//	rA = obbA->prjLine(&cross, &obbA->OBB_X, &obbA->OBB_Z);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_X, &obbB->OBB_Z);				//obbB�̒���
//	L = fabs(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));	//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��Y����obbB��Z���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nY, obbB->nZ));
//	rA = obbA->prjLine(&cross, &obbA->OBB_X, &obbA->OBB_Z);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_X, &obbB->OBB_Y);				//obbB�̒���
//	L = fabs(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));	//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��Z����obbB��X���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nZ, obbB->nX));
//	rA = obbA->prjLine(&cross, &obbA->OBB_X, &obbA->OBB_Y);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_Y, &obbB->OBB_Z);				//obbB�̒���
//	L = fabs(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));	//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��Z����obbB��Y���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nZ, obbB->nY));
//	rA = obbA->prjLine(&cross, &obbA->OBB_X, &obbA->OBB_Y);				//obbA�̒���
//	rB = obbA->prjLine(&cross, &obbB->OBB_X, &obbB->OBB_Z);				//obbB�̒���
//	L = fabs(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));	//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//obbA��Z����obbB��Z���̊O�� : ���̊O�ς𕪗����Ƃ��Čv�Z���s��
//	cross = XMVector3Normalize(XMVector3Cross(obbA->nZ, obbB->nZ));
//	rA = obbA->prjLine(&cross, &obbA->OBB_X, &obbA->OBB_Y);
//	rB = obbA->prjLine(&cross, &obbB->OBB_X, &obbB->OBB_Y);
//	L = fabs(XMVectorGetX(XMVector3Dot(betweenCenterPoint, cross)));//�������ɓ��e�������S�_�Ԃ̋���
//	if (L > rA + rB)
//	{
//		return false;
//	}
//
//	//���S�_�Ԃ̋���������rA + rB�ȏ�ɂȂ�Ȃ������̂œ������Ă���
//#endif
//	return true;
//}