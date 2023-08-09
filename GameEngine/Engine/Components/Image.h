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
	Image(int cameraNum = -1);
	~Image();
	//�摜���[�h
	bool Load(const std::string& name, const std::string& tab = "");
	//���W�ݒ�
	void SetPosition(const XMFLOAT3& pos);
	//���W�ݒ�(�s�N�Z���P��)
	void SetPositionAtPixel(XMFLOAT3 pos);
	//�����x�ݒ�
	void SetAlpha(float alpha);
	//�摜�T�C�Y�ݒ�
	void SetSize(const XMFLOAT3& size);
	//�摜��]
	void SetRotation(const XMFLOAT3& rotate);
	//�`��Ώېݒ�(������ʎ�)
	void SetDrawTarget(int targetNum) { drawTargetNumber_ = targetNum; }
	//�`��
	void Draw();

	XMFLOAT3 GetPosition() const { XMFLOAT3 pos; XMStoreFloat3(&pos, transform_.position_); return pos; }

	bool IsHitCursor();
};

