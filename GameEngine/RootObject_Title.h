#pragma once
#include"Object.h"
class RootObject_Title : public Object
{
public:
	RootObject_Title();
	~RootObject_Title();
	void Initialize() override;
	void SetTransform();
	void Release() override;
};

