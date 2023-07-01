#pragma once
#include"Test_Collider_ECSver.h"
class Test_BoxCollider_ECSver : private Test_Collider_ECSver
{
private:

	friend class Test_Collider_ECSver;
public:
	Test_BoxCollider_ECSver(XMFLOAT3 basePos,XMFLOAT3 size);
	bool IsHit(Test_Collider_ECSver* target) override;

};

