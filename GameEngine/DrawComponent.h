#pragma once
#include"Component.h"
#include<list>
#include"Engine/GameObject/GameObject.h"
#include"Engine/ResourceManager/Text.h"
#include"Engine/DirectX_11/Particle.h"
#include"Test_Model_ECSver.h"
#include"Coordinator.h"

enum class DrawType
{
	TYPE_MODEL=0,
	TYPE_PARTICLE,
	TYPE_TEXT,

};
class DrawComponent
{
	DrawType type_;
	Entity drawEntity_;
	std::string typeName_;
	GameObject* attachObject_;
public:
	DrawComponent();
	DrawComponent(GameObject* object);
	virtual ~DrawComponent() {};
	template<typename T>
	void SetDrawObject(T drawObject)
	{
		typeName_ = typeid(T).name();
		std::string name= typeid(T).name();
		SetDrawType(name);
		drawEntity_ = Coordinator::CreateEntity();
		Coordinator::AddComponent<T>(drawEntity_, drawObject);
	}

	auto GetDrawObjdect(std::string name);
	void SetDrawType(std::string name);
	void SetAttachObject(GameObject* object);
	void Draw();

};
