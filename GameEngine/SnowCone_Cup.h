#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowCone_Cup : public GameObject
{
private:
	float coneSize_;
public:
	SnowCone_Cup(Object* parent);
	~SnowCone_Cup();

	void Initialize() override;
	int GetConeSize();
	void SetColor(const XMFLOAT4& color);
	void SetTopping(int topNum);
	void SetConeSize(float size) { coneSize_ = size; }
	XMVECTOR GetIceBonePos(const std::string& boneName);
	void RemoveIce();
	void Release() override;
};