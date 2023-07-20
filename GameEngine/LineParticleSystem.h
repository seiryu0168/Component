#pragma once
#include"System.h"
#include"Engine/DirectX_11/LineParticle.h"
class LineParticleSystem : public System
{
public:
	LineParticleSystem();
	~LineParticleSystem() {};
	void Update() override;
	void Release() override;
};

