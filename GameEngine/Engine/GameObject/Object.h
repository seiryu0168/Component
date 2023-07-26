#pragma once
//#include"Engine\Collider\BoxCollider.h"
//#include"Engine\Collider/SphereCollider.h"
//#include"Engine\Collider/OBBCollider.h"
#include"../Coordinator.h"
//#include"../Component.h"
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
	//friend class Collider;
	//friend class Component;

private:
	float time_;
protected:

	std::list<std::shared_ptr<Object>> childList_;
	//std::list<Component*> componentList_;
	//std::list<Collider*> colliderList_; //�R���C�_�[���X�g	
	std::unordered_map<std::string, std::vector<Entity>> entityList_;
	//std::vector<Entity> entityList_;
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
	Object(Object* parent,const std::string& name);
	Object(Object* parent = nullptr);
	//Object();
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
	void SetTag(const std::string& tagName) { objectTag_ = tagName; }
	bool IsActive() const { return activeFlag_; }
	bool IsStart() const { return startFlag_; }
	bool IsUpdate() const { return isUpdate_; }
	std::string GetObjectName() const { return objectName_; }
	Object* GetParent() const;
	Object* GetRootObject();
	Object* FindObject(const std::string& name);
	Object* FindObjectAtTag(const std::string& tagName);

	Object* FindChild(const std::string& name) const;
	Object* FindChildAtTag(const std::string& tagName) const;

	Object* GetScene();
	std::list<std::shared_ptr<Object>>* GetChildList() { return &childList_; }

	void KillAllChildren();
	void KillObjectSub(Object* pTarget);
	void PushBackChild(const std::shared_ptr<Object>& pTarget);

	template <typename T>
	void AddComponent(const T& component)
	{
		std::string typeName = typeid(T).name();
			Entity entity = Coordinator::CreateEntity();
			//���܂œ��ꂽ���Ƃ��Ȃ��R���|�[�l���g��������
			//�z�������ăG���e�B�e�B���i�[
			if (entityList_.find(typeName) == entityList_.end())
			{
				std::vector<Entity> entities;
				entities.push_back(entity);
				entityList_.insert({ typeName,entities });
			}
			else
				entityList_.find(typeName)->second.push_back(entity);

			Coordinator::AddComponent<T>(entity,component);
	}

	template <typename T>
	void RemoveComponent(int componentNum=0)
	{
		std::string typeName = typeid(T).name();
		//�R���|�[�l���g�ԍ����z����ɂ���Ȃ�
		if(componentNum< entityList_.find(typeName)->second.size())
		Coordinator::RemoveComponent<T>(entityList_.find(typeName)->second[componentNum]);
	}

	template <typename T>
	T& GetComponent(int componentNum=0)
	{
		std::string typeName = typeid(T).name();
		assert(entityList_.find(typeName)->second.size());	//���s�����狭���I��
		return Coordinator::GetComponent<T>(entityList_.find(typeName)->second[componentNum]);
	}
	template <typename T>
	std::vector<Entity>& GetComponentList()
	{
		std::string typeName = typeid(T).name();
		assert(entityList_.find(typeName)!=entityList_.end());	//���s�����狭���I��
		return entityList_.find(typeName)->second;
	}

	template<class T>
	T* Instantiate(Object* parent)
	{
		std::shared_ptr<T> p = std::make_shared<T>(parent);
		if (parent != nullptr)
		{
			parent->PushBackChild(p);
		}
		return p.get();
	}
};