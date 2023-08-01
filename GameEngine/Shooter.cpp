#include "Shooter.h"
#include "Engine/Systems/ImageSystem.h"
Shooter::Shooter(Object* parent)
	:GameObject(parent,"Shooter")
{
}

Shooter::~Shooter()
{
}

void Shooter::Initialize()
{
	Image image;
	image.Load("Assets/Image/Fire.png");
	AddComponent<Image>(image);
}

void Shooter::Update()
{
}

void Shooter::Release()
{
}
