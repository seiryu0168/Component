#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowCone_Cup : public GameObject
{
private:
	float coneSize_;
	int iceNum_;
	int cupNum_;
public:
	SnowCone_Cup(Object* parent);
	~SnowCone_Cup();

	void Initialize() override;
	int GetConeSize();
	float GetConeHeight();
	void SetColor(const XMFLOAT4& color);
	void SetTopping(int topNum);
	void SetConeSize(float size);
	void ChangeDrawTarget(int num);
	void ToppingSetUp();
	XMVECTOR GetIceBonePos(const std::string& boneName);
	void RemoveIce();
	void Release() override;
};