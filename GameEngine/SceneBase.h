#pragma once
#include"Coordinator.h"
#include"RootObject.h"
#include"ObjectSetter.h"
class SceneBase
{
	std::shared_ptr<Object> rootObject_;
	std::string sceneName_;
	std::string fileName_;
	ObjectSetter setter_;
public:
	SceneBase();
	SceneBase(const std::string& name);
	virtual ~SceneBase() {};
	virtual void SceneInitialize() = 0;
	void SetRootObject(std::shared_ptr<Object> obj);
	void ObjectSet();
	void SetFile(const std::string& name);
	void Update();

	void AllKillObject();

};

