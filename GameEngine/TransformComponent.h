#pragma once
#include"Component.h"
#include<memory>
#include"Engine/DirectX_11/Math.h"
class TransformComponent : public Component
{
private:
	XMVECTOR RotationQuaternion_;

	XMMATRIX matTranslate_;	//移動行列
	XMMATRIX matRotate_;	//回転行列	
	XMMATRIX matScale_;	//拡大行列
public:
	XMFLOAT3 position_;	//位置
	XMFLOAT3 rotate_;	//向き
	XMFLOAT3 scale_;	//拡大率
	XMVECTOR baseVec_;	//基準となるベクトル
		
	std::shared_ptr<TransformComponent> pParent_;//親の情報
	
	TransformComponent(Object* atcObj);
	TransformComponent();
	~TransformComponent();

	//各行列の計算
	void Calclation();

	//回転行列と拡縮の逆行列の計算
	XMMATRIX GetNormalMatrix();

	//ワールド行列を取得
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

