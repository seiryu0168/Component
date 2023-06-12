#pragma once
#include<d3d11.h>
#include"Engine\DirectX_11\Texture.h"
#include"Engine/DirectX_11/Math.h"
class Material
{
private:
	std::string materialName_;
	Texture* pTexture_;    //�e�N�X�`��
	Texture* pNormalMap_;  //�m�[�}���}�b�v
	XMFLOAT4 diffuse_;	  //�f�B�t���[�Y(�}�e���A���̐F)
	XMFLOAT4 ambient_;	  //�A���r�G���g
	XMFLOAT4 speculer_;    //�X�y�L�����[(�c���c����\������z)
	float shininess_;	  //�n�C���C�g�̋���

public:
	Material();
	~Material();
	//////////////////�Z�b�^�[/////////////////////
	void SetMaterialName(std::string name);
	void SetTexture(Texture* tex);
	void SetNormalMap(Texture* nmlMap);
	void SetDiffuse(XMFLOAT4 diff);
	void SetAmbient(XMFLOAT4 amb);
	void SetSpeculer(XMFLOAT4 spec);
	void SetShininess(float shin);

	//////////////////�Q�b�^�[/////////////////////
	const Texture* GetTexture() { return pTexture_; }
	const Texture* GetNormalMap() { return pNormalMap_; }
	const XMFLOAT4& GetDiffuse() { return diffuse_; }
	const XMFLOAT4& GetAmbient() { return ambient_; }
	const XMFLOAT4& GetSpeculer() { return speculer_; }
	const float& GetShininess() { return shininess_; }
};

