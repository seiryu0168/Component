#pragma once
#include<bitset>
#include<queue>
#include<array>
#include"ECS.h"
//using Entity = unsigned int;
//const Entity MAX_ENTITIES = 5000;
//using ComponentType = unsigned int;
//const ComponentType MAX_COMPONENTS = 32;
//using Signature = std::bitset<MAX_COMPONENTS>;

class EntityManager
{
private:
	//使用可能なエンティティのキュー
	std::queue<Entity> availableEntites_{};
	//エンティティで管理されるシグネチャの配列
	std::array<Signature, MAX_ENTITIES> signatures_{};
	//今使用してるエンティティの数
	unsigned int livingEntityCount_{};
public:
	EntityManager();
	~EntityManager();

	Entity CreateEntity();
	void DestroyEntity(Entity entity);
	void SetSignature(Entity entity, Signature signature);
	Signature GetSignature(Entity entity);
	void Initialize();

};

