#include "newSceneManager.h"
#include"../Scenes/Scene_Title.h"
#include"../Scenes/Scene_Menu.h"
#include"ResourceManager/ModelManager_ECSver.h"
#include"ResourceManager/ImageManager_ECSver.h"
#include"ResourceManager/Audio.h"
#include"ResourceManager/TextureManager.h"
#include"Systems/PhysicsSystem.h"
#include"Systems/TransformSystem.h"
#include"Systems/ColliderSystem.h"
#include"Systems/ModelSystem.h"
#include"Systems/ParticleSystem.h"
#include"Systems/LineParticleSystem.h"
#include"Systems/TextSystem.h"
#include"Systems/ImageSystem.h"
#include"Coordinator.h"

namespace newSceneManager
{
	SCENE_ID prevScene_;
	SCENE_ID currentScene_;
	SCENE_ID nextScene_;
	bool isSceneChange_;
	UINT changeCount_;
	std::string sceneFile_;
	std::vector<std::shared_ptr<SceneBase>> sceneList_;

	std::shared_ptr<ColliderSystem> pColliderSystem_;
	std::shared_ptr<ModelSystem> pModelSyatem_;
	std::shared_ptr<ParticleSystem> pParticleSystem_;
	std::shared_ptr<LineParticleSystem> pLineParticleSystem_;
	std::shared_ptr<TextSystem> pTextSystem_;
	std::shared_ptr<ImageSystem> pImageSystem_;
	void Initialize()
	{
		prevScene_ = SCENE_ID::SCENE_ID_TITLE;
		currentScene_ = SCENE_ID::SCENE_ID_TITLE;
		nextScene_ = SCENE_ID::SCENE_ID_TITLE;
		isSceneChange_ = false;
		changeCount_ = 0;
		ECSInitialize();
		std::shared_ptr<Scene_Title> title=std::make_shared<Scene_Title>("Title");
		std::shared_ptr<Scene_Menu> menu = std::make_shared<Scene_Menu>("Menu");
		sceneList_.push_back(title);
		sceneList_.push_back(menu);
		
		for (int i = 0; i < static_cast<int>(SCENE_ID::SCENE_MAX); i++)
		{
			sceneList_[i]->SceneInitialize();
		}
		//sceneList_[static_cast<int>(currentScene_)]->ObjectSet();
	}
	//void Initialize(const std::string& name)
	//{
	//	currentScene_ = SCENE_ID::SCENE_ID_MAIN;
	//	ECSInitialize();
	//	Scene1 scene(name);
	//	sceneList_.push_back(scene);
	//	sceneList_[static_cast<int>(currentScene_)].SceneInitialize();
	//	sceneList_[static_cast<int>(currentScene_)].ObjectSet();
	//}

	void Update()
	{
		if (isSceneChange_ && changeCount_ <= 0)
		{
			sceneList_[static_cast<int>(currentScene_)]->AllKillObject();

			Coordinator::AllRemove();
			ModelManager_ECSver::Release();
			ImageManager_ECSver::Release();
			TextureManager::Release();

			sceneList_[static_cast<int>(nextScene_)]->SceneInitialize();
			sceneList_[static_cast<int>(nextScene_)]->ObjectSet();
			currentScene_ = nextScene_;
			isSceneChange_ = false;
		}
		pColliderSystem_.get()->Update();
		sceneList_[static_cast<int>(currentScene_)]->Update();

		if(changeCount_!=0)
		changeCount_--;
		changeCount_ = max(0, changeCount_);
	}

	void Draw()
	{
		pModelSyatem_->Update();
		pParticleSystem_->Update();
		pLineParticleSystem_->Update();
		pImageSystem_->Update();
		pTextSystem_->Update();
		
	}

	void AddScene(const std::string& objectFileName)
	{

	}

	void CreateScene(const std::string& sceneName)
	{
		//Scene1 scene(sceneName);
		//sceneList_.push_back(scene);
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
		pLineParticleSystem_ = Coordinator::RegisterSystem<LineParticleSystem>();
		pColliderSystem_ = Coordinator::RegisterSystem<ColliderSystem>();
		pImageSystem_ = Coordinator::RegisterSystem<ImageSystem>();
		Coordinator::RegisterComponent<Text>();
		Coordinator::RegisterComponent<Collider>();
		Coordinator::RegisterComponent<Particle>();
		Coordinator::RegisterComponent<LineParticle>();
		Coordinator::RegisterComponent<Transform>();
		Coordinator::RegisterComponent<Test_Model_ECSver>();
		Coordinator::RegisterComponent<Image>();
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
		Signature lineParticle_signature;
		lineParticle_signature.set(Coordinator::GetComponentType<LineParticle>());
		Signature model_signature;
		model_signature.set(Coordinator::GetComponentType<Test_Model_ECSver>());
		Signature image_signature;
		image_signature.set(Coordinator::GetComponentType<Image>());

		Coordinator::SetSystemSignature<PhysicsSystem>(phy_signature);
		Coordinator::SetSystemSignature<TransformSystem>(trans_signature);
		Coordinator::SetSystemSignature<ColliderSystem>(coll_signature);
		Coordinator::SetSystemSignature<ParticleSystem>(particle_signature);
		Coordinator::SetSystemSignature<LineParticleSystem>(lineParticle_signature);
		
		Coordinator::SetSystemSignature<ModelSystem>(model_signature);
		Coordinator::SetSystemSignature<TextSystem>(text_signature);
		Coordinator::SetSystemSignature<ImageSystem>(image_signature);
	}

}