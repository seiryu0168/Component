#pragma once
#include"SceneBase.h"
#include"RootObject_Title.h"
class Scene_Title : public SceneBase
{
	//std::shared_ptr<RootObject_Title> rootObject_;
public:
	Scene_Title();
	Scene_Title(const std::string& name);
	~Scene_Title();
	void SceneInitialize() override;
};

