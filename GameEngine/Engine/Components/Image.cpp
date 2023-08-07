#include "Image.h"
#include"../ResourceManager/ImageManager_ECSver.h"
#include"../DirectX_11/Direct3D.h"
#include"../GameObject/CameraManager.h"
#include "../DirectX_11/Input.h"

Image::Image(int cameraNum)
	:alpha_(1.0f),
	rect_({ 0,0,1,1 }),
	color_(),
	imageName_(""),
	pSprite_(),
	transform_(),
	drawTargetNumber_(cameraNum)
{
}

Image::~Image()
{
}

bool Image::Load(const std::string& name)
{
	pSprite_ = ImageManager_ECSver::Load(name);
	if(pSprite_==nullptr)
	return false;

	XMFLOAT3 size = pSprite_->GetSize();
	rect_ = { 0,0,(long)size.x,(long)size.y };
	return true;
}

void Image::SetPosition(const XMFLOAT3& pos)
{
	transform_.position_ = XMLoadFloat3(&pos);
}

void Image::SetPositionAtPixel(XMFLOAT3 pos)
{
	pos.x = pos.x / (float)Direct3D::GetScreenWidth() ;
	pos.y = pos.y / (float)Direct3D::GetScreenHeight();
	transform_.position_ = XMLoadFloat3(&pos);
}	

void Image::SetAlpha(float alpha)
{
	alpha_ = alpha;
}

void Image::SetSize(const XMFLOAT3& size)
{
	transform_.scale_ = size;
}

void Image::SetRotation(const XMFLOAT3& rotate)
{
	transform_.RotateEular(rotate);
}

void Image::Draw()
{
	if(drawTargetNumber_ == CameraManager::GetCurrentCameraNum() || drawTargetNumber_ == -1)
	pSprite_->Draw(transform_, rect_, color_, alpha_);
}

bool Image::IsHitCursor()
{
    UINT wid = (UINT)(pSprite_->GetSize().x * transform_.scale_.x / 2);
    UINT hgt = (UINT)(pSprite_->GetSize().y * transform_.scale_.y / 2);
    float Left = (XMVectorGetX(transform_.position_) + 1) * (Direct3D::GetScreenWidth() / 2.0f) - wid;
    float Right = (XMVectorGetX(transform_.position_) + 1) * (Direct3D::GetScreenWidth() / 2.0f) + wid;
    float Top = (-XMVectorGetY(transform_.position_) + 1) * (Direct3D::GetScreenHeight() / 2.0f) - hgt;
    float Bottom = (-XMVectorGetY(transform_.position_) + 1) * (Direct3D::GetScreenHeight() / 2.0f) + hgt;
    if (Left <= XMVectorGetX(Input::GetMousePosition()) && XMVectorGetX(Input::GetMousePosition()) <= Right &&
        Top <= XMVectorGetY(Input::GetMousePosition()) && XMVectorGetY(Input::GetMousePosition()) <= Bottom)
    {
        return true;
    }
    return false;
}
