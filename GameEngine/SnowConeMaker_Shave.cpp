#include "SnowConeMaker_Shave.h"
#include"Engine/GameObject/CameraManager.h"
#include"Engine/DirectX_11/Input.h"
#include"SnowCone_Cup.h"
#include"Engine/Systems/ImageSystem.h"
namespace
{
	const XMVECTOR DEFAULT_POS = XMVectorSet(-40, 8, -40, 0);
	const float SNOWCONE_SIZE_DELTA = 0.01f;
	const float SNOWCONE_SIZE_LIMIT = 4.0f;
}

SnowConeMaker_Shave::SnowConeMaker_Shave(Object* parent)
	:GameObject(parent, "SnowConeMaker_Shave"),
	snowConeSize_(0.0f)
{
}

SnowConeMaker_Shave::~SnowConeMaker_Shave()
{
}

void SnowConeMaker_Shave::Initialize()
{
	transform_->position_ = DEFAULT_POS;
	CameraManager::GetCamera(playerNum_).SetPosition(transform_->position_);
	snowCone_ = Instantiate<SnowCone_Cup>(GetParent());// = std::make_shared<SnowCone_Cup>(GetParent());
	CameraManager::GetCamera(playerNum_).SetTarget(XMVectorSet(-40,0,-30,0));

	{

		Image image(playerNum_);
		image.Load("Assets/Image/SnowCone_ShaveMeterImage.png");
		image.SetPositionAtPixel({ 1700,-512,0 });
		image.SetSize({ 0.5f,snowConeSize_,0 });
		AddComponent<Image>(image);
	}
	{

		Image image(playerNum_);
		image.Load("Assets/Image/SnowCone_ShaveMeterFrameImage.png");
		image.SetPositionAtPixel({ 1700,0,0 });
		image.SetSize({ 0.5f,1.0f,0 });
		AddComponent<Image>(image);
	}

}

void SnowConeMaker_Shave::Update()
{

	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_X))
	{
		snowCone_->KillMe();
		snowCone_ = Instantiate<SnowCone_Cup>(GetParent());
		snowConeSize_ = 0.0f;
		GetComponent<Image>().SetSize({ 0.5f,snowConeSize_,0 });
	}
	

	if (Input::IsPadButton(XINPUT_GAMEPAD_A)&&snowCone_&& snowConeSize_<SNOWCONE_SIZE_LIMIT)
	{
		Shave();
	}

}

void SnowConeMaker_Shave::Shave()
{
	GameObject* obj = (GameObject*)snowCone_->FindChild("SnowCone_Ice");
	if (obj)
	{
		obj->GetTransform()->scale_.y += SNOWCONE_SIZE_DELTA*0.3f;
		snowConeSize_ += SNOWCONE_SIZE_DELTA;
		GetComponent<Image>().SetSize({ 0.5f,snowConeSize_,0 });
	}
}

void SnowConeMaker_Shave::Release()
{
}
