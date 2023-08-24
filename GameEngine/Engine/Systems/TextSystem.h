#pragma once
#include"../ECS/System.h"
#include"../Components/Text.h"
class TextSystem : public System
{
public:
	TextSystem();
	~TextSystem() {};
	//void Update() override;
	void Draw(int layerNum) override;
	void Release() override;
};

