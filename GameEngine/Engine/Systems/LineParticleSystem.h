#pragma once
#include"../ECS/System.h"
#include"../Components/LineParticle.h"
class LineParticleSystem : public System
{
public:
	LineParticleSystem();
	~LineParticleSystem() {};
	void Update() override;
	void Draw() override;
	void Release() override;
	void CheckRemove() override;
};

