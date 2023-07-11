#pragma once
#include"Coordinator.h"
#include"Object.h"
#include"ObjectSetter.h"
class SceneBase
{
	Object* rootObject_;
	std::string fileName_;
	ObjectSetter setter_;
public:
	SceneBase();
	virtual ~SceneBase() {};
	void SceneInitialize();
	void ObjectSet();
	void SetFile(std::string name);
	void Update();

};

