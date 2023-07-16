#pragma once
#include"DrawComponent.h"
class Draw2DComponent : public DrawComponent
{
	//DrawType type_;
	//Entity drawEntity_;
	//std::string typeName_;
	//GameObject* attachObject_;
public:
	Draw2DComponent();
	Draw2DComponent(GameObject* object);
	//template<typename T>
	//void SetDrawObject(T drawObject)
	//{
	//	typeName_ = typeid(T).name();
	//	std::string name = typeid(T).name();
	//	SetDrawType(name);
	//	drawEntity_ = Coordinator::CreateEntity();
	//	Coordinator::AddComponent<T>(drawEntity_, drawObject);
	//}

	//auto GetDrawObjdect(std::string name);
	//void SetDrawType(std::string name);
	//void SetAttachObject(GameObject* object);
	//virtual void Draw() {};
};

