#pragma once
#include"Engine/GameObject/GameObject.h"
#include"Engine/ResourceManager/json.hpp"
#include"Engine/SAFE_DELETE_RELEASE.h"
#include<vector>
using json = nlohmann::json;

namespace InterSceneData
{
	void AddData(std::string dataName,const json& jsonData);
	void DeleteData(std::string dataName);
	json& GetData(const std::string& dataName);
};

