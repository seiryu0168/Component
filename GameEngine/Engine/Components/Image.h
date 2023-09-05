#pragma once
#include"../DirectX_11/Sprite.h"
#include<memory>
class Image
{
private:
	std::string imageName_;
	std::shared_ptr<Sprite> pSprite_;
	RECT rect_;
	XMFLOAT4 color_;
	float alpha_;
	XMFLOAT2 scroll_;
	int drawTargetNumber_;
	int layerNum_;
	Transform transform_;
	bool isStatic_;
public:
	Image(int cameraNum = -1,int layerNum=0);
	~Image();
	//画像ロード
	bool Load(const std::string& name, const std::string& tab = "");
	bool StaticLoad(const std::string& name);
	//座標設定
	void SetPosition(const XMFLOAT3& pos);
	//座標設定(ピクセル単位)
	void SetPositionAtPixel(XMFLOAT3 pos);
	//透明度設定
	void SetAlpha(float alpha);
	//色設定
	void SetColor(const float color) noexcept;
	void SetColor(const XMFLOAT3& color) noexcept;
	//画像のスクロール量設定
	void SetScroll(const XMFLOAT2& scroll);
	//画像サイズ設定
	void SetSize(const XMFLOAT3& size);
	//画像回転
	void SetRotation(const XMFLOAT3& rotate);
	//描画対象設定(複数画面時)
	void SetDrawTarget(int targetNum) { drawTargetNumber_ = targetNum; }
	//描画
	void Draw();
	void Draw(int layerNum);

	XMFLOAT3 GetPosition() const { XMFLOAT3 pos; XMStoreFloat3(&pos, transform_.position_); return pos; }

	bool IsHitCursor();
};

