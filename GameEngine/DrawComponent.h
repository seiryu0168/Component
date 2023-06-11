#pragma once
#include"Component.h"
#include<list>
#include"Engine/GameObject/GameObject.h"
class DrawComponent : public Component
{
	bool drawFlag_;
	std::list<DrawComponent*> drawComponentList_;
	
public:
	DrawComponent(Object* atcObj);
	~DrawComponent();
	void Start() override;
	void Update() override;
	void AddDrawList(DrawComponent* comp);
	void DD();
	void(*Draw)();
	void(*SecondDraw)();
	void(*ThirdDraw)();
	void DrawSub();
	void SecondDrawSub();
	void ThirdDrawSub();

};
