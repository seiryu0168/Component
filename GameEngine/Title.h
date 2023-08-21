#pragma once
#include"Engine/GameObject/GameObject.h"
#include"Engine/Time.h"
class Title : public GameObject
{
private:
	std::unique_ptr<Time::Watch> time_;
public:
	Title(Object* parent);
	~Title();
	void Initialize() override;
	void Update() override;
	void Release() override;
};

