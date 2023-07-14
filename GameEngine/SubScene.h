#pragma once
#include"Engine\GameObject\GameObject.h"
class SubScene : public GameObject
{
public:
	SubScene(Object* parent);
	~SubScene();
	void Initialize() override;
	void Update() override;
	void Release() override;
};

