#pragma once
#include"Engine/DirectX_11/Sprite.h"
#include<memory>
class Image
{
private:
	std::string imageName_;
	std::shared_ptr<Sprite> pSprite_;
	RECT rect_;
	XMFLOAT4 color_;
	float alpha_;
	Transform transform_;
public:
	Image();
	~Image();
	bool Load(std::string name);
	void SetPosition(XMFLOAT3& pos);
	void SetAlpha(float alpha);
	void SetSize(XMFLOAT3 size);
	void SetRotation(XMFLOAT3 rotate);
	void Draw();


};

