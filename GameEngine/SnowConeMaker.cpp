#include "SnowConeMaker.h"
#include"Engine/Systems/ModelSystem.h"
SnowConeMaker::SnowConeMaker(Object* parent)
	:GameObject(parent,"SnoeConeMaker")
{
}

SnowConeMaker::~SnowConeMaker()
{
}

void SnowConeMaker::Initialize()
{
	{
		Test_Model_ECSver model(this);
		model.Load("Assets/Model/AAA.fbx");
		AddComponent<Test_Model_ECSver>(model);
	}
}

void SnowConeMaker::Release()
{
}
