#pragma once
#include<unordered_map>
#include<memory>
#include"Engine/DirectX_11/Sprite.h"
namespace ImageManager_ECSver
{
	std::shared_ptr<Sprite> Load(std::string fileName);
	void Release();
};

