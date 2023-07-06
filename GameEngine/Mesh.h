#pragma once
#include"Engine/DirectX_11/Math.h"
#include<fbxsdk.h>
#include<d3d11.h>
#include<vector>
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
	XMVECTOR normal;//blenderではスムーズシェードにした上でノーマルの自動スムーズを切らないと法線のデータがおかしくなって正しく表示されない
	XMVECTOR tangent;//接線
};

struct Mesh
{
	std::vector<VERTEX> vertices;
	std::vector<UINT32> indices;
	std::string diffuseMap;
	
};

