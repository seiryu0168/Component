#pragma once
#include <dInput.h>
#include"Direct3D.h"
#include"XInput.h"
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dInput8.lib")
#pragma comment(lib,"Xinput.lib")
#include"../SAFE_DELETE_RELEASE.h"

namespace Input
{
	void Initialize(HWND hWnd);
	void Update();
	int GetConectedControllerCount();
	//キーボード
	bool IsKey(int keyCode);
	bool IsKeyDown(int keyCode);
	bool IsKeyUp(int keyCode);

	//マウス
	bool IsMouseButton(int buttonCode);
	bool IsMouseButtonDown(int buttonCode);
	bool IsMouseButtonUp(int buttonCode);

	//コントローラー
	bool IsPadAnyButton(int padID = 0);
	bool IsPadAnyButtonDown(int padID = 0);
	bool IsPadAnyButtonUp(int padID = 0);
	bool IsPadButton(int buttonCode,int padID = 0);
	bool IsPadButtonDown(int buttonCode, int padID = 0);
	bool IsPadButtonUp(int buttonCode, int padID = 0);

	float GetLStick_X(int padID = 0);
	float GetLStick_Y(int padID = 0);
	float GetRStick_X(int padID = 0);
	float GetRStick_Y(int padID = 0);



	float GetLTrigger(int padID = 0);
	float GetLTriggerDown(int padID = 0);
	float GetLTriggerUp(int padID = 0);

	float GetRTrigger(int padID = 0);
	float GetRTriggerDown(int padID = 0);
	float GetRTriggerUp(int padID = 0);

	XMVECTOR GetMousePosition();
	XMVECTOR GetMouseMove();
	void SetMousePosition(int x, int y);
	void Release();

}