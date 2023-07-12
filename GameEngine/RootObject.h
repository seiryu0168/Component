#pragma once
#include"Object.h"

class RootObject : public Object
{
public:
	RootObject();
	~RootObject();
	void Initialize() override;
	void SetTransform();
	void Release() override;
};

