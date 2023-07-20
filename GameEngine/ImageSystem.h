#pragma once
#include"System.h"
#include"Image.h"
class ImageSystem : public System
{
public:
	ImageSystem();
	~ImageSystem() {};
	void Update() override;
	void Release() override;
};