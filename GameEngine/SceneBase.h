#pragma once
#include"Coordinator.h"
#include"Object.h"
#include"ObjectSetter.h"
class SceneBase
{
	Object* rootObject_;
	ObjectSetter setter_;
public:
	SceneBase();
	virtual ~SceneBase() {};
	void SceneInitialize();


};

