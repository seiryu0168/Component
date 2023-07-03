#pragma once
#include "Collider.h"


class BoxCollider : public Collider
{
private:
	XMFLOAT3     size_;			//‘å‚«‚³
public:

	BoxCollider();
	BoxCollider(XMFLOAT3 basePos, XMFLOAT3 size);
	~BoxCollider();
	void SetSize(XMFLOAT3 size) { size_ = size; }
	XMFLOAT3 GetSize() { return size_; }
};