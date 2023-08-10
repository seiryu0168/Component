#pragma once
#include"Result_Single.h"
class Result_Shooting : public Result_Single<int>
{
public:
	Result_Shooting(Object* parent);
	~Result_Shooting();

	void Initialize() override;
	void Update() override;
	void Release() override;
};

