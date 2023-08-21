#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowCone_Topping;
class SnowCone_Ice : public GameObject
{
private:
	SnowCone_Topping* top_;
	XMFLOAT3 color_;
public:
	SnowCone_Ice(Object* parent);
	~SnowCone_Ice();

	void Initialize() override;
	void SetColor(const XMFLOAT4& color);
	void SetTopping(int topNum);
	void RemoveTopping();
	void Release() override;
};

