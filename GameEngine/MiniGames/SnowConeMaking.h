#pragma once
#include"Framework.h"

class SnowCone_Cup;
class SnowConeMaking : public Framework
{
private:
	std::queue<SnowCone_Cup*> cupList_;
public:
	SnowConeMaking(Object* parent);
	~SnowConeMaking();
	void Initialize() override;
	void AddCup(SnowCone_Cup* cup);
	SnowCone_Cup* GetCup();
	void Release()override;
};

