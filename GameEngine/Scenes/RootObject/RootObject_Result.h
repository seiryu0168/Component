#pragma once
#include"../../Engine/GameObject/Object.h"
class RootObject_Result : public Object
{
public:
	RootObject_Result();
	~RootObject_Result();
	void Initialize() override;
	void Release() override;
};

