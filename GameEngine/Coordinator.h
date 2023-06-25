#pragma once
#include"ComponentManager.h"
#include"EntityManager.h"
#include"SystemManager.h"
#include<unordered_map>
#include<memory>
#include<bitset>
#include"System.h"
using Entity = unsigned int;
const Entity MAX_ENTITIES = 5000;
using ComponentType = unsigned int;
const ComponentType MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;

class Coordinator
{
private:
	std::unique_ptr<ComponentManager> componentManager_;
	std::unique_ptr<EntityManager> entityManager_;
	std::unique_ptr<SystemManager> systemManager_;
public:
	void Init();
	Entity CreateEntity();
	void DestroyEntity(Entity entity);
	template <typename T>
	void RegisterComponent()
	{
		componentManager_->RegisterComponent<T>();

	}

	template <typename T>
	void AddComponent(Entity entity,T component)
	{
		componentManager_->AddComponent<T>(entity, component);
		auto signature = entityManager_->GetSignature(entity);
		signature.set(componentManager_->GetComponentType<T>(), true);
		entityManager_->SetSignature(entity, signature);

		systemManager_->EntitySignatureChanged(entity, signature);

	}

	template <typename T>
	void RemoveComponent(Entity entity)
	{
		componentManager_->RemoveComponent<T>(entity);
		auto signature = entityManager_->GetSignature(entity);
		signature.set(componentManager_->GetComponentType<T>(), false);
		entityManager_->SetSignature(entity, signature);

		systemManager_->EntitySignatureChanged(entity, signature);
	}

	template <typename T>
	T&GetComponent(Entity entity)
	{
		return componentManager_->GetComponent<T>(entity);
	}

	template <typename T>
	ComponentType GetComponentType()
	{
		return componentManager_->GetComponentType<T>();
	}
	template <typename T>
	std::shared_ptr<T> RegisterSystem()
	{
		return systemManager_->RegisterSistem<T>();
	}
	template <typename T>
	void SetSystemSignature(Signature signature)
	{
		systemManager_->SetSignature<T>)(signature);
	}

 };

