#include"../Scenes/Scene_Title.h"
#include"../Scenes/Scene_Menu.h"
#include"../Scenes/Scene_Play.h"
#include"../Scenes/Scene_Result.h"

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

#include"GameObject/CameraManager.h"

#include"Coordinator.h"
#include "newSceneManager.h"

#include "../Division.h"

//ïœêî
namespace
{
	SCENE_ID prevSceneName_;
	SCENE_ID currentSceneName_;
	SCENE_ID nextSceneName_;
	bool isSceneChange_;
	UINT changeCount_;
	std::string sceneFile_;
	std::unordered_map<SCENE_ID, std::shared_ptr<SceneBase>> sceneList_;
	std::shared_ptr<SceneBase> currentScene_;
	std::shared_ptr<ColliderSystem> pColliderSystem_;
	std::shared_ptr<ModelSystem> pModelSyatem_;
	std::shared_ptr<ParticleSystem> pParticleSystem_;
	std::shared_ptr<LineParticleSystem> pLineParticleSystem_;
	std::shared_ptr<TextSystem> pTextSystem_;
	std::shared_ptr<ImageSystem> pImageSystem_;

	int MAX_LAYER = 4;
}

//äOïîÇ©ÇÁå©Ç¶Ç»Ç¢ÇÊÇ§Ç…Ç∑ÇÈ
namespace newSceneManager
{
	//ÉVÅ[ÉìÉäÉXÉgÇ…óvëfÇäiî[Ç∑ÇÈ
	void SceneInitialize();
}

namespace newSceneManager
{

	void Initialize()
	{
		prevSceneName_ = SCENE_ID::TITLE;
		currentSceneName_ = SCENE_ID::TITLE;
		nextSceneName_ = SCENE_ID::TITLE;
		isSceneChange_ = false;
		changeCount_ = 0;
		ECSInitialize();

		SceneInitialize();

		currentScene_ = sceneList_[currentSceneName_];
		currentScene_->SceneInitialize();
	}

	void Update()
	{
		if (isSceneChange_ && changeCount_ <= 0)
		{
			Division::setLoad(true);
			currentScene_->AllKillObject();

			Coordinator::AllRemove();
			ModelManager_ECSver::Release();
			ImageManager_ECSver::Release();
			TextureManager::Release();
			//D2D::
			CameraManager::ResetCamera();
			currentScene_ = sceneList_[nextSceneName_];
			currentScene_->SceneInitialize();
			//sceneList_[static_cast<int>(nextScene_)].second->SceneInitialize();
			//sceneList_[static_cast<int>(nextScene_)].second->ObjectSet();
			currentSceneName_ = nextSceneName_;
			isSceneChange_ = false;
			Division::setLoad(false);
		}
		pColliderSystem_.get()->Update();
		currentScene_->Update();
		currentScene_->StaticUpdate();

		pModelSyatem_->Update();
		pParticleSystem_->Update();
		pLineParticleSystem_->Update();

		if (changeCount_ != 0)
		{
			changeCount_--;
			changeCount_ = max(0, changeCount_);
		}
	}

	void Draw()
	{
		for (int layerCount = 0; layerCount < MAX_LAYER; layerCount++)
		{

			pModelSyatem_->Draw(layerCount);
			pParticleSystem_->Draw(layerCount);
			pLineParticleSystem_->Draw(layerCount);
			pImageSystem_->Draw(layerCount);
			pTextSystem_->Draw(layerCount);
		}
		currentScene_->Draw();
	}

	void AddScene(const std::string& objectFileName)
	{

	}

	void CreateScene(const std::string& sceneName)
	{
		//Scene1 scene(sceneName);
		//sceneList_.push_back(scene);
	}

	void CheckRemoveObject()
	{
		pColliderSystem_->CheckRemove();
		pModelSyatem_->CheckRemove();
		pParticleSystem_->CheckRemove();
		pLineParticleSystem_->CheckRemove();
		pImageSystem_->CheckRemove();
		//pTextSystem_->CheckRemove();
		currentScene_->CheckKillObject();
	}

	//void ChangeScene(SCENE_ID next, int countDown)
	//{
	//	isSceneChange_ = true;
	//	//nextSceneName_ = next;
	//	changeCount_ = countDown;
	//}

	void ChangeScene(const SCENE_ID& sceneId, int countDown)
	{
		if (sceneList_.find(sceneId) == sceneList_.end())
			return;
		isSceneChange_ = true;
		nextSceneName_ = sceneId;
		changeCount_ = countDown;
	}
	void ChangeScene(const SCENE_ID& sceneId, float countDown)
	{
		if (sceneList_.find(sceneId) == sceneList_.end())
			return;
		isSceneChange_ = true;
		nextSceneName_ = sceneId;
		changeCount_ = countDown * 60.0f;
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

	void Release()
	{
		Division::setLoad(true);
		currentScene_->AllKillObject();

		Coordinator::AllRemove();
		ModelManager_ECSver::Release();
		ImageManager_ECSver::Release();
		ImageManager_ECSver::StaticImageRelease();
		TextureManager::Release();
		TextureManager::StaticTextureRelease();
		//D2D::
		CameraManager::ResetCamera();
		Division::setLoad(false);
	}

	std::shared_ptr<ImageSystem> GetImageSystem()
	{
		return pImageSystem_;
	}

	void SceneInitialize()
	{
		sceneList_.insert({ SCENE_ID::TITLE, std::make_unique<Scene_Title>("Title") });
		sceneList_.insert({ SCENE_ID::MENU, std::make_unique<Scene_Menu>("Menu") });
		sceneList_.insert({ SCENE_ID::PLAY, std::make_unique<Scene_Play>("Play") });
		sceneList_.insert({ SCENE_ID::RESULT, std::make_unique<Scene_Result>("Result") });
	}
}