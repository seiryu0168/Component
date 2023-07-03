#pragma once
#include "Collider.h"


class BoxCollider : public Collider
{
	//Collider�N���X�ɃA�N�Z�X�ł���悤�ɂ���
	//friend class Collider;

private:
	XMFLOAT3     size_;			//�傫��
public:

	BoxCollider();
	BoxCollider(XMFLOAT3 basePos, XMFLOAT3 size);
	~BoxCollider();
	void SetSize(XMFLOAT3 size) { size_ = size; }
	XMFLOAT3 GetSize() { return size_; }
};