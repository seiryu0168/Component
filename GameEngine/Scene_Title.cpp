#include "Scene_Title.h"

Scene_Title::Scene_Title()
{
}

Scene_Title::Scene_Title(const std::string& name)
	:SceneBase(name)
{
}

Scene_Title::~Scene_Title()
{
}

void Scene_Title::SceneInitialize()
{
	SetRootObject(std::make_shared<RootObject_Title>());
	//rootObject_ = std::make_shared<RootObject_Title>();
	//rootObject_->SetTransform();
}

//void Scene_Title::AllKillObject()
//{
//	//rootObject_->KillAllChildren();
//}
