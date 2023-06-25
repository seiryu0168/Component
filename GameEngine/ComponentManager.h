#pragma once
#include<unordered_map>
#include<memory>
#include"ComponentArray.h"
using Entity = unsigned int;
const Entity MAX_ENTITIES = 5000;
using ComponentType = unsigned int;
const ComponentType MAX_COMPONENTS = 32;

class ComponentManager
{
private:
	//������^�|�C���^����R���|�[�l���g�^�ւ̃}�b�s���O
	std::unordered_map<const char*, ComponentType> componentTypes_{};
	//������^�|�C���^����R���|�[�l���g�z��ւ̃}�b�s���O
	std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays_{};
	//���ɓo�^����R���|�[�l���g�̃^�C�v
	ComponentType nextComponentType_{};

	template <typename T>
	std::shared_ptr<ComponentArray<T>> GetComponentArray()
	{
		//�R���|�[�l���g
		const char* typeName = typeid(T).name();
		assert(componentTypes_.find(typeName) != componentTypes_.end()&&"Component not registered before use");
		return std::static_pointer_cast<ComponentArray<T>>(componentArrays_[typeName]);
	}

public:
	template <typename T>
	void RegisterComponent()
	{
		const chat* typeName = typeid(T).name();
		assert(componenTypes.find(typeName) == componentTypes_.end() && "Registaring component type more once");
		componentTypes_.insert({ typeName,nextComponentType_ });
		componentArrays_.insert({ typeName, std::make_shared<ComponentArray<T>>()});
		++nextComponentType_;
	}

	template <typename T>
	ComponentType GetComponentType()
	{
		const char* typeName = typeid(T).name();
		assert(componentTypes_.find(typeName) != componentTypes_.end() && "Component not registered before use");
		return componentTypes_[typeName];
	
	}
	template <typename T>
	ComponentType GetComponent()
	{
		const char* typeName = typeid(T).name();
		assert(componentTypes_.find(typeName) != componentTypes_.end()&&"Component not registered before use");

		return componentTypes_[typeName];
	}

	template <typename T>
	void AddComponent(Entity entity,T component)
	{
		GetComponentArray<T>()->InsertData(entity, component);

	}

	template <typename T>
	void RemoveComponent(Entity entity)
	{
		GetComponentArray<T>()->RmoveData(entity);
	}

	template <typename T>
	T& GetComponent(Entity entity)
	{
		return GetComponentArray<T>()->GetData(entity);
	}

	void EntityDestroyed(Entity entity)
	{
		for (auto const& pair : componentArrays_)
		{
			auto const& component = pair.second;
			component->EntityDestroyed(entity);
		}
	}
};

