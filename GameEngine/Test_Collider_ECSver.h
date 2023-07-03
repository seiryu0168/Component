#pragma once
#include"Engine/DirectX_11/Math.h"
#include"Engine/GameObject/GameObject.h"
#include"Coordinator.h"

//class Test_BoxCollider_ECSver;
enum class COLLIDERTYPE
{
	TYPE_BOX=0,
	TYPE_SPHERE,
};
//
//struct HitBox 
//{
//	XMFLOAT3     center_;		//���_
//	XMFLOAT3     size_;			//�傫��
//};
//struct HitSphere
//{
//	XMFLOAT3     center_;		//���_
//	float		 radius_;		//���a
//};

class Test_Collider_ECSver
{
private:
	friend class Test_BoxCollider_ECSver;
	Entity colliderEntity_;
	XMFLOAT3     center_;		//���_
	COLLIDERTYPE colliderType_;
	bool		 isKill_;
	bool prevHit_;
	bool nowHit_;
	GameObject* attachObject_;
public:

	Test_Collider_ECSver();
	//Test_Collider_ECSver(HitBox boxCollider);
	//Test_Collider_ECSver(HitSphere sphereCollider);
	virtual ~Test_Collider_ECSver() {};

	void SetAttachObject(GameObject* object) { attachObject_ = object; }
	GameObject* GetAttachObject() { return attachObject_; }
	void SetColliderType(COLLIDERTYPE type);
	COLLIDERTYPE GetType() { return colliderType_; }
	const XMFLOAT3& GetCenter() { return center_; }

	//bool IsHitBox_Box(Test_BoxCollider_ECSver* boxA, Test_BoxCollider_ECSver* boxB);
};