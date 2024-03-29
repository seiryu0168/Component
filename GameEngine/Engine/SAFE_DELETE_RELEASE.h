#pragma once
#include<DirectXMath.h>
using namespace DirectX;
#define SAFE_DELETE(p) if(p != nullptr){delete p;p=nullptr;}
#define SAFE_DELETE_ARRAY(p) if (p != nullptr) {delete[] p;p = nullptr;}
#define SAFE_RELEASE_DELETE(p)if(p!=nullptr){p->Release();delete p;p=nullptr;}
#define SAFE_RELEASE(p) if(p != nullptr){ p->Release(); p = nullptr;}