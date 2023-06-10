#pragma once
#include"Engine/GameObject/GameObject.h"
class MainScene : public GameObject
{
	GameObject* pControlObject_;
public:
	MainScene(Object* parent);
	~MainScene();
	void Initialize() override;
	void Update() override;
	void Release() override;

};

