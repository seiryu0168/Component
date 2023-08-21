#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowCone_Cup : public GameObject
{
private:
public:
	SnowCone_Cup(Object* parent);
	~SnowCone_Cup();

	void Initialize() override;
	void SetColor(const XMFLOAT4& color);
	void Release() override;
};