#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowCone_Cup : public GameObject
{
private:
	float coneSize_;
	int coneScore_;

	int iceNum_;
	int cupNum_;

	float easingTime_;
	bool isEasing_;
public:
	SnowCone_Cup(Object* parent);
	~SnowCone_Cup();
	void Initialize() override;
	void Update() override;
	int GetConeSize();
	float GetConeHeight();
	void SetColor(const XMFLOAT4& color);
	void SetTopping(int topNum);
	void SetConeSize(float size);
	void ChangeDrawTarget(int num);
	void ToppingSetUp();
	void StartEasing() { isEasing_ = true; }
	bool IsEasing() { return isEasing_; }
	XMVECTOR GetIceBonePos(const std::string& boneName);
	void RemoveIce();
	void Release() override;
};