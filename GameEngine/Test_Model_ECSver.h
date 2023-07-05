#pragma once
#include"Material.h"
#include<vector>
#include"Coordinator.h"
#include"Engine/DirectX_11/Fbx.h"
#include"Engine/GameObject/GameObject.h"
//���b�V���N���X�ƃ}�e���A���N���X���R���|�[�l���g�Ƃ��Ēu��
//���f���N���X�ŕ`��
class Test_Model_ECSver
{
private:
	//Fbx* mesh_;
	int hModel_;
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

