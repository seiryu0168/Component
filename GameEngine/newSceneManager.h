#pragma once
#include<vector>
#include<string>
#include<utility>
#include"SceneBase.h"
enum class SCENE_ID
{
	SCENE_ID_MAIN = 0,
	SCENE_ID_SUB,
	SCENE_MAX,
};

namespace newSceneManager
{
	void Initialize();
	void Initialize(std::string name);
	void Update();
	void AddScene(std::string objectFileName);
	void CreateScene(std::string sceneName);
	void ChangeScene(SCENE_ID next, int countDown = 0);
	void ECSInitialize();

};

