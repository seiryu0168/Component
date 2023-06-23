#pragma once
#include"IComponentArray.h"
#include<unordered_map>
template<class T>
class ComponentArray : public IComponentArray
{
private:
	//コンポーネントの配列(MAX_ENTITIESが配列の長さ)
	std::array<T, MAX_ENTITIES> componentArray_;
	//エンティティから配列のインデックスのマッピング
	std::unordered_map<Entity, size_t> entityToIndexMap_;
	//インデックスからエンティティのマッピング
	std::unordered_map<size_t, Entity> indexToEntityMap_;
	//配列内の有効なエンティティの総数
	size_t size_;
public:
	void InsertData(Entity entity, T component);
	void RemoveData(Entity entity);
	T& GetData(Entity entity);
	void EntityDestroyed(Entity entity) override;


};

