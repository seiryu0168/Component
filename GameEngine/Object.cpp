#include "Object.h"
#include"Engine\SAFE_DELETE_RELEASE.h"

int objectcount = 0;
Object::Object(Object* parent, std::string name)
{
}

Object::Object(Object* parent)
{
}

Object::Object()
{
}

Object::~Object()
{
}

void Object::UpdateSub()
{
	/////////アップデート/////////
	if (startFlag_ == false && activeFlag_)
	{
		Object* p = GetRootObject();
		this->Initialize();
		this->startFlag_ = true;
	}
	else if (startFlag_ &&
		activeFlag_ &&
		isUpdate_)
		Update();



	for (auto itr = childList_.begin(); itr != childList_.end(); itr++)
	{
		(*itr)->UpdateSub();
	}
	////////当たり判定///////////
	for (auto itr = childList_.begin(); itr != childList_.end();)
	{
		if (activeFlag_)
		{

			if ((*itr)->killFlag_ == true)
			{
				(*itr)->BeforeDeath();
				(*itr)->ReleaseSub();
				delete* itr;
				itr = childList_.erase(itr);
			}
			/*else
			{
				(*itr)->Collision(GetParent());
				itr++;
			}*/
		}
	}
}

void Object::FixedUpdateSub()
{
	FixedUpdate();
	for (auto itr = childList_.begin(); itr != childList_.end(); itr++)
	{
		(*itr)->FixedUpdateSub();
	}

	for (auto itr = childList_.begin(); itr != childList_.end();)
	{
		if ((*itr)->killFlag_ == true)
		{
			(*itr)->ReleaseSub();
			delete* itr;
			itr = childList_.erase(itr);
		}
		/*else
		{
			(*itr)->Collision(GetParent());
			itr++;
		}*/
	}
}
void Object::ReleaseSub()
{
	for (auto i = colliderList_.begin(); i != colliderList_.end(); i++)
	{
		SAFE_DELETE(*i);
	}
	for (auto i = childList_.begin(); i != childList_.end(); i++)
	{
		(*i)->ReleaseSub();
		SAFE_DELETE(*i);
	}

	Release();
}
//コライダーを追加
//collider->pColObjectにセットする奴
//void Object::AddCollider(Collider* collider)
//{
//	collider->SetGemaObject(this);
//	colliderList_.push_back(collider);
//}

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

Object* Object::GetParent()
{
	return pParent_;
}

Object* Object::GetRootObject()
{
	if (pParent_->GetParent() == nullptr)
		return this;
	return GetParent()->GetRootObject();
}

void Object::KillAllChildren()
{
	//リストに何も無ければ終わり
	if (childList_.empty())
	{
		return;
	}
	//リストにある子どもを全員消す
	for (auto itr = this->childList_.begin(); itr != this->childList_.end();)
	{
		KillObjectSub(*itr);
		delete* itr;
		itr = this->childList_.erase(itr);
	}
}

void Object::KillObjectSub(Object* pTarget)
{
	if (!pTarget->childList_.empty())
	{
		for (auto itr = pTarget->childList_.begin(); itr != pTarget->childList_.end();)
		{
			KillObjectSub(*itr);
			SAFE_DELETE(*itr);
			itr = pTarget->childList_.erase(itr);
		}
		pTarget->childList_.clear();
	}
	pTarget->Release();
}
void Object::PushBackChild(Object* pTarget)
{
	assert(pTarget != nullptr);
	pTarget->pParent_ = this;
	pTarget->objectID_ = objectcount++;
	childList_.push_back(pTarget);
}