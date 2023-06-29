#pragma once
//#include"Engine\Collider\BoxCollider.h"
//#include"Engine\Collider/SphereCollider.h"
//#include"Engine\Collider/OBBCollider.h"
#include"Coordinator.h"
#include"Component.h"
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

class PhysicsSystem;
class Object
{
	friend class Collider;
	friend class Component;

private:
	float time_;
protected:

	std::list<Object*> childList_;
	std::list<Component*> componentList_;
	//std::list<Collider*> colliderList_; //�R���C�_�[���X�g	
	std::vector<Entity> entityList_;
	Object* pParent_;
	Object* pScene_;
	std::string	objectName_;			//���O
	int objectID_;						//�I�u�W�F�N�g�ŗL�̔ԍ�
	std::string objectTag_;				//�I�u�W�F�N�g�ɔC�ӂł����鎯�ʗp�̖��O
	bool killFlag_;						//�L�����邩�ǂ���
	bool activeFlag_;					//�I�u�W�F�N�g���A�N�e�B�u(Update�Ă΂��)���ǂ���
	bool isUpdate_;
	bool drawFlag_;						//�`�悷�邩�ǂ���
	bool startFlag_;					//�����A�N�e�B�u�ɂȂ��ĂȂ��ꍇfalse
	PhysicsSystem* physicsSystem_;
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
	//void Collision(Object* pTarget);
	//void AddCollider(Collider* collider);
	//void DelCollider(const Object& obj);


	void KillMe() { killFlag_ = true; }
	void SetTag(std::string tagName) { objectTag_ = tagName; }
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
	template<typename T>
	T GetComponent()
	{
		Coordinator::GetComponent<T>()
	}
	std::list<Object*>* GetChildList() { return &childList_; }

	void KillAllChildren();
	void KillObjectSub(Object* pTarget);
	void PushBackChild(Object* pTarget);


	//template <class T>
	//T* AddComponent(Object* atcObj)
	//{
	//	T* p;
	//	p = new T(atcObj);
	//	componentList_.push_back(p);
	//	return p;
	//}
	//template<class T>
	//T* GetComponent(int num = 0)
	//{
	//	int compnum = 0;
	//	for (auto&& i : componentList_)
	//	{
	//		if (typeid(T) == typeid(*i))
	//		{
	//			if (compnum == num)
	//				return (T*)i;
	//
	//			compnum++;
	//		}
	//	}
	//	return nullptr;
	//}
	//
	//template<class T>
	//std::list<Component*> GetComponentList()
	//{
	//	std::list<Component*> returnList;
	//	for (auto&& i : componentList_)
	//	{
	//		if (typeid(T) == typeid(*i))
	//		{
	//			returnList.push_back(*i);
	//		}
	//	}
	//	return returnList;
	//}
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
