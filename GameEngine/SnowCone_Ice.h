#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowCone_Ice : public GameObject
{
private:
public:
	SnowCone_Ice(Object* parent);
	~SnowCone_Ice();

	void Initialize() override;
	void SetColor(const XMFLOAT4& color);
	void Release() override;
};

