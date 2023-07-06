#pragma once
#include"Engine/DirectX_11/Math.h"
#include<fbxsdk.h>
#include<d3d11.h>
#include<vector>
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
	XMVECTOR normal;//blender�ł̓X���[�Y�V�F�[�h�ɂ�����Ńm�[�}���̎����X���[�Y��؂�Ȃ��Ɩ@���̃f�[�^�����������Ȃ��Đ������\������Ȃ�
	XMVECTOR tangent;//�ڐ�
};

struct Mesh
{
	std::vector<VERTEX> vertices;
	std::vector<UINT32> indices;
	std::string diffuseMap;
	
};

