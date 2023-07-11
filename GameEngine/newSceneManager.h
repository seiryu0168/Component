#pragma once
#include<vector>
#include<string>
#include<utility>
#include"SceneBase.h"
class newSceneManager
{
private:
	int prevScene_;
	int currentScene_;
	int nextScene_;
	bool isSceneChange_;
	UINT changeCount_;
	std::string sceneFile_;
	std::vector<SceneBase> sceneList_;
	//std::pair<std::string, SceneBase> scene;

public:
	newSceneManager();
	newSceneManager(std::string name);
	~newSceneManager();
	void Initialize();
	void Update();
	void AddScene(std::string objectFileName);
	void CreateScene(std::string sceneName);
	void ChangeScene(int next, int countDown);
	void ECSInitialize();

};

