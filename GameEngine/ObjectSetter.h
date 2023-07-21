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
	/// jsonファイル読み込む
	/// </summary>
	/// <param name="fileName"></param>
	/// <returns>成功した場合true,失敗したらfalse</returns>
	bool DataLoad(const std::string& fileName);
	void SetObject();
	void DeleteObject();





};

