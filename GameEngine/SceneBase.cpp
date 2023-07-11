#include"SceneBase.h"

#include"PhysicsSystem.h"
#include"TransformSystem.h"
#include"ColliderSystem.h"
#include"ModelSystem.h"
#include"Coordinator.h"


SceneBase::SceneBase()
{

	setter_ = ObjectSetter(rootObject_);
}

void SceneBase::SceneInitialize()
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

void SceneBase::ObjectSet()
{
	setter_.SetObject();
}

void SceneBase::SetFile(std::string name)
{
	fileName_ = name;
}

void SceneBase::Update()
{
	rootObject_->UpdateSub();
}
