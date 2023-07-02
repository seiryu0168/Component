#pragma once
//#include"Test_Collider_ECSver.h"
#include"Engine/GameObject/GameObject.h"
//enum class COLLIDERTYPE
//{
//	TYPE_BOX = 0,
//	TYPE_SPHERE,
//};
class Test_BoxCollider_ECSver// : public Test_Collider_ECSver
{
private:
	//XMFLOAT3     center_;		//Œ´“_
	//XMFLOAT3     size_;			//‘å‚«‚³
	//COLLIDERTYPE colliderType_;
	//bool isKill_;
	//bool prevHit_;
	//bool nowHit_;
	//GameObject* attachObject_;
	//friend class Test_Collider_ECSver;
public:
	Test_BoxCollider_ECSver(XMFLOAT3 basePos,XMFLOAT3 size);
	~Test_BoxCollider_ECSver();
	//void SetPosition(XMFLOAT3 pos) { center_ = pos; }
	//void SetSize(XMFLOAT3 size) { size_ = size; }
	//bool IsHit(Test_Collider_ECSver* target) override;

};

