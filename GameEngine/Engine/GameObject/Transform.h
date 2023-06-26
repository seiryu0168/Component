#pragma once
#include"../DirectX_11/Math.h"
#include<memory>
using namespace DirectX;
class Transform
{
	XMMATRIX matTranslate_;	//�ړ��s��
	XMMATRIX matRotate_;	//��]�s��	
	XMMATRIX matScale_;	//�g��s��
public:

	XMVECTOR position_;	//�ʒu
	XMVECTOR rotate_;	//����
	XMFLOAT3 scale_;	//�g�嗦

	XMVECTOR baseVec_;	//��ƂȂ�x�N�g��

	std::shared_ptr<Transform> pParent_;//�e�̏��

	//�R���X�g���N�^
	Transform();

	//�f�X�g���N�^
	~Transform();

	//�e�s��̌v�Z
	void Calclation();
	//��]
	void RotateAxis(XMVECTOR axis, float angle);
	void RotateEular(XMFLOAT3 rotation);

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

	static XMFLOAT3 Float3Add(XMFLOAT3 add1, XMFLOAT3 add2)
	{
		return XMFLOAT3(add1.x + add2.x, add1.y + add2.y, add1.z + add2.z);
	}
};

