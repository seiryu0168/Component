#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowCone_ToppingSumple : public GameObject
{
private:
	XMFLOAT3 sumplePos_;
	int currentNum_;
	float offsetPosY_;
	float easingTime_;
	bool isMove_;
		 
public:
	SnowCone_ToppingSumple(Object* parent);
	~SnowCone_ToppingSumple();

	void Initialize() override;
	void Update() override;
	void ChangeSumple(int num);
	void SetSumpleSize(float size, float pos);
	void MoveSumple(float deltaPos);
	int  GetSumpleImageNum() { return currentNum_; }
	void Move() { isMove_ = true; }
	void Reset();
	void Release() override;

};

