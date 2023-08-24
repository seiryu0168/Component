#pragma once
#include"../DirectX_11/Material.h"
#include<vector>
#include"../Coordinator.h"
#include"../DirectX_11/Fbx.h"
#include"../GameObject/GameObject.h"

//メッシュクラスとマテリアルクラスをコンポーネントとして置く
//モデルクラスで描画
class Test_Model_ECSver// : public Draw3DComponent
{
private:
	bool isDraw_;
	SHADER_TYPE type_;
	int animationFrame_;
	std::shared_ptr<Fbx> fbx_;
	std::vector<Entity> materialList_;
	Entity meshEntity_;
	GameObject* attachObject_;

	int layerNum_;
public:
	Test_Model_ECSver();
	Test_Model_ECSver(GameObject* object, int layerNum = 0);

	//モデルのロード
	bool Load(const std::string& fileName);

	//レイキャスト(未検証)
	void RayCast(RayCastData& rayData);

	//シェーダータイプ設定
	void SetShaderType(SHADER_TYPE type) { type_ = type; }

	const XMVECTOR& GetBone(const std::string& boneName);
	const XMVECTOR& GetBone(const UINT& partsNum,const UINT& num);
	const UINT& GetBoneCount();
	const bool& IsDraw() { return isDraw_; }
	void SetDraw(bool isDraw) { isDraw_ = isDraw; }
	void SetCustomColor(int partsNum,int materialNum,const XMFLOAT4& color);
	//アタッチされているオブジェクトを返す
	GameObject* GetAttachedObject() { return attachObject_; }
	//描画
	void Draw();
	void Draw(int layerNum);

};

