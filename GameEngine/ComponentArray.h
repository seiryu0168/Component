#pragma once
#include"IComponentArray.h"
#include<unordered_map>
template<typename T>
class ComponentArray : public IComponentArray
{
private:
	//�R���|�[�l���g�̔z��(MAX_ENTITIES���z��̒���)
	std::array<T, MAX_ENTITIES> componentArray_;
	
	//�G���e�B�e�B�ƃC���f�b�N�X�͂��݂��̒l���z��̂ǂ��ɂ��邩��l�Ƃ��ĕێ����Ă���
	//�G���e�B�e�B����z��̃C���f�b�N�X��	�}�b�s���O
	std::unordered_map<Entity, size_t> entityToIndexMap_;
	//�C���f�b�N�X����G���e�B�e�B�̃}�b�s���O
	std::unordered_map<size_t, Entity> indexToEntityMap_;
	//�z����̗L���ȃG���e�B�e�B�̑���
	size_t size_;
public:
	void InsertData(Entity entity, T component) 
	{
		//�����G���e�B�e�B�ɕ����̃R���|�[�l���g���ǉ�����Ă͂����Ȃ�
		assert(entityToIndexMap_.find(entity) == entityToIndexMap_.end() && "Component added to same entity more than once");

		//�G���e�B�e�B�ƃC���f�b�N�X�̔z��ɂ��ꂼ��}�b�s���O���A�R���|�[�l���g�̔z��ɒǉ�����
		size_t newIndex = size_;
		entityToIndexMap_[entity] = newIndex;
		indexToEntityMap_[newIndex] = entity;
		componentArray_[newIndex] = component;
		++size;
	}
	void RemoveData(Entity entity)
	{
		assert(entityToIndexMap_.find(entity) != entityToIndexMap_.end() && "Removing non-existent component");

		//�����̗v�f���폜����v�f�̏ꏊ�ɃR�s�[
		//���������R���|�[�l���g�̃C���f�b�N�X
		size_t indexOfRemovedEntity = entityToIndexMap_[entity];
		//�����̃C���f�b�N�X
		size_t indexOfLastElement = size_ - 1;
		//�����\��̏ꏊ�ɖ����̒l����
		componentArray_[indexOfRemovedEntity] = componentArray_[indexOfLastElement];

		//�G���e�B�e�B�z��̖����̒l
		Entity entityOflastElement = indexToEntityMap_[indexOfLastElement];
		//�G���e�B�e�B�z�񖖔��̒l(�C���f�b�N�X)�����������G���e�B�e�B�̃C���f�b�N�X�ɏ���������
		entityToIndexMap_[entityOflastElement] = indexOfRemovedEntity;
		//�C���f�b�N�X�z����̏����l�𖖔��̗v�f�ŏ���������
		indexToEntityMap_[indexOfRemovedEntity] = entityOflastElement;
		//�G���e�B�e�B�z�񂩂����
		entityToIndexMap_.erase(entity);
		//�C���f�b�N�X�z�񂩂�Ō�̒l������
		indexToEntityMap_.erase(indexOfLastElement);
		//�L���ȃG���e�B�e�B������炷
		--size_;
	}
	T& GetData(Entity entity)
	{
		assert(entityToIndexMap.find(entity) != entityToIndexMap_.end() && "Retrieving non-existent component");
		return componentArray_[entityToIndexMap_[entity]];
	}
	void EntityDestroyed(Entity entity) override
	{
		if (entityToIndexMap_.find(entity) != entityToIndexMap_.end())
			RemoveData(entity);
	}


};
