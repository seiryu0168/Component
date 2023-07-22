#pragma once
#include"../ECS/System.h"
#include"../Components/Text.h"
class TextSystem : public System
{
public:
	TextSystem();
	~TextSystem() {};
	void Update() override;
	void Release() override;
};

