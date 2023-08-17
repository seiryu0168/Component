#pragma once
#include"Engine/GameObject/GameObject.h"
class Select_StaticUI : public GameObject
{
private:
	std::vector<int> backGrountImageList_;
public:
	Select_StaticUI(Object* parent);
	~Select_StaticUI();

	void Initialize() override;
	void Release() override;
};

