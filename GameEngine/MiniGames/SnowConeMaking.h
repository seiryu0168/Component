#pragma once
#include"Framework.h"
class SnowConeMaking : public Framework
{
private:

public:
	SnowConeMaking(Object* parent);
	~SnowConeMaking();
	void Initialize() override;
	void Release()override;
};

