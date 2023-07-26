#pragma once
#include<vector>
#include<string>
#include<utility>
#include"../Scenes/SceneBase.h"
enum class SCENE_ID
{
	TITLE = 0,
	MENU,
	PLAY,
	//MAX,
};

namespace newSceneManager
{
	void Initialize();
	//void Initialize(const std::string& name);
	void Update();
	void Draw();
	void AddScene(const std::string& objectFileName);
	void CreateScene(const std::string& sceneName);
	//void ChangeScene(SCENE_ID next, int countDown = 0);
	void ChangeScene(const SCENE_ID& sceneId, int countDown = 0);
	void ECSInitialize();

};

