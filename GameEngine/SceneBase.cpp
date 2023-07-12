#include"SceneBase.h"

//#include"PhysicsSystem.h"
//#include"TransformSystem.h"
//#include"ColliderSystem.h"
//#include"ModelSystem.h"
//#include"Coordinator.h"


SceneBase::SceneBase()
	:sceneName_("default")
{
}

SceneBase::SceneBase(std::string name)
	:sceneName_(name)
{
}

void SceneBase::SceneInitialize()
{
	rootObject_ = new RootObject;
	rootObject_->SetTransform();
	setter_ = ObjectSetter(rootObject_);
}

void SceneBase::ObjectSet()
{
	setter_.SetObject();
}

void SceneBase::SetFile(std::string name)
{
	fileName_ = name;
}

void SceneBase::Update()
{
	rootObject_->UpdateSub();
}

void SceneBase::AllKillObject()
{
	rootObject_->KillAllChildren();
	SAFE_DELETE(rootObject_);
	setter_.DeleteObject();
}
