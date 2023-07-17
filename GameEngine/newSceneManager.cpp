#include "newSceneManager.h"
#include"Scene1.h"
#include"Engine/ResourceManager/Model.h"
#include"Engine/ResourceManager/ImageManager.h"
#include"Engine/ResourceManager/Audio.h"
#include"PhysicsSystem.h"
#include"TransformSystem.h"
#include"ColliderSystem.h"
#include"ModelSystem.h"
#include"ParticleSystem.h"
#include"TextSystem.h"
#include"Draw3DSystem.h"
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

	std::shared_ptr<ColliderSystem> pColliderSystem_;
	//std::shared_ptr<Draw3DSystem> pDraw3DSystem_;
	//std::shared_ptr<Draw2DSystem> pDraw2DSystem_;
	std::shared_ptr<ModelSystem> pModelSyatem_;
	std::shared_ptr<ParticleSystem> pParticleSystem_;
	std::shared_ptr<TextSystem> pTextSystem_;
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
		pColliderSystem_.get()->Update();
		sceneList_[static_cast<int>(currentScene_)].Update();

		if(changeCount_!=0)
		changeCount_--;
		changeCount_ = max(0, changeCount_);
	}

	void Draw()
	{
		pModelSyatem_.get()->Update();
		pParticleSystem_.get()->Update();
		pTextSystem_.get()->Update();
		//pDraw2DSystem_.get()->Update();
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
		pTextSystem_ = Coordinator::RegisterSystem<TextSystem>();
		pModelSyatem_ = Coordinator::RegisterSystem<ModelSystem>();
		pParticleSystem_ = Coordinator::RegisterSystem<ParticleSystem>();
		pColliderSystem_ = Coordinator::RegisterSystem<ColliderSystem>();
		
		Coordinator::RegisterComponent<Text>();
		Coordinator::RegisterComponent<Collider>();
		Coordinator::RegisterComponent<Particle>();
		Coordinator::RegisterComponent<Transform>();
		Coordinator::RegisterComponent<Test_Model_ECSver>();

		Signature phy_signature;
		phy_signature.set(Coordinator::GetComponentType<Gravity>());
		phy_signature.set(Coordinator::GetComponentType<RigidBody>());
		phy_signature.set(Coordinator::GetComponentType<TransformData>());

		Signature trans_signature;
		trans_signature.set(Coordinator::GetComponentType<Transform>());
		Signature coll_signature;
		coll_signature.set(Coordinator::GetComponentType<Collider>());
		Signature text_signature;
		text_signature.set(Coordinator::GetComponentType<Text>());
		Signature particle_signature;
		particle_signature.set(Coordinator::GetComponentType<Particle>());
		Signature model_signature;
		model_signature.set(Coordinator::GetComponentType<Test_Model_ECSver>());

		//Signature d3_signature;
		//d3_signature.set(Coordinator::GetComponentType<Draw3DComponent>());
		//Signature d2_signature;
		//d2_signature.set(Coordinator::GetComponentType<Draw2DComponent>());
		Coordinator::SetSystemSignature<PhysicsSystem>(phy_signature);
		Coordinator::SetSystemSignature<TransformSystem>(trans_signature);
		Coordinator::SetSystemSignature<ColliderSystem>(coll_signature);
		Coordinator::SetSystemSignature<ParticleSystem>(particle_signature);
		Coordinator::SetSystemSignature<ModelSystem>(model_signature);
		Coordinator::SetSystemSignature<TextSystem>(text_signature);
		//Coordinator::SetSystemSignature<Draw3DSystem>(d3_signature);
		//
		//Coordinator::SetSystemSignature<Draw2DSystem>(d2_signature);
	}

}