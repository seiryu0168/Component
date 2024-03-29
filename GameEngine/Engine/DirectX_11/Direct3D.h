#pragma once
#include <d3d11.h>
#include<assert.h>
#include"Math.h"
#include<vector>
#include"../SAFE_DELETE_RELEASE.h"
using namespace DirectX;

//リンカ
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

enum class SHADER_TYPE
{
	SHADER_2D = 0,
	SHADER_3D,
	SHADER_EFF,
	SHADER_OUTLINE,
	SHADER_TOON,
	SHADER_MAX,
};
enum classTARGET
{
	TARGET_BACK_BUFFER=0,
	TARGET_RENDER_TARGET_1,
	TARGET_RENDER_TARGET_2,
	TARGET_RENDER_TARGET_3,
	TARGET_RENDER_TARGET_MAX
};

enum class BLEND_MODE
{
	BLEND_DEFAULT = 0,
	BLEND_ADD,
	BLEND_MAX
};


namespace Direct3D
{
	enum RENDER_TYPE
	{
		BACK_BUFFER = 0,
		RENDER_TARGET,
		RENDER_MAX
	};
	extern ID3D11Device* pDevice;				//デバイス
	extern ID3D11DeviceContext* pContext;		//デバイスコンテキスト
	

	//extern int screenWidth;
	//extern int screenHeight;
	

	//初期化
	HRESULT Initialize(int winW, int winH, HWND hWnd);

	//シェーダー準備
    HRESULT InitShader();
	HRESULT InitShader2D();
	HRESULT InitShader3D();
	HRESULT InitShaderEFF();
	HRESULT InitShaderOutLine();
	HRESULT InitShaderToon();

	void SetShader(SHADER_TYPE type);
	void SetBlendMode(BLEND_MODE mode);
	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetContext();
	IDXGISwapChain* GetSwapChain();
	void FullScreen(BOOL isFullScreen);
	int GetScreenWidth();
	int GetScreenHeight();
	void SetScreenWidth(int w);
	void SetScreenHeight(int h);
	XMINT2 GetDisplaySize();

	HWND GetWindowHandle(); 
	void SetDepthBufferWriteEnable(bool isWrite);
	int GetViewPortCount();
	void AddViewPort(D3D11_VIEWPORT port);
	void RemoveViewPort(UINT index);
	void SetViewPort(D3D11_VIEWPORT viewPort);
	int GetViewNumber();

	//描画開始
	void BeginDraw();

	//描画終了
	void EndDraw();

	//解放
	void Release();

	
};