#include "Material.h"
#include"Engine/SAFE_DELETE_RELEASE.h"
Material::Material()
	:pTexture_(nullptr),
	pNormalMap_(nullptr),
	diffuse_({0,0,0,0}),
	ambient_({0,0,0,0}),
	speculer_({0,0,0,0}),
	shininess_(0)
{
}

Material::~Material()
{
	SAFE_RELEASE_DELETE(pTexture_);
	SAFE_RELEASE_DELETE(pNormalMap_);
}

void Material::SetMaterialName(std::string name)
{
	materialName_ = name;
}

void Material::SetTexture(Texture* tex)
{
	if (pTexture_ != nullptr)
		SAFE_RELEASE_DELETE(pTexture_);
	pTexture_ = tex;
}

void Material::SetNormalMap(Texture* nmlMap)
{
	pNormalMap_ = nmlMap;
}

void Material::SetDiffuse(XMFLOAT4 diff)
{
	diffuse_=diff;
}

void Material::SetAmbient(XMFLOAT4 amb)
{
	ambient_ = amb;
}

void Material::SetSpeculer(XMFLOAT4 spec)
{
	speculer_ = spec;
}

void Material::SetShininess(float shin)
{
	shininess_ = shin;
}