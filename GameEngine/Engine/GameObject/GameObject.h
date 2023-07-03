#pragma once
#include<string>
#include<typeinfo>
#include<memory>
#include<list>
#include"../../Object.h"
#include"../Collider/BoxCollider.h"
#include"../Collider/SphereCollider.h"
#include"../Collider/OBBCollider.h"
#include"../../TransformComponent.h"
#include"../../DrawComponent.h"
#include<vector>
#include"Transform.h"

class GameObject : public Object
{
	//friend class Collider;
	//friend class Component;
protected:

	bool drawFlag_;						//描画するかどうか
	Transform* transform_;
	//std::list<Component*> componentList_;

public:
	GameObject();
	GameObject(Object* parent, const std::string& name);
	virtual ~GameObject() {};

	bool IsDraw() { return drawFlag_; }
	void SetDrawFlag(bool flag) { drawFlag_ = flag; }

	///////////////////////////衝突関連の関数////////////////////////
	virtual void OnCollisionEnter(GameObject* pTarget) {};
	virtual void OnCollisionExit(GameObject* pTarget) {};
	virtual void OnCollisionStay(GameObject* pTarget) {};
	void Collision(GameObject* pTarget);
	void CheckLillCollider(GameObject*);
	//void AddCollider(Collider* collider);
	//void DelCollider(const GameObject& obj);

///////////////////////////各セッターゲッター//////////////////////////////////////
	void SetTag(std::string tagName) { objectTag_ = tagName; }
	void SetActive(bool status);
	void SetUpdate(bool status) { isUpdate_ = status; };
	void SetStart(bool status) { startFlag_ = status; }
	void SetParent(GameObject* parent);
	std::string GetTag() { return objectTag_; }

	Transform* GetTransform();
	XMFLOAT3  GetPosition();
	XMFLOAT3  GetRotate();
	XMFLOAT3  GetScale();

	//指定した座標に回転させる行列を作る関数
	XMMATRIX LookAtMatrix(XMFLOAT3 target, XMVECTOR frontVec, XMVECTOR upVec = XMVectorSet(0, 1, 0, 0));
	XMMATRIX    GetWorldMatrix();

	//ワールド座標取得
	XMFLOAT3    GetWorldPosition() { return Transform::Float3Add(((GameObject*)GetParent())->transform_->position_, transform_->position_); }

};