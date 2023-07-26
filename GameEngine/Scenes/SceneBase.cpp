#include"SceneBase.h"

//#include"PhysicsSystem.h"
//#include"TransformSystem.h"
//#include"ColliderSystem.h"
//#include"ModelSystem.h"
//#include"Coordinator.h"


SceneBase::SceneBase()
	:SceneBase("default")
{
}

SceneBase::SceneBase(const std::string& name)
	:sceneName_(name)
{
}

void SceneBase::SceneInitialize()
{
	//rootObject_ = std::make_shared<RootObject>();
	//rootObject_->SetTransform();
	//setter_ = ObjectSetter(rootObject_.get());
}

void SceneBase::SetRootObject(std::shared_ptr<Object> obj)
{
	rootObject_ = obj;
}

void SceneBase::ObjectSet()
{
	setter_.SetObject();
}

void SceneBase::SetFile(const std::string& name)
{
	fileName_ = name;
}

void SceneBase::Update()
{
	rootObject_->UpdateSub();
}

void SceneBase::CheckKillObject()
{
	rootObject_->ReleaseSub();
}

void SceneBase::AllKillObject()
{
	rootObject_->KillAllChildren();
	setter_.DeleteObject();
}
