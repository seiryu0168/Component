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
//	XMFLOAT3     center_;		//原点
//	XMFLOAT3     size_;			//大きさ
//};
//struct HitSphere
//{
//	XMFLOAT3     center_;		//原点
//	float		 radius_;		//半径
//};

class Test_Collider_ECSver
{
private:
	friend class Test_BoxCollider_ECSver;
	Entity colliderEntity_;
	XMFLOAT3     center_;		//原点
	XMFLOAT3     size_;			//大きさ
	COLLIDERTYPE colliderType_;
	bool		 isKill_;
	bool prevHit_;
	bool nowHit_;
	GameObject* attachObject_;
public:

	Test_Collider_ECSver();
	Test_Collider_ECSver(XMFLOAT3 basePos, XMFLOAT3 size);
	//Test_Collider_ECSver(HitBox boxCollider);
	//Test_Collider_ECSver(HitSphere sphereCollider);
	~Test_Collider_ECSver();

	//virtual bool IsHit(Test_Collider_ECSver* target) = 0;
	GameObject* GetAttachObject() { return attachObject_; }
	COLLIDERTYPE GetType() { return colliderType_; }

	const XMFLOAT3& GetCenter() { return center_; }
	const XMFLOAT3& GetSize() { return size_; }

	//bool IsHitBox_Box(Test_BoxCollider_ECSver* boxA, Test_BoxCollider_ECSver* boxB);
};