#include "Object.h"
#include"../Systems/PhysicsSystem.h"
#include"../SAFE_DELETE_RELEASE.h"
#include "../Debug.h"

int objectcount = 0;
Object::Object(Object* parent, const std::string& name)
	:pParent_(parent),
	objectName_(name),
	objectTag_(""),
	killFlag_(0),
	activeFlag_(true),
	isUpdate_(true),
	drawFlag_(true),
	startFlag_(false),
	objectID_(-1),
	time_(0),
	pScene_(nullptr),
	physicsSystem_(nullptr),
	childList_()
{
	
	//Coordinator::RegisterComponent<Gravity>();
	//Coordinator::RegisterComponent<TransformData>();
	//Coordinator::RegisterComponent<RigidBody>();

	/*physicsSystem_ = Coordinator::RegisterSystem<PhysicsSystem>();
	

	Signature signature;
	signature.set(Coordinator::GetComponentType<Gravity>());
	signature.set(Coordinator::GetComponentType<RigidBody>());
	signature.set(Coordinator::GetComponentType<TransformData>());

	Coordinator::SetSystemSignature<PhysicsSystem>(signature);*/
}

Object::Object(Object* parent) : Object(parent, "")
{
}

Object::~Object()
{
}

void Object::UpdateSub()
{
	/////////�A�b�v�f�[�g/////////
	if (startFlag_ == false && activeFlag_)
	{
		//Object* p = GetRootObject();
		this->Initialize();
		this->startFlag_ = true;
	}
	else if (startFlag_ &&
		activeFlag_ &&
		isUpdate_)
		Update();

#if _DEBUG
	DebugMode();
	ShowGraphical();

	//�f�o�b�O���[�h���Ăяo���Ă��Ȃ��Ƃ����s
	if (!Debug::CallDebug_)
#endif
		for (auto&& itr : childList_)
		{
			itr->UpdateSub();
		}

	//for (auto itr = childList_.begin(); itr != childList_.end();)
	//{
	//	if ((*itr)->killFlag_ == true)
	//	{
	//		(*itr)->ReleaseSub();
	//		 //SAFE_RELEASE(*itr->get());
	//		itr = childList_.erase(itr);
	//	}
	//	else
	//		itr++;
	//}
}

//void Object::ComponentUpdate()
//{
//	for (Component* comp : componentList_)
//	{
//		comp->Update();
//	}
//}

void Object::FixedUpdateSub()
{
	FixedUpdate();
	for (auto&& itr : childList_)
	{
		itr->FixedUpdateSub();
	}

	for (auto itr = childList_.begin(); itr != childList_.end();)
	{
		if ((*itr)->killFlag_ == true)
		{
			(*itr)->ReleaseSub();
			itr = childList_.erase(itr);
		}
		/*else
		{
			(*itr)->Collision(GetParent());
			itr++;
		}*/
	}
}
void Object::DrawSub()
{
	if (drawFlag_ && startFlag_)
	{
		Draw();
	}
	for (auto&& itr : childList_)
	{
		itr->DrawSub();
	}
}

void Object::SecondDrawSub()
{
	if (drawFlag_ && startFlag_)
	{
		SecondDraw();
	}

	for (auto&& itr : childList_)
	{
		itr->SecondDrawSub();
	}
}

void Object::ThirdDrawSub()
{
	if (drawFlag_&&startFlag_)
	{
		ThirdDraw();
	}

	for (auto&& itr : childList_)
	{
		itr->ThirdDrawSub();
	}
}
void Object::ReleaseSub()
{
	for (auto itr = childList_.begin();itr != childList_.end();)
	{
			(*itr)->ReleaseSub();
		if ((*itr)->IsDead())
		{
			//SAFE_DELETE(*itr)
			itr = childList_.erase(itr);
		}
		//else if ((*itr)->childList_.empty() != false)
		//{
		//	(*itr)->ReleaseSub();
		//}
		else
			itr++;


	
	}

	Release();
}

//void Object::DelCollider(const Object& obj)
//{
//	for (auto itr = colliderList_.begin(); itr != colliderList_.end();)
//	{
//		if ((*itr)->GetpColObject() == &obj)
//		{
//			itr = colliderList_.erase(itr);
//		}
//		if (itr == colliderList_.end())
//		{
//			break;
//		}
//		itr++;
//	}
//}

void Object::KillMe()
{
	this->killFlag_ = true;
	for (auto&& itr = childList_.begin(); itr != childList_.end(); itr++)
	{
		(*itr)->KillMe();
	}
}

Object* Object::GetParent() const
{
	return pParent_;
}

Object* Object::GetRootObject()
{
	if (this->GetParent() == nullptr)
		return this;
	else
		return GetParent()->GetRootObject();
}

Object* Object::FindObject(const std::string& name)
{
	return GetRootObject()->FindChild(name);
}

Object* Object::FindObjectAtTag(const std::string& tagName)
{
	return GetRootObject()->FindChildAtTag(tagName);
}

Object* Object::FindChild(const std::string& name) const
{
	if (childList_.empty())
		return nullptr;

	for (auto&& obj : childList_)
	{
		if (obj->objectName_ == name)
			return obj.get();

		Object* objChild = obj->FindChild(name);
		if (objChild != nullptr)
			return objChild;

	}
	return nullptr;
}

Object* Object::FindChildAtTag(const std::string& tagName) const
{
	if (childList_.empty())
		return nullptr;

	for (auto&& obj : childList_)
	{
		if (obj->objectTag_== tagName)
			return obj.get();

		Object* objChild = obj->FindChildAtTag(tagName);
		if (objChild != nullptr)
			return objChild;

	}
	return nullptr;
}

Object* Object::GetScene()
{
	auto itr = GetRootObject()->GetChildList()->begin();
	return (*itr)->GetChildList()->begin()->get();
}

void Object::KillAllChildren()
{
	//���X�g�ɉ���������ΏI���
	if (childList_.empty())
	{
		return;
	}
	//���X�g�ɂ���q�ǂ���S������
	for (auto&& itr : childList_)
	{
		KillObjectSub(itr.get());
		//delete* itr;
		//itr = this->childList_.erase(itr);
	}
	childList_.clear();
}

void Object::KillObjectSub(Object* pTarget)
{
	if (!pTarget->childList_.empty())
	{
		for (auto&& itr : pTarget->childList_)
		{
			KillObjectSub(itr.get());
			//SAFE_DELETE(*itr);
			//itr = pTarget->childList_.erase(itr);
		}
		pTarget->childList_.clear();
	}
	pTarget->Release();
}
void Object::PushBackChild(const std::shared_ptr<Object>& pTarget)
{
	assert(pTarget != nullptr);
	pTarget->pParent_ = this;
	pTarget->objectID_ = objectcount++;
	childList_.push_back(pTarget);
}