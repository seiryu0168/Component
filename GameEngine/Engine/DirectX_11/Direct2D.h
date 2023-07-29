#pragma once
#include"../DirectX_11/Direct3D.h"
#include<d2d1.h>
#include<dwrite_3.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib,"dwrite.lib")
enum STARTING_TYPE
{
	LEFT_TOP = 0,
	LEFT_CENTER,
	LEFT_BOTTOM,
	CENTER_TOP,
	CENTER_CENTER,
	CENTER_BOTTOM,
	RIGHT_TOP,
	RIGHT_CENTER,
	RIGHT_BOTTOM,
};

namespace D2D
{
	
	extern ID2D1Factory* pFactory_;
	extern ID2D1RenderTarget* pRenderTarget_;
	extern IDWriteFontSetBuilder1* pFontSetBuilder_;

	HRESULT Initialize(int winW, int winH, HWND hWnd);
	HRESULT CreateFontCollection();
	IDWriteFontCollection* GetSystemFontCollection();
	ID2D1Factory* Get2DFactory();
	IDWriteFactory5* GetDWriteFactory();
	IDWriteFontCollection1* GetCollection();
	ID2D1RenderTarget* GetRenderTarget();
	void Release();
	void RenderTest();
	void BeginDraw();
	void EndDraw();
	int  GetdpiX();
	int  GetdpiY();

};

