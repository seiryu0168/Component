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
	std::unordered_map<const char*, ComponentType> componentTypes{};
	std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays{};
	ComponentType nextComponentType{};

	template <typename T>
	std::shared_ptr<ComponentArray<T>> GetComponentArray()
	{
		const char* typeName = typeid(T).name();
		assert(componentTypes.find(typeName) != componentTypes.end()&&"Component not registered before use");
		return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeName]);
	}

public:
	template <typename T>
	void RegisterComponent()
	{
		const chat* typeName = typeid(T).name();
		assert(componenTypes.find(typeName) == componentTypes.end() && "Registaring component type more once");
		componentTypes.insert({ typeName,nextComponentType });
		componentArrays.insert({ typeName, std::make_shared<ComponentArray<T>>()});
		++nextComponentType;
	}

	template <typename T>
	ComponentType GetComponent()
	{
		const char* typeName = typeid(T).name();
		assert(componentTypes.find(typeName) != componentTypes.end()&&"Component not registered before use");

		return componentTypes[typeName];
	}

	template <typename T>
	void AddComponent(Entity entity,T component)
	{
		GetComponentArray<T>()->InsertData(entity, component);
	}

};

