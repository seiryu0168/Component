#include "CameraManager.h"


//変数
XMVECTOR position_;			//カメラの位置（視点）
XMVECTOR target_;			//見る位置（焦点）
XMVECTOR upVector_;			//上ベクトル
XMMATRIX viewMatrix_;		//ビュー行列
XMMATRIX projMatrix_;		//プロジェクション行列
XMMATRIX billBoardMatrix_;	//ビルボード行列
float	 angleOfView;		//視野角
float	 aspectRadio;		//アスペクト比
float	 nearClipping;		//ニアクリッピング
float	 farClipping;		//ファークリッピング

namespace CameraManager
{
	std::vector<Camera> cameraList_;
	float screenWidth_;
	float screenHeight_;
	int currentViewPort_;

	Camera defaultCamera_;
}

//初期化
void CameraManager::Initialize(float width,float height)
{
	screenWidth_ = width;
	screenHeight_ = height;
	
	
	position_ = XMVectorSet(0, 10, -40, 0);	//カメラの位置
	target_ = XMVectorSet(0, 0, 0, 0);	//カメラの焦点
	upVector_ = XMVectorSet(0, 1, 0, 0);
	angleOfView = XM_PIDIV4;
	aspectRadio = (FLOAT)width / (FLOAT)height;
	nearClipping = 0.1f;
	farClipping = 1000.0f;
	// プロジェクション行列
	//projMatrix_ = XMMatrixPerspectiveFovLH(XM_PIDIV4, (FLOAT)width / (FLOAT)height, 0.1f, 1000.0f);
	defaultCamera_.Initialize(width, height, nearClipping, farClipping);
	defaultCamera_.SetPosition(position_);
	//defaultCamera_.SetTarget(target_);
	//defaultCamera_.SetAOV(angleOfView);
	//defaultCamera_.SetAspectRadio(aspectRadio);
	defaultCamera_.SetViewPort(width, height, 0.0f, 1.0f, 0, 0);
	cameraList_.push_back(defaultCamera_);
}

//更新
void CameraManager::Update()
{
	for (Camera& camera : cameraList_)
	{
		camera.Update();
	}

	////ビュー行列の作成
	//viewMatrix_ = XMMatrixLookAtLH(position_, target_, upVector_);
	//
	//billBoardMatrix_ = XMMatrixLookAtLH(XMVectorSet(0, 0, 0, 0), target_ - position_, upVector_);
	//billBoardMatrix_ = XMMatrixInverse(nullptr, billBoardMatrix_);
}

void CameraManager::CreateCamera(XMFLOAT3 pos, XMFLOAT3 target, float aov, float width, float height, float nearClipping, float farClipping)
{
	Camera camera;
	camera.Initialize(width, height, nearClipping, farClipping);
	camera.SetPosition(XMLoadFloat3(&pos));
	camera.SetTarget(XMLoadFloat3(&target));
	camera.SetAOV(aov);

	cameraList_.push_back(camera);
	//position_ = XMVectorSet(0, 10, -40, 0);	//カメラの位置
	//target_ = XMVectorSet(0, 0, 0, 0);	//カメラの焦点
	//upVector_ = XMVectorSet(0, 1, 0, 0);
	//angleOfView = XM_PIDIV4;
	//aspectRadio = (FLOAT)width / (FLOAT)height;
	//nearClipping = 0.1f;
	//farClipping = 1000.0f;
	//// プロジェクション行列
	//projMatrix_ = XMMatrixPerspectiveFovLH(XM_PIDIV4, (FLOAT)width / (FLOAT)height, 0.1f, 1000.0f);
}

Camera& CameraManager::GetCamera(UINT num)
{
	if (num >= cameraList_.size())
		num = cameraList_.size() - 1;

		currentViewPort_ = num;
		return cameraList_[num];
}

Camera& CameraManager::GetCurrentCamera()
{
	return cameraList_[currentViewPort_];
	// TODO: return ステートメントをここに挿入します
}

void CameraManager::AddCamera(Camera camera)
{
	cameraList_.push_back(camera);
}

void CameraManager::AllRmoveCamera(UINT num)
{
	cameraList_.clear();
}

void CameraManager::ResetCamera()
{
	cameraList_.clear();
	cameraList_.push_back(defaultCamera_);
}

UINT CameraManager::GetCameraCount()
{
	return (UINT)cameraList_.size();
}

////位置を設定
//void CameraManager::SetPosition(XMVECTOR position)
//{
//	position_ = position;
//}
//
////焦点を設定
//void CameraManager::SetTarget(XMVECTOR target)
//{
//	target_ = target;
//}
//
//void CameraManager::SetUpVector(XMVECTOR upVector)
//{
//	upVector_ = upVector;
//}
//
//void CameraManager::SetProjection(float aov, float aspectRadio, float nearZ, float farZ)
//{
//	projMatrix_ = XMMatrixPerspectiveFovLH(aov, aspectRadio, nearZ, farZ);
//}
//
//void CameraManager::SetAOV(float aov)
//{
//	projMatrix_ = XMMatrixPerspectiveFovLH(aov, aspectRadio, nearClipping, farClipping);
//}
//
//void CameraManager::SetAspectRadio(float aspect)
//{
//	projMatrix_ = XMMatrixPerspectiveFovLH(angleOfView, aspect, nearClipping, farClipping);
//}
//
//void CameraManager::SetClipping(float nearZ, float farZ)
//{
//	projMatrix_ = XMMatrixPerspectiveFovLH(angleOfView, aspectRadio, nearZ, farZ);
//}
//
//
////視点(カメラの位置)を取得
//XMFLOAT3 CameraManager::GetPosition()
//{
//	return StoreFloat3(position_);
//}
//XMVECTOR CameraManager::GetTarget()
//{
//	return target_;
//}
////ビュー行列を取得
//XMMATRIX CameraManager::GetViewMatrix()
//{
//	return viewMatrix_;
//}
//
//XMMATRIX CameraManager::GetBillBoardMatrix()
//{
//	return billBoardMatrix_;
//}
////プロジェクション行列を取得
//XMMATRIX CameraManager::GetProjectionMatrix()
//{
//	return projMatrix_;
//}