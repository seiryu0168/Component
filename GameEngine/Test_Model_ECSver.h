#pragma once
#include"Material.h"
#include<vector>
#include"Coordinator.h"
#include"Engine/DirectX_11/Fbx.h"
#include"Engine/GameObject/GameObject.h"
//メッシュクラスとマテリアルクラスをコンポーネントとして置く
//モデルクラスで描画
class Test_Model_ECSver
{
private:
	int hModel_;
	SHADER_TYPE type;
	int animationFrame_;
	std::shared_ptr<Fbx> fbx_;
	std::vector<Entity> materialList_;
	Entity meshEntity_;
	GameObject* attachObject_;
public:
	Test_Model_ECSver();
	Test_Model_ECSver(GameObject* object);

	bool Load(std::string fileName);
	void RayCast(RayCastData& rayData);
	void Draw();

};

