#pragma once
#include"Component.h"
#include<list>
#include"Engine/GameObject/GameObject.h"
//#include"Test_Model_ECSver.h"
#include"Coordinator.h"

enum class DrawType
{
	TYPE_MODEL=0,
	TYPE_PARTICLE,

};
class DrawComponent
{
	Entity drawEntity_;
	
	GameObject* attachObject_;
public:
	DrawComponent();
	DrawComponent(GameObject* object);
	template<typename T>
	void SetDrawObject(T drawObject)
	{
		drawEntity_ = Coordinator::CreateEntity();
		Coordinator::AddComponent<T>(drawEntity_, drawObject);
	}	

	//auto GetType()
	//{
	//	//return a;
	//
	//}
	void SetAttachObject(GameObject* object);
	void Draw();

};
