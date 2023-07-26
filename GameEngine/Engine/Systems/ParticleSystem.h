#pragma once
#include"../ECS/System.h"
#include"../Components/Particle.h"
class ParticleSystem : public System
{
public:
	ParticleSystem();
	~ParticleSystem() {};
	void Update() override;
	void Draw() override;
	void Release() override;
	void CheckRemove() override;
};

