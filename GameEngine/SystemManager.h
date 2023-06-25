#pragma once
#include<unordered_map>
#include<memory>
#include<bitset>
#include"ECS.h"
#include"System.h"
//using Entity = unsigned int;
//const Entity MAX_ENTITIES = 5000;
//using ComponentType = unsigned int;
//const ComponentType MAX_COMPONENTS = 32;
//using Signature = std::bitset<MAX_COMPONENTS>;

class SystemManager
{
private:
	//システム型の文字列ポインタからシグネチャへのマップ
	std::unordered_map<const char*, Signature> signatures_{};
	//システム型の文字列ポインタからシステムポインタへのマップ
	std::unordered_map<const char*, std::shared_ptr<System>> systems_{};

public:
	template <typename T>
	std::shared_ptr<T> RegisterSistem()
	{
		const char* typeName = typeid(T).name();
		//システムが今まで追加したのと同じもの
		/*if (systems_.find(typeName) != systems_.end())
		{
			auto systm = systems_.find(typeName);

			return systm;
		}*/
		assert(systems_.find(typeName) == systems_.end() && "Registering system more than once");
		//システムのポインタを作成し、外部で使うために返す
		auto system = std::make_shared<T>();
		systems_.insert({ typeName,system });
		return system;
	}

	template <typename T>
	void SetSignature(Signature signature)
	{
		const char* typeName = typeid(T).name();
		assert(signatures_.find(typeName) == signatures_.end() && "System used before registered");
		//システムにシグネチャをセット
		signatures_.insert({ typeName,signature });
	}

	void EntityDestroyed(Entity entity);
	void EntitySignatureChanged(Entity entity, Signature entitySignature);
};

