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
	void Initialize(const std::string& name);
	void Update();
	void Draw();
	void AddScene(const std::string& objectFileName);
	void CreateScene(const std::string& sceneName);
	void ChangeScene(SCENE_ID next, int countDown = 0);
	void ECSInitialize();

};

