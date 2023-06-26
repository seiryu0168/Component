#pragma once
#include"Component.h"
#include<memory>
#include"Engine/DirectX_11/Math.h"
class TransformComponent : public Component
{
private:
	XMVECTOR RotationQuaternion_;

	XMMATRIX matTranslate_;	//�ړ��s��
	XMMATRIX matRotate_;	//��]�s��	
	XMMATRIX matScale_;	//�g��s��
public:
	XMFLOAT3 position_;	//�ʒu
	XMFLOAT3 rotate_;	//����
	XMFLOAT3 scale_;	//�g�嗦
	XMVECTOR baseVec_;	//��ƂȂ�x�N�g��
		
	std::shared_ptr<TransformComponent> pParent_;//�e�̏��
	
	TransformComponent(Object* atcObj);
	TransformComponent();
	~TransformComponent();

	//�e�s��̌v�Z
	void Calclation();

	//��]�s��Ɗg�k�̋t�s��̌v�Z
	XMMATRIX GetNormalMatrix();

	//���[���h�s����擾
	XMMATRIX GetWorldMatrix();
	XMMATRIX GetLocalMatrix();
	XMMATRIX GetLocalTranslateMatrix();
	XMMATRIX GetLocalRotateMatrix();
	XMMATRIX GetLocalScaleMatrix();

	XMMATRIX GetWorldTranslateMatrix();
	XMMATRIX GetWorldRotateMatrix();
	XMMATRIX GetWorldScaleMatrix();

	void SetPositionX(float x) { position_.x = x; }
	void SetPositionY(float y) { position_.y = y; }
	void SetPositionZ(float z) { position_.z = z; }
	void SetPosition(XMFLOAT3 pos) { position_ = pos; }

	void SetRotateX(float x) { rotate_.x = x; }
	void SetRotateY(float y) { rotate_.y = y; }
	void SetRotateZ(float z) { rotate_.z = z; }
	void SetRotate(XMFLOAT3 rotate) { rotate_ = rotate; }

	void SetScaleX(float x) { scale_.x = x; }
	void SetScaleY(float y) { scale_.y = y; }
	void SetScaleZ(float z) { scale_.z = z; }
	void SetScale(XMFLOAT3 scale) { scale_ = scale; }

	void SetParentTransformComponent(std::shared_ptr<TransformComponent> parent);

	static XMFLOAT3 Float3Add(XMFLOAT3 add1, XMFLOAT3 add2)
	{
		return XMFLOAT3(add1.x + add2.x, add1.y + add2.y, add1.z + add2.z);
	}


};

