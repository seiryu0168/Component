#include "SnowCone_SyrupSelect.h"
#include"Engine/Systems/ImageSystem.h"
#include"Engine/DirectX_11/Input.h"

namespace
{
	const XMFLOAT3 IMAGEPOS[] = { {-1000,500,0},{-1000,0,0} };
}

SnowCone_SyrupSelect::SnowCone_SyrupSelect(Object* parent)
	:GameObject(parent,"SnowCone_SyrupSelect")
{
}

SnowCone_SyrupSelect::~SnowCone_SyrupSelect()
{
}

void SnowCone_SyrupSelect::Initialize()
{
	{
		Image image(1);
		image.Load("Assets/Image/SnowCone_Syrup_Red.png");
		image.SetPositionAtPixel(IMAGEPOS[0]);
		AddComponent<Image>(image);
	}
	{
		Image image(1);
		image.Load("Assets/Image/SnowCone_Syrup_Blue.png");
		image.SetPositionAtPixel(IMAGEPOS[1]);
		AddComponent<Image>(image);
	}
}

void SnowCone_SyrupSelect::Update()
{
	switch (Input::GetPadAnyDown())
	{
		case XINPUT_GAMEPAD_DPAD_DOWN
	}
}

void SnowCone_SyrupSelect::Release()
{
}
