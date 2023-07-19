#pragma once
#include"System.h"
#include"Test_Model_ECSver.h"
class ModelSystem : public System
{
public:
	ModelSystem();
	void Update() override;
	void Release() override;
};

