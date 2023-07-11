#include "newSceneManager.h"
#include"Scene1.h"
#include"Engine/ResourceManager/Model.h"
#include"Engine/ResourceManager/ImageManager.h"
#include"Engine/ResourceManager/Audio.h"
#include"PhysicsSystem.h"
#include"TransformSystem.h"
#include"ColliderSystem.h"
#include"ModelSystem.h"
#include"Coordinator.h"
newSceneManager::newSceneManager()
	:currentScene_(0)
{
	ECSInitialize();
	Scene1 scene;
	sceneList_.push_back(scene);
}

newSceneManager::newSceneManager(std::string name)
	:sceneFile_(name)
{
	ECSInitialize();
	Scene1 scene(name);
	sceneList_.push_back(scene);
	//CreateScene();
}

newSceneManager::~newSceneManager()
{

}

void newSceneManager::Initialize()
{
	sceneList_[currentScene_].SceneInitialize();
	sceneList_[currentScene_].ObjectSet();
}

void newSceneManager::Update()
{
	if (isSceneChange_ && changeCount_ <= 0)
	{
		sceneList_[currentScene_].AllKillObject();
		Coordinator::AllRemove();
		ModelManager::AllDeleteModelNum();
		ModelManager::Release();
		ImageManager::AllRelease();


		sceneList_[nextScene_].SceneInitialize();
		sceneList_[nextScene_].ObjectSet();
		isSceneChange_ = false;
		currentScene_ = nextScene_;
	}
	sceneList_[currentScene_].Update();

	changeCount_--;
	changeCount_ = max(0, changeCount_);
}

void newSceneManager::AddScene(std::string objectFileName)
{

}

void newSceneManager::CreateScene(std::string sceneName)
{
	Scene1 scene(sceneName);
	sceneList_.push_back(scene);
}

void newSceneManager::ChangeScene(int next,int countDown)
{

	if (next >= 0 && next < sceneList_.size())
	{
		isSceneChange_ = true;
		nextScene_ = next;
		changeCount_ = countDown;
	}
}

void newSceneManager::ECSInitialize()
{
	Coordinator::RegisterSystem<PhysicsSystem>();
	Coordinator::RegisterSystem<TransformSystem>();
	Coordinator::RegisterSystem<ColliderSystem>();
	Coordinator::RegisterSystem<ModelSystem>();
	Coordinator::RegisterComponent<Collider>();
	Coordinator::RegisterComponent<DrawComponent>();

	Coordinator::RegisterComponent<Transform>();

	Signature phy_signature;
	phy_signature.set(Coordinator::GetComponentType<Gravity>());
	phy_signature.set(Coordinator::GetComponentType<RigidBody>());
	phy_signature.set(Coordinator::GetComponentType<TransformData>());

	Signature trans_signature;
	trans_signature.set(Coordinator::GetComponentType<Transform>());
	Signature coll_signature;
	coll_signature.set(Coordinator::GetComponentType<Collider>());
	Signature model_signature;
	model_signature.set(Coordinator::GetComponentType<DrawComponent>());

	Coordinator::SetSystemSignature<PhysicsSystem>(phy_signature);
	Coordinator::SetSystemSignature<TransformSystem>(trans_signature);
	Coordinator::SetSystemSignature<ColliderSystem>(coll_signature);
	Coordinator::SetSystemSignature<ModelSystem>(model_signature);
}
