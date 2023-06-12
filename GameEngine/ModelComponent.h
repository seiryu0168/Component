#pragma once
#include"Component.h"
class ModelComponent : public Component
{
	int hModel_;
public:
	ModelComponent(Object* atcObj);
	ModelComponent();
	~ModelComponent();

	void Draw();
};

