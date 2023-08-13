#pragma once
#include"Engine/GameObject/GameObject.h"
#include<random>
class Shooting_Table : public GameObject
{
public:
	Shooting_Table(Object* parent);
	~Shooting_Table();
	void Initialize() override;
	void Load(const std::string& fileName);
	void Release() override;
};

