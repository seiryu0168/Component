#include "DrawComponent.h"

DrawComponent::DrawComponent(Object* atcObj)
	:Component(atcObj)
{
	Draw = nullptr;
	SecondDraw = nullptr;
	ThirdDraw = nullptr;
}

DrawComponent::~DrawComponent()
{
}

void DrawComponent::Start()
{
}

void DrawComponent::Update()
{
	DrawSub();
	SecondDrawSub();
	ThirdDrawSub();
}

void DrawComponent::AddDrawList(DrawComponent* comp)
{

	drawComponentList_.push_back(comp);
}

void DrawComponent::DD()
{
}

void DrawComponent::DrawSub()
{
	if (attacheObject_->IsActive() && attacheObject_->IsStart())
	{
		if (Draw != nullptr)
			Draw();
	}
	for (auto drw : drawComponentList_)
	{
		drw->DrawSub();
	}
}

void DrawComponent::SecondDrawSub()
{
	if (attacheObject_->IsActive() && attacheObject_->IsStart())
	{
		if (SecondDraw != nullptr)
			SecondDraw();
	}
	for (auto drw : drawComponentList_)
	{
		drw->SecondDrawSub();
	}
}

void DrawComponent::ThirdDrawSub()
{
	if (attacheObject_->IsActive() && attacheObject_->IsStart())
	{
		if (ThirdDraw != nullptr)
			ThirdDraw();
	}
	for (auto drw : drawComponentList_)
	{
		drw->ThirdDrawSub();
	}
}
