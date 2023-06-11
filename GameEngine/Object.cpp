#include "Object.h"
#include"Engine\SAFE_DELETE_RELEASE.h"

int objectcount = 0;
Object::Object(Object* parent, const std::string name)
	:pParent_(parent),
	objectName_(name),
	objectTag_(""),
	killFlag_(0),
	activeFlag_(true),
	isUpdate_(true),
	drawFlag_(true),
	startFlag_(false),
	objectID_(-1)
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
	//for (auto itr = childList_.begin(); itr != childList_.end();)
	//{
	//	if (activeFlag_)
	//	{

	//		if ((*itr)->killFlag_ == true)
	//		{
	//			(*itr)->BeforeDeath();
	//			(*itr)->ReleaseSub();
	//			delete* itr;
	//			itr = childList_.erase(itr);
	//		}
	//		/*else
	//		{
	//			(*itr)->Collision(GetParent());
	//			itr++;
	//		}*/
	//	}
	//}
}

void Object::ComponentUpdate()
{
	for (Component* comp : componentList_)
	{
		comp->Update();
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
void Object::DrawSub()
{
	if (drawFlag_ && startFlag_)
	{
		Draw();
	}
	for (auto itr=childList_.begin();itr!=childList_.end();itr++)
	{
		(*itr)->DrawSub();
	}
}

void Object::SecondDrawSub()
{
	if (drawFlag_ && startFlag_)
	{
		SecondDraw();
	}

	for (auto itr = childList_.begin(); itr != childList_.end(); itr++)
	{
		
			(*itr)->SecondDrawSub();
	}
}

void Object::ThirdDrawSub()
{
	if (drawFlag_&&startFlag_)
	{
		ThirdDraw();
	}

	for (auto itr = childList_.begin(); itr != childList_.end(); itr++)
	{
			(*itr)->ThirdDrawSub();
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
	if (this->GetParent() == nullptr)
		return this;
	else
		return GetParent()->GetRootObject();
}

Object* Object::FindObject(std::string name)
{
	return GetRootObject()->FindChild(name);
}

Object* Object::FindObjectAtTag(std::string tagName)
{
	return GetRootObject()->FindChildAtTag(tagName);
}

Object* Object::FindChild(std::string name)
{
	if (childList_.empty())
		return nullptr;

	for (Object* obj : childList_)
	{
		if (obj->objectName_ == name)
			return obj;

		Object* objChild = obj->FindChild(name);
		if (objChild != nullptr)
			return objChild;

	}
	return nullptr;
}

Object* Object::FindChildAtTag(std::string tagName)
{
	if (childList_.empty())
		return nullptr;

	for (Object* obj : childList_)
	{
		if (obj->objectTag_== tagName)
			return obj;

		Object* objChild = obj->FindChildAtTag(tagName);
		if (objChild != nullptr)
			return objChild;

	}
	return nullptr;
}

Object* Object::GetScene()
{
	auto itr = GetRootObject()->GetChildList()->begin();
	return (*(*itr)->GetChildList()->begin());
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