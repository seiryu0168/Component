#pragma once
#include"System.h"
#include"Engine/DirectX_11/LineParticle.h"
class LineParticleSystem : public System
{
public:
	LineParticleSystem();
	void Update() override;
};

