#pragma once
#include"Component.h"
#include"Engine\GameObject\GameObject.h"
//#include"Engine/GameObject/Transform.h"
class ComponentManager
{
private:
	std::string tag_;
	std::list<Component*> componentList_;
public:
	Transform Transform_;
	GameObject* object_;
	ComponentManager(GameObject* target);
	ComponentManager();
	~ComponentManager();
	template<class T>
	T* AddComponent()
	{
		T* comp;
		comp = new T(object_);
		componentList_.push_back(comp);
	}

	//コンポーネント取得
	template<class T>
	T* GetComponent(int num = 0)
	{
		int compnum = 0;
		for (auto&& i : componentList_)
		{
			if (typeid(T) == typeid(*i))
			{
				if (compnum == num)
					return (T*)i;

				compnum++;
			}
		}
		return nullptr;
	}

	template<class T>
	std::list<T*> GetComponentList()
	{
		std::list<T*> returnList;
		for (auto&& i : componentList_)
		{
			if (typeid(T) == typeid(*i))
			{
				returnList.push_back(*i);
			}
		}
		return returnList;
	}
};

