#pragma once
#include<unordered_map>
#include<memory.h>
#include"Engine/DirectX_11/Fbx.h"
#include"Engine/DirectX_11/Texture.h"
#include"Engine/GameObject/Transform.h"
namespace ModelManager_ECSver
{
	std::shared_ptr<Fbx> Load(std::string fileName);
	//void SetTransform(int modelNum, Transform transform);
	//void Draw(int modelNum);
	//void RayCast(int modelNum, RayCastData& ray);
};

