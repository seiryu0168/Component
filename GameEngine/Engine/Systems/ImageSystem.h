#pragma once
#include"../ECS/System.h"
#include"../Components/Image.h"
class ImageSystem : public System
{
public:
	ImageSystem();
	~ImageSystem() {};
	//void Update() override;
	void Draw() override;
	void Release() override;
	int IsHitCursorAny();
};