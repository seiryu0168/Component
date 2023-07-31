#pragma once
#include"Engine/GameObject/GameObject.h"
class Title : public GameObject
{
public:
	Title(Object* parent);
	~Title();
	void Initialize() override;
	void Update() override;
	void Release() override;
};

