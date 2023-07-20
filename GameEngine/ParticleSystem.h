#pragma once
#include"System.h"
#include"Engine/DirectX_11/Particle.h"
class ParticleSystem : public System
{
public:
	ParticleSystem();
	~ParticleSystem() {};
	void Update() override;
	void Release() override;
};

