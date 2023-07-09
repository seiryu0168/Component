#include "ComponentManager.h"

void ComponentManager::AllRemoveComponent()
{
	for (auto&& itr=componentArrays_.begin();itr!=componentArrays_.end();itr++)
	{
		(*itr).second->Clear();
	}
	componentArrays_.clear();
}