#pragma once
#include<unordered_map>
#include<memory.h>
#include"Engine/DirectX_11/Fbx.h"
#include"Engine/DirectX_11/Texture.h"
#include"Engine/GameObject/Transform.h"
namespace ModelManager_ECSver
{
	std::shared_ptr<Fbx> Load(const std::string& fileName);
	void Release();
};

