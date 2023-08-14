#include "Shooting_Table.h"
#include"Engine/Systems/ModelSystem.h"
#include"Shooting_TergetGift.h"
#include"Engine/ResourceManager/json.hpp"
#include"Engine/Systems/ColliderSystem.h"
#include<fstream>

namespace
{
	const std::string TARGET_DATA_FILENAME = "Assets/GameDatas/ShootingDatas/TargetData.json";
}
Shooting_Table::Shooting_Table(Object* parent)
	:GameObject(parent, "Shooting_Table")
{
}

Shooting_Table::~Shooting_Table()
{
}

void Shooting_Table::Initialize()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<int> rand5(0, 2);
	
	transform_->position_ = XMVectorSet(0, 0, 30, 0);
	Test_Model_ECSver model(this);
	model.Load("Assets/Model/Shooting_Table.fbx");
	AddComponent<Test_Model_ECSver>(model);

	nlohmann::json jsonReader;
	std::ifstream ifs(TARGET_DATA_FILENAME);
	int i = 0;
	jsonReader = nlohmann::json::parse(ifs);
	for (i; i<model.GetBoneCount(); i++)
	{
		//台モデルのボーン数に応じて景品を生成
		XMVECTOR ve = model.GetBone(0, i);
		int targetNum = rand5(mt);
		//オブジェクト生成
		Shooting_TergetGift* gift = Instantiate<Shooting_TergetGift>(GetParent());
		//乱数によるモデル読み込み
		Test_Model_ECSver mdl(gift);
		mdl.Load(jsonReader["Shooting_TargetModel"][targetNum]["ModelName"]);
		gift->AddComponent<Test_Model_ECSver>(mdl);
		//当たり判定設定
		XMFLOAT3 colSize = {};
		colSize.x = jsonReader["Shooting_TargetModel"][targetNum]["CollisionSize"][0];
		colSize.y = jsonReader["Shooting_TargetModel"][targetNum]["CollisionSize"][1];
		colSize.z = jsonReader["Shooting_TargetModel"][targetNum]["CollisionSize"][2];
		HitBox box({ colSize.x, colSize.y, colSize.z });
		Collider col({0,0,0}, box);
		col.SetAttachObject(gift);
		gift->AddComponent<Collider>(col);
		//オブジェクトの位置設定
		//gift->GetTransform()->scale_ = colSize;
		gift->GetTransform()->position_ = model.GetBone(0, i) + XMVectorSet(0, colSize.y, 0, 0);
		gift->SetScore(i+1);
	}
}

void Shooting_Table::Load(const std::string& fileName)
{

	//for (auto& elem : jsonReader["Shooting_TargetModel"])
	//{
	//	elem["ModelName"]
	//}

}

void Shooting_Table::Release()
{
}
