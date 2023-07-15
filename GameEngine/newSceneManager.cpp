#include "newSceneManager.h"
#include"Scene1.h"
#include"Engine/ResourceManager/Model.h"
#include"Engine/ResourceManager/ImageManager.h"
#include"Engine/ResourceManager/Audio.h"
#include"PhysicsSystem.h"
#include"TransformSystem.h"
#include"ColliderSystem.h"
#include"ModelSystem.h"
#include"Draw2DSystem.h"
#include"Coordinator.h"

namespace newSceneManager
{
	SCENE_ID prevScene_;
	SCENE_ID currentScene_;
	SCENE_ID nextScene_;
	bool isSceneChange_;
	UINT changeCount_;
	std::string sceneFile_;
	std::vector<SceneBase> sceneList_;

	void Initialize()
	{
		prevScene_ = SCENE_ID::SCENE_ID_MAIN;
		currentScene_ = SCENE_ID::SCENE_ID_MAIN;
		nextScene_ = SCENE_ID::SCENE_ID_MAIN;
		isSceneChange_ = false;
		changeCount_ = 0;
		ECSInitialize();
		for (int i = 0; i < static_cast<int>(SCENE_ID::SCENE_MAX); i++)
		{
			Scene1 scene;
			sceneList_.push_back(scene);
		}
		sceneList_[static_cast<int>(currentScene_)].SceneInitialize();
		sceneList_[static_cast<int>(currentScene_)].ObjectSet();
	}
	void Initialize(std::string name)
	{
		currentScene_ = SCENE_ID::SCENE_ID_MAIN;
		ECSInitialize();
		Scene1 scene(name);
		sceneList_.push_back(scene);
		sceneList_[static_cast<int>(currentScene_)].SceneInitialize();
		sceneList_[static_cast<int>(currentScene_)].ObjectSet();
	}

	void Update()
	{
		if (isSceneChange_ && changeCount_ <= 0)
		{
			sceneList_[static_cast<int>(currentScene_)].AllKillObject();
			Coordinator::AllRemove();
			ModelManager::AllDeleteModelNum();
			ModelManager::Release();
			ImageManager::AllRelease();

			ECSInitialize();
			sceneList_[static_cast<int>(nextScene_)].SceneInitialize();
			sceneList_[static_cast<int>(nextScene_)].ObjectSet();
			currentScene_ = nextScene_;
			isSceneChange_ = false;
		}
		sceneList_[static_cast<int>(currentScene_)].Update();

		if(changeCount_!=0)
		changeCount_--;
		changeCount_ = max(0, changeCount_);
	}

	void AddScene(std::string objectFileName)
	{

	}

	void CreateScene(std::string sceneName)
	{
		Scene1 scene(sceneName);
		sceneList_.push_back(scene);
	}

	void ChangeScene(SCENE_ID next, int countDown)
	{
		isSceneChange_ = true;
		nextScene_ = next;
		changeCount_ = countDown;
	}

	void ECSInitialize()
	{
		Coordinator::RegisterSystem<PhysicsSystem>();
		Coordinator::RegisterSystem<TransformSystem>();
		Coordinator::RegisterSystem<ColliderSystem>();
		Coordinator::RegisterSystem<ModelSystem>();
		Coordinator::RegisterSystem<Draw2DSystem>();
		Coordinator::RegisterComponent<Collider>();
		Coordinator::RegisterComponent<DrawComponent>();
		Coordinator::RegisterComponent<Draw2DComponent>();
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
		Signature d2_signature;
		d2_signature.set(Coordinator::GetComponentType<Draw2DComponent>());
		Coordinator::SetSystemSignature<PhysicsSystem>(phy_signature);
		Coordinator::SetSystemSignature<TransformSystem>(trans_signature);
		Coordinator::SetSystemSignature<ColliderSystem>(coll_signature);
		Coordinator::SetSystemSignature<ModelSystem>(model_signature);
		Coordinator::SetSystemSignature<Draw2DSystem>(d2_signature);
	}

}