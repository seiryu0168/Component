#pragma once
#include"Engine/GameObject/GameObject.h"
#include"Engine/ResourceManager/json.hpp"
	using json = nlohmann::json;
class ObjectSetter
{
private:
	json jsonFile_;
public:
	ObjectSetter();
	~ObjectSetter();
	/// <summary>
	/// json�t�@�C���ǂݍ���
	/// </summary>
	/// <param name="fileName"></param>
	/// <returns>���������ꍇtrue,���s������false</returns>
	bool DataLoad(std::string fileName);
	void SetObject();





};

