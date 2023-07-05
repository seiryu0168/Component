#pragma once
#include"Material.h"
#include<vector>
#include"Coordinator.h"
//メッシュクラスとマテリアルクラスをコンポーネントとして置く
//モデルクラスで描画
class Test_Model_ECSver
{
	Entity meshEntity_;
	std::vector<Material> materialList_;

};

