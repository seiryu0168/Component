#pragma once
#include"Direct3D.h"
#include"Texture.h"
#include"DirectXMath.h"
#include"../GameObject/GameObject.h"
#include<list>

struct LineData
{
	float width;
	float endWidth;
	int   length;
	std::string textureName;
	LineData()
	{
		width = 0.5f;
		endWidth = 0.0f;
		length = 10;
		textureName = "Effect01.png";
	}

};
class LineParticle
{
	enum class LineMode
	{
		LINE_DEFAULT=0,
		LINE_CROSS,
	};

private:
	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWVP;
		XMFLOAT4	color;
	};

	//頂点情報
	struct VERTEX
	{
		XMFLOAT3 position;
		XMFLOAT3 uv;
	};

	float WIDTH_;//ラインパーティクルの幅
	UINT LENGTH_;//ラインパーティクルのポジションを記憶する量
	float endWidth_;
	XMFLOAT4 color_;
	//int* index_;

	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer* pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;

	Texture* pTexture_;
	std::vector<int> indexList;
	std::list<XMFLOAT3> positionList_;
	GameObject* attachObject_;
public:
	LineParticle();
	LineParticle(GameObject* object);
	/// <summary>
	/// ラインの位置保存
	/// 位置をポジションリストに追加
	/// </summary>
	/// <param name="pos">この関数が呼ばれた時の位置</param>
	void AddPosition(XMFLOAT3 pos);
	/// <summary>
	/// パイプ状のラインパーティクル生成
	/// </summary>
	/// <param name="pList"></param>
	/// <returns></returns>
	HRESULT CreateMeshPype(std::list<XMFLOAT3>* pList);
	HRESULT CreateMeshPlate(std::list<XMFLOAT3>* pList);
	/// <summary>
	/// ラインパーティクルに使う画像のロード
	/// </summary>
	/// <param name="fileName"></param>
	/// <returns></returns>
	HRESULT Load(std::string fileName);
	/// <summary>
	/// ラインパーティクルの色設定
	/// </summary>
	/// <param name="col">色</param>
	void SetColor(XMFLOAT4 col);
	/// <summary>
	/// インデックス生成
	/// </summary>
	void SetIndex();

	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	/// <summary>
	/// ラインパーティクルの各パラメータ設定
	/// </summary>
	/// <param name="width">横幅</param>
	/// <param name="length">ポジションの保存数</param>
	/// <param name="tipWidth">終端の幅</param>
	void SetLineParameter(LineData data);
	void SetWidth(float width);
	void SetEndWidth(float endWidth);
	void SetLength(float length);
	/// <summary>
	/// ポジションリストの削除
	/// </summary>
	void DeleteLine();
	void Release();



};

