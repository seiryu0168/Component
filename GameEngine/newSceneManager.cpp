#include "newSceneManager.h"
#include"Scene1.h"
newSceneManager::newSceneManager()
{
}

newSceneManager::newSceneManager(std::string name)
	:sceneFile_(name)
{
}

newSceneManager::~newSceneManager()
{
}

void newSceneManager::Update()
{

}

void newSceneManager::AddScene(std::string objectFileName)
{
	Scene1 scene;
	scene.SetFile(objectFileName);
	sceneList_.push_back(scene);
}

void newSceneManager::ChangeScene()
{
}
