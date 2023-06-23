#pragma once
#include<bitset>
#include<queue>
#include<array>
using Entity = unsigned int;
const Entity MAX_ENTITIES = 5000;
using Component = unsigned int;
const Component MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;

class EntityManager
{
private:
	//�g�p�\�ȃG���e�B�e�B�̃L���[
	std::queue<Entity> availableEntites_{};
	//�G���e�B�e�B�ŊǗ������V�O�l�`���̔z��
	std::array<Signature, MAX_ENTITIES> signatures_{};
	//���g�p���Ă�G���e�B�e�B�̐�
	unsigned int livingEntityCount_{};
public:
	EntityManager();
	~EntityManager();

	Entity CreateEntity();
	void DestroyEntity(Entity entity);
	void SetSignature(Entity entity, Signature signature);
	Signature GetSignature(Entity entity);

};

