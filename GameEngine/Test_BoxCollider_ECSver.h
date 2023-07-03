#pragma once
#include"Test_Collider_ECSver.h"
#include"Engine/GameObject/GameObject.h"

class Test_BoxCollider_ECSver : public Test_Collider_ECSver
{
private:
	XMFLOAT3     size_;			//‘å‚«‚³
public:

	Test_BoxCollider_ECSver();
	Test_BoxCollider_ECSver(XMFLOAT3 basePos,XMFLOAT3 size);
	~Test_BoxCollider_ECSver();
	void SetPosition(XMFLOAT3 pos) { center_ = pos; }
	void SetSize(XMFLOAT3 size) { size_ = size; }
	//bool IsHit(Test_Collider_ECSver* target) override;

};

