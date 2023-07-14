#pragma once
#include"Coordinator.h"
#include"RootObject.h"
#include"ObjectSetter.h"
class SceneBase
{
	RootObject* rootObject_;
	std::string sceneName_;
	std::string fileName_;
	ObjectSetter setter_;
public:
	SceneBase();
	SceneBase(std::string name);
	virtual ~SceneBase() {};
	void SceneInitialize();
	void ObjectSet();
	void SetFile(std::string name);
	void Update();

	void AllKillObject();

};

