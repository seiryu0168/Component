#pragma once
#include"Engine/DirectX_11/Math.h"
#include"Engine/GameObject/GameObject.h"

class Test_BoxCollider_ECSver;
enum class COLLIDERTYPE
{
	TYPE_BOX=0,
};
class Test_Collider_ECSver
{
private:
	friend class Test_BoxCollider_ECSver;
	XMFLOAT3     center_;		//Œ´“_
	XMFLOAT3     size_;			//‘å‚«‚³
	COLLIDERTYPE colliderType_;
	bool		 isKill_;
	bool prevHit_;
	bool nowHit_;
	GameObject* attachObject_;
public:

	Test_Collider_ECSver();
	virtual ~Test_Collider_ECSver() {};

	virtual bool IsHit(Test_Collider_ECSver* target) = 0;
	GameObject* GetAttachObject() { return attachObject_; }

	bool IsHitBox_Box(Test_BoxCollider_ECSver* boxA, Test_BoxCollider_ECSver* boxB);
};