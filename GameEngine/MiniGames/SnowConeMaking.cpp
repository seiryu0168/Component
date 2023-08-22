#include "SnowConeMaking.h"
#include"../Engine/GameObject/CameraManager.h"
#include"../SnowConeMaker_Shave.h"
#include"../SnowConeMaker_Topping.h"
#include"../SnowCone_Table.h"
#include"../SnowCone_Cup.h"
#include"../Engine/Systems/ImageSystem.h"
#include"../SnowCone_Order.h"

namespace
{
	static const XMFLOAT3 cupPos[3] = { {-10,0,0},{0,0,0},{10,0,0} };
}
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
		camera.SetViewPort(WH.x, WH.y, 0.0f, 1.0f, 0, 0);
		CameraManager::AddCamera(camera);

	}
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

	for(int i=0;i<2;i++)
	{
		Image image(i+1);
		image.Load("Assets/Image/MultiWindowFrame.png");
		AddComponent<Image>(image);
	}

	Instantiate<SnowCone_Order>(this);
	Instantiate<SnowCone_Table>(this);
	Instantiate<SnowConeMaker_Shave>(this)->SetPlayerNumber(0);
	Instantiate<SnowConeMaker_Topping>(this)->SetPlayerNumber(1);
}

void SnowConeMaking::AddCup(SnowCone_Cup* cup)
{
	if (cupList_.size() < 3)
	{
		cupList_.push(cup);
		for (int i = 0; i < cupList_.size(); i++)
		{
			cup->GetTransform()->position_ = XMLoadFloat3(&cupPos[i]);
		}
	}
	else
		cup->KillMe();
}

void SnowConeMaking::Evaluation(float size, int syrup, int topping)
{
	((SnowCone_Order*)FindChild("SnowCone_Order"))->Judge(size, syrup, topping);
}

SnowCone_Cup* SnowConeMaking::GetCup()
{
	SnowCone_Cup* cup = nullptr;
	if (cupList_.empty() == false)
	{
		cup = cupList_.front();
		cupList_.pop();
		return cup;
	}
	else
		return cup;
}



void SnowConeMaking::Release()
{
}
