#pragma once
#include"../DirectX_11/Math.h"
#include<memory>
using namespace DirectX;
class Transform
{
	XMMATRIX matTranslate_;	//移動行列
	XMMATRIX matRotate_;	//回転行列	
	XMMATRIX matScale_;	//拡大行列
public:

	XMVECTOR position_;	//位置
	XMVECTOR rotate_;	//向き
	XMFLOAT3 scale_;	//拡大率

	XMVECTOR baseVec_;	//基準となるベクトル

	std::shared_ptr<Transform> pParent_;//親の情報

	//コンストラクタ
	Transform();

	//デストラクタ
	~Transform();

	//各行列の計算
	void Calclation();
	//回転
	void RotateAxis(XMVECTOR axis, float angle);
	void RotateEular(XMFLOAT3 rotation);

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

	static XMFLOAT3 Float3Add(XMFLOAT3 add1, XMFLOAT3 add2)
	{
		return XMFLOAT3(add1.x + add2.x, add1.y + add2.y, add1.z + add2.z);
	}
};

