#pragma once
#include<d3d11.h>
#include"Engine\DirectX_11\Texture.h"
#include"Engine/DirectX_11/Math.h"
class Material
{
private:
	std::string materialName_;
	Texture* pTexture_;    //テクスチャ
	Texture* pNormalMap_;  //ノーマルマップ
	XMFLOAT4 diffuse_;	  //ディフューズ(マテリアルの色)
	XMFLOAT4 ambient_;	  //アンビエント
	XMFLOAT4 speculer_;    //スペキュラー(ツルツルを表現する奴)
	float shininess_;	  //ハイライトの強さ

public:
	Material();
	~Material();
	//////////////////セッター/////////////////////
	void SetMaterialName(std::string name);
	void SetTexture(Texture* tex);
	void SetNormalMap(Texture* nmlMap);
	void SetDiffuse(XMFLOAT4 diff);
	void SetAmbient(XMFLOAT4 amb);
	void SetSpeculer(XMFLOAT4 spec);
	void SetShininess(float shin);

	//////////////////ゲッター/////////////////////
	const Texture* GetTexture() { return pTexture_; }
	const Texture* GetNormalMap() { return pNormalMap_; }
	const XMFLOAT4& GetDiffuse() { return diffuse_; }
	const XMFLOAT4& GetAmbient() { return ambient_; }
	const XMFLOAT4& GetSpeculer() { return speculer_; }
	const float& GetShininess() { return shininess_; }
};

