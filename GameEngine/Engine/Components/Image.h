#pragma once
#include"../DirectX_11/Sprite.h"
#include<memory>
class Image
{
private:
	std::string imageName_;
	std::shared_ptr<Sprite> pSprite_;
	RECT rect_;
	XMFLOAT4 color_;
	float alpha_;
	int drawTargetNumber_;
	Transform transform_;
public:
	Image();
	~Image();
	bool Load(const std::string& name);
	void SetPosition(const XMFLOAT3& pos);
	void SetPositionAtPixel(XMFLOAT3 pos);
	void SetAlpha(float alpha);
	void SetDrawTarget(int targetNum) { drawTargetNumber_ = targetNum; }
	void SetSize(const XMFLOAT3& size);
	void SetRotation(const XMFLOAT3& rotate);
	void Draw();


};

