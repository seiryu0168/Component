#pragma once
#include"Engine/GameObject/GameObject.h"
#include"Engine/ResourceManager/json.hpp"
	using json = nlohmann::json;
class ObjectSetter
{
private:
	json jsonFile_;
	Object* sceneObject_;
public:
	ObjectSetter();
	ObjectSetter(Object* sceneObject);
	~ObjectSetter();
	/// <summary>
	/// json�t�@�C���ǂݍ���
	/// </summary>
	/// <param name="fileName"></param>
	/// <returns>���������ꍇtrue,���s������false</returns>
	bool DataLoad(std::string fileName);
	void SetObject();





};

