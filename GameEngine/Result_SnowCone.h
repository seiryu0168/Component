#pragma once
#include"Result_Single.h"
class Result_SnowCone : public Result_Single<int>
{
public:
	Result_SnowCone(Object* parent);
	~Result_SnowCone();

	void Initialize() override;
	void Release() override;
};

