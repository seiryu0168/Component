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
	std::string prevSceneName_;
	std::string currentSceneName_;
	std::string nextSceneName_;
	bool isSceneChange_;
	UINT changeCount_;
	std::string sceneFile_;
	std::unordered_map<std::string,std::shared_ptr<SceneBase>> sceneList_;
	std::shared_ptr<SceneBase> currentScene_;
	std::shared_ptr<ColliderSystem> pColliderSystem_;
	std::shared_ptr<ModelSystem> pModelSyatem_;
	std::shared_ptr<ParticleSystem> pParticleSystem_;
	std::shared_ptr<LineParticleSystem> pLineParticleSystem_;
	std::shared_ptr<TextSystem> pTextSystem_;
	std::shared_ptr<ImageSystem> pImageSystem_;
	void Initialize()
	{
		prevSceneName_ = "Title";
		currentSceneName_ = "Title";
		nextSceneName_ = "Title";
		isSceneChange_ = false;
		changeCount_ = 0;
		ECSInitialize();
		std::shared_ptr<Scene_Title> title=std::make_shared<Scene_Title>("Title");
		std::shared_ptr<Scene_Menu> menu = std::make_shared<Scene_Menu>("Menu");
		sceneList_.insert({"Title", title });
		sceneList_.insert({ "Menu",menu });
		currentScene_ = title;
		currentScene_->SceneInitialize();
	}

	void Update()
	{
		if (isSceneChange_ && changeCount_ <= 0)
		{
			currentScene_->AllKillObject();

			Coordinator::AllRemove();
			ModelManager_ECSver::Release();
			ImageManager_ECSver::Release();
			TextureManager::Release();

			currentScene_=sceneList_.find(nextSceneName_)->second;
			currentScene_->SceneInitialize();
			//sceneList_[static_cast<int>(nextScene_)].second->SceneInitialize();
			//sceneList_[static_cast<int>(nextScene_)].second->ObjectSet();
			currentSceneName_ = nextSceneName_;
			isSceneChange_ = false;
		}
		pColliderSystem_.get()->Update();
		currentScene_->Update();

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

	//void ChangeScene(SCENE_ID next, int countDown)
	//{
	//	isSceneChange_ = true;
	//	//nextSceneName_ = next;
	//	changeCount_ = countDown;
	//}

	void ChangeScene(std::string next, int countDown)
	{
		if (sceneList_.find(next) == sceneList_.end())
			return;
		isSceneChange_ = true;
		nextSceneName_ = next;
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