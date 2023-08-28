#include "SnowCone_Cup.h"
#include"Engine/Systems/ModelSystem.h"
#include"Engine/Systems/ImageSystem.h"
#include"SnowCone_Ice.h"

SnowCone_Cup::SnowCone_Cup(Object* parent)
	:GameObject(parent, "SnowCone_Cup"),
	coneSize_(0),
	iceNum_(0)
{
}

SnowCone_Cup::~SnowCone_Cup()
{
}

void SnowCone_Cup::Initialize()
{

	//Instantiate<SnowCone_Ice>(this);

	{
		Image image(1, 0);
		image.Load("Assets/Image/SnowCone_IceImage.png");
		image.SetPositionAtPixel({ 0,180, 0 });
		iceNum_ = AddComponent<Image>(image);

	}
	{
		Image image(1, 0);
		image.Load("Assets/Image/SnowCone_CupImage.png");
		AddComponent<Image>(image);
	}
	//Test_Model_ECSver model(this);
	//model.Load("Assets/Model/SnowCone_Cup.fbx");
	//AddComponent<Test_Model_ECSver>(model);
	//transform_->position_ = XMVectorSet(-40, 0, -30, 0);

}

int SnowCone_Cup::GetConeSize()
{
	return (int)(coneSize_/1.32f);
}

void SnowCone_Cup::SetColor(const XMFLOAT4& color)
{
	((SnowCone_Ice*)FindChild("SnowCone_Ice"))->SetColor(color);
}

void SnowCone_Cup::SetTopping(int topNum)
{
	((SnowCone_Ice*)FindChild("SnowCone_Ice"))->SetTopping(0);
}

void SnowCone_Cup::SetConeSize(float size)
{
	coneSize_ += size;
	GetComponent<Image>(iceNum_).SetSize({ 1,coneSize_+1,0 });
}

void SnowCone_Cup::ChangeDrawTarget(int num)
{
	GetComponent<Image>().SetDrawTarget(num);
	GetComponent<Image>(iceNum_).SetDrawTarget(num);
	GetComponent<Image>().SetAlpha(0);
	GetComponent<Image>(iceNum_).SetAlpha(0);
}

XMVECTOR SnowCone_Cup::GetIceBonePos(const std::string& boneName)
{
	return ((SnowCone_Ice*)FindChild("SnowCone_Ice"))->GetComponent<Test_Model_ECSver>().GetBone(boneName);
}

void SnowCone_Cup::RemoveIce()
{
	((SnowCone_Ice*)FindChild("SnowCone_Ice"))->RemoveTopping();
}

void SnowCone_Cup::Release()
{
}
