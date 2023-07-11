#pragma once
#include<vector>
#include<string>
#include<pair>
#include"SceneBase.h"
class newSceneManager
{
private:
	std::string sceneFile_;
	std::vector<SceneBase> sceneList_;

public:
	newSceneManager();
	newSceneManager(std::string name);
	~newSceneManager();
	void Update();
	void AddScene(std::string objectFileName);
	void ChangeScene();

};

