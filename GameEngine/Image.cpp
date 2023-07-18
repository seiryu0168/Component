#include "Image.h"
#include"ImageManager_ECSver.h"
Image::Image()
	:alpha_(1.0f),
	rect_({0,0,1,1})
{
}

Image::~Image()
{
}

bool Image::Load(std::string name)
{
	pSprite_ = ImageManager_ECSver::Load(name);
	if(pSprite_==nullptr)
	return false;

	XMFLOAT3 size = pSprite_->GetSize();
	rect_ = { 0,0,(long)size.x,(long)size.y };
	return true;
}

void Image::SetPosition(XMFLOAT3& pos)
{
	transform_.position_ = XMLoadFloat3(&pos);
}

void Image::SetAlpha(float alpha)
{
	alpha_ = alpha;
}

void Image::SetSize(XMFLOAT3 size)
{
	transform_.scale_ = size;
}

void Image::SetRotation(XMFLOAT3 rotate)
{
	transform_.RotateEular(rotate);
}

void Image::Draw()
{
	pSprite_->Draw(transform_, rect_, color_, alpha_);
}
