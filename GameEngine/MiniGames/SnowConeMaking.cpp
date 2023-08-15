#include "SnowConeMaking.h"
#include"../Engine/GameObject/CameraManager.h"
#include"../SnowConeMaker_Shave.h"
#include"../SnowConeMaker_Topping.h"
#include"../SnowCone_Table.h"
SnowConeMaking::SnowConeMaking(Object* parent)
	:Framework(parent,"SnowConeMaking")
{
}

SnowConeMaking::~SnowConeMaking()
{
}

void SnowConeMaking::Initialize()
{
	CameraManager::AllRmoveCamera();
	D2D::AllRemoveRenderTarget();
	{
		Camera camera;
		XMINT2 WH = { Direct3D::GetScreenWidth() ,Direct3D::GetScreenHeight() };
		camera.Initialize(WH.x, WH.y, 1.0f, 500.0f);
		camera.SetViewPort(WH.x / 2.0f, WH.y / 2.0f, 0.0f, 1.0f, 0, WH.y / 4.0f);
		CameraManager::AddCamera(camera);
	}

	{
		Camera camera;
		XMINT2 WH = { Direct3D::GetScreenWidth() ,Direct3D::GetScreenHeight() };
		camera.Initialize(WH.x, WH.y, 1.0f, 500.0f);
		camera.SetViewPort(WH.x / 2.0f, WH.y / 2.0f, 0.0f, 1.0f, WH.x/2.0f, WH.y / 4.0f);
		CameraManager::AddCamera(camera);
	}

	Instantiate<SnowCone_Table>(this);
	Instantiate<SnowConeMaker_Shave>(this)->SetPlayerNumber(0);
	Instantiate<SnowConeMaker_Topping>(this)->SetPlayerNumber(1);
}


void SnowConeMaking::Release()
{
}
