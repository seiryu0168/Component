#pragma once
#include"../DirectX_11/Material.h"
#include<vector>
#include"../Coordinator.h"
#include"../DirectX_11/Fbx.h"
#include"../GameObject/GameObject.h"

//���b�V���N���X�ƃ}�e���A���N���X���R���|�[�l���g�Ƃ��Ēu��
//���f���N���X�ŕ`��
class Test_Model_ECSver// : public Draw3DComponent
{
private:
	int hModel_;
	SHADER_TYPE type_;
	int animationFrame_;
	std::shared_ptr<Fbx> fbx_;
	std::vector<Entity> materialList_;
	Entity meshEntity_;
	GameObject* attachObject_;
public:
	Test_Model_ECSver();
	Test_Model_ECSver(GameObject* object);

	//���f���̃��[�h
	bool Load(const std::string& fileName);
	//���C�L���X�g(������)
	void RayCast(RayCastData& rayData);
	//�V�F�[�_�[�^�C�v�ݒ�
	void SetShaderType(SHADER_TYPE type) { type_ = type; }
	//�A�^�b�`����Ă���I�u�W�F�N�g��Ԃ�
	GameObject* GetAttachedObject() { return attachObject_; }
	//�`��
	void Draw();

};

