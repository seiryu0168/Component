#pragma once
#include"System.h"
#include"Test_Model_ECSver.h"
#include"DrawComponent.h"
class ModelSystem : public System
{
public:
	ModelSystem();
	void Update() override;
};

