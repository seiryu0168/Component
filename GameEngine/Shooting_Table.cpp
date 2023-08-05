#include "Shooting_Table.h"
#include"Engine/Systems/ModelSystem.h"
#include"Shooting_TergetGift.h"
Shooting_Table::Shooting_Table(Object* parent)
	:GameObject(parent,"Shooting_Table")
{
}

Shooting_Table::~Shooting_Table()
{
}

void Shooting_Table::Initialize()
{
	transform_->position_ = XMVectorSet(0, 0, 30, 0);
	Test_Model_ECSver model(this);
	model.Load("Assets/Model/Shooting_Table.fbx");
	AddComponent<Test_Model_ECSver>(model);

	for (int i = 0; i<model.GetBoneCount(); i++)
	{
		//台モデルのボーン数に応じて景品を生成
		XMVECTOR ve = model.GetBone(0, i);
		Instantiate<Shooting_TergetGift>(GetParent())->GetTransform()->position_ = model.GetBone(0, i);
	}
}

void Shooting_Table::Release()
{
}
