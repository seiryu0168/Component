#pragma once
#include"System.h"
#include"Draw2DComponent.h"
class Draw2DSystem : public System
{
public:
	Draw2DSystem();
	void Update() override;
};

