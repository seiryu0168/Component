#pragma once
#include"Engine/GameObject/GameObject.h"
class SnowConeMaker : public GameObject
{
private:

public:
	SnowConeMaker(Object* parent);
	~SnowConeMaker();

	void Initialize() override;
	void Release() override;
};

