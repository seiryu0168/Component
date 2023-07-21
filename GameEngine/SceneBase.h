#pragma once
#include"Coordinator.h"
#include"RootObject.h"
#include"ObjectSetter.h"
class SceneBase
{
	std::shared_ptr<RootObject> rootObject_;
	std::string sceneName_;
	std::string fileName_;
	ObjectSetter setter_;
public:
	SceneBase();
	SceneBase(const std::string& name);
	virtual ~SceneBase() {};
	void SceneInitialize();
	void ObjectSet();
	void SetFile(const std::string& name);
	void Update();

	void AllKillObject();

};

