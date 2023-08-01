#pragma once
#include"Engine/GameObject/GameObject.h"
class Shooting_Table : public GameObject
{
public:
	Shooting_Table(Object* parent);
	~Shooting_Table();
	void Initialize() override;
	void Release() override;
};

