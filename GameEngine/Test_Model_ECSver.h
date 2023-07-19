#pragma once
#include"Material.h"
#include<vector>
#include"Coordinator.h"
#include"Engine/DirectX_11/Fbx.h"
#include"Engine/GameObject/GameObject.h"

//���b�V���N���X�ƃ}�e���A���N���X���R���|�[�l���g�Ƃ��Ēu��
//���f���N���X�ŕ`��
class Test_Model_ECSver// : public Draw3DComponent
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
	//Test_Model_ECSver(const Test_Model_ECSver& object);




	bool Load(std::string fileName);
	void RayCast(RayCastData& rayData);
	void Draw();

};

