#pragma once
#include<unordered_map>
#include<memory>
#include"ComponentArray.h"
#include"ECS.h"

class ComponentManager
{
private:
	//文字列型ポインタからコンポーネント型へのマッピング
	std::unordered_map<const char*, ComponentType> componentTypes_{};
	//文字列型ポインタからコンポーネント配列へのマッピング
	std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays_{};
	//次に登録するコンポーネントのタイプ
	ComponentType nextComponentType_{};

	template <typename T>
	std::shared_ptr<ComponentArray<T>> GetComponentArray()
	{
		//コンポーネント
		const char* typeName = typeid(T).name();
		assert(componentTypes_.find(typeName) != componentTypes_.end()&&"Component not registered before use");
		return std::static_pointer_cast<ComponentArray<T>>(componentArrays_[typeName]);
	}

public:
	template <typename T>
	void RegisterComponent()
	{
		const char* typeName = typeid(T).name();
		//同じコンポーネントタイプがある場合、登録しない
		if (componentTypes_.find(typeName) != componentTypes_.end())
			return;
		assert(componentTypes_.find(typeName) == componentTypes_.end() && "Registaring component type more once");
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
	void AddComponent(Entity entity,T& component)
	{
		GetComponentArray<T>()->InsertData(entity, component);
	}

	template <typename T>
	void RemoveComponent(Entity entity)
	{
		GetComponentArray<T>()->RemoveData(entity);
	}
	void AllRemoveComponent();

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

