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

	int i = 0;
	for (i; i<model.GetBoneCount(); i++)
	{
		//台モデルのボーン数に応じて景品を生成
		XMVECTOR ve = model.GetBone(0, i);
		Shooting_TergetGift* gift = Instantiate<Shooting_TergetGift>(GetParent());
		gift->GetTransform()->position_ = model.GetBone(0, i);
		gift->SetScore(i+1);
	}
}

void Shooting_Table::Release()
{
}
