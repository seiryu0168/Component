#pragma once
#include"Engine\Collider\BoxCollider.h"
#include"Engine\Collider/SphereCollider.h"
#include"Engine\Collider/OBBCollider.h"
#include"../../Component.h"
#include<string>
#include<list>

//#ifdef _DEBUG
//#define _CRTDBG_MAP_ALLOC
//#include<memory>
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#include <crtdbg.h>
//#else
//#define DEBUG_NEW	
//#endif
//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif // _DEBUG

class Object
{
	friend class Collider;
	friend class Component;
private:
protected:
	std::list<Object*> childList_;
	std::list<Component*> componentList_;
	std::list<Collider*> colliderList_; //コライダーリスト	
	Object* pParent_;
	Object* pScene_;
	std::string	objectName_;			//名前
	int objectID_;						//オブジェクト固有の番号
	std::string objectTag_;				//オブジェクトに任意でつけられる識別用の名前
	bool killFlag_;						//キルするかどうか
	bool activeFlag_;					//オブジェクトがアクティブ(Update呼ばれる)かどうか
	bool isUpdate_;
	bool drawFlag_;						//描画するかどうか
	bool startFlag_;					//一回もアクティブになってない場合false
public:
	Object(Object* parent,std::string name);
	Object(Object* parent);
	Object();
	~Object();

	virtual void Initialize() = 0;
	virtual void Update() {};
	virtual void FixedUpdate() {};
	virtual void Draw() {};
	virtual void SecondDraw() {};
	virtual void ThirdDraw() {};
	virtual void BeforeDeath() {};
	virtual void Release() = 0;

	void UpdateSub();
	void ComponentUpdate();
	void FixedUpdateSub();
	void DrawSub();
	void SecondDrawSub();
	void ThirdDrawSub();
	void ReleaseSub();

	virtual void OnCollision(Object* pTarget) {};
	void Collision(Object* pTarget);
	void AddCollider(Collider* collider);
	void DelCollider(const Object& obj);


	void KillMe() { killFlag_ = true; }
	bool IsActive() { return activeFlag_; }
	bool IsStart() { return startFlag_; }
	bool IsUpdate() { return isUpdate_; }
	std::string GetObjectName() { return objectName_; }
	Object* GetParent();
	Object* GetRootObject();
	Object* FindObject(std::string name);
	Object* FindObjectAtTag(std::string tagName);

	Object* FindChild(std::string name);
	Object* FindChildAtTag(std::string tagName);

	Object* GetScene();
	std::list<Object*>* GetChildList() { return &childList_; }

	void KillAllChildren();
	void KillObjectSub(Object* pTarget);
	void PushBackChild(Object* pTarget);


	template <class T>
	T* AddComponent(Object* atcObj)
	{
		T* p;
		p = new T(atcObj);
		componentList_.push_back(p);
		return p;
	}
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
	std::list<Component*> GetComponentList()
	{
		std::list<Component*> returnList;
		for (auto&& i : componentList_)
		{
			if (typeid(T) == typeid(*i))
			{
				returnList.push_back(*i);
			}
		}
		return returnList;
	}
	//void DeleteComponent(Component* comp);

	template<class T>
	T* Instantiate(Object* parent)
	{
		T* p;
		p = new T(parent);
		if (parent != nullptr)
		{
			parent->PushBackChild(p);
		}
		return p;
	}
};
