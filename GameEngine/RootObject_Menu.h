#pragma once
#include"Object.h"
class RootObject_Menu : public Object
{
public:
	RootObject_Menu();
	~RootObject_Menu();
	void Initialize() override;
	void SetTransform();
	void Release() override;
};

