#pragma once
#include"IComponentArray.h"
#include<unordered_map>
template<class T>
class ComponentArray : public IComponentArray
{
private:
	//�R���|�[�l���g�̔z��(MAX_ENTITIES���z��̒���)
	std::array<T, MAX_ENTITIES> componentArray_;
	//�G���e�B�e�B����z��̃C���f�b�N�X�̃}�b�s���O
	std::unordered_map<Entity, size_t> entityToIndexMap_;
	//�C���f�b�N�X����G���e�B�e�B�̃}�b�s���O
	std::unordered_map<size_t, Entity> indexToEntityMap_;
	//�z����̗L���ȃG���e�B�e�B�̑���
	size_t size_;
public:
	void InsertData(Entity entity, T component);
	void RemoveData(Entity entity);
	T& GetData(Entity entity);
	void EntityDestroyed(Entity entity) override;


};

