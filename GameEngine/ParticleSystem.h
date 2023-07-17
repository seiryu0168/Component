#pragma once
#include"System.h"
#include"Engine/DirectX_11/Particle.h"
class ParticleSystem : public System
{
public:
	ParticleSystem();
	void Update() override;
};

