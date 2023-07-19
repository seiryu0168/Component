#pragma once
#include"System.h"
#include"Engine/ResourceManager/Text.h"
class TextSystem : public System
{
public:
	TextSystem();
	void Update() override;
	void Release() override;
};

