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
	/// jsonファイル読み込む
	/// </summary>
	/// <param name="fileName"></param>
	/// <returns>成功した場合true,失敗したらfalse</returns>
	bool DataLoad(std::string fileName);
	void SetObject();





};

