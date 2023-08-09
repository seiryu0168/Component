#pragma once
#include"Engine/GameObject/GameObject.h"
#include"Engine/ResourceManager/json.hpp"
#include"Engine/SAFE_DELETE_RELEASE.h"
#include<vector>
#include<variant>
using json = nlohmann::json;

namespace InterSceneData
{
	extern struct Data
	{
		std::variant<bool, std::string, short, int, float > value_;
		std::string dataName_;
	};
	extern std::vector<Data> interScenedatas_;
	template<typename T>
	void AddData(std::string dataName, T num)
	{
		//同じ名前のデータを検索
		for (Data& data : interScenedatas_)
		{
			//あったらそのデータを書き換える
			if (data.dataName_ == dataName)
			{
				data.value_ = num;
				return;
			}
		}

		Data data;
		data.dataName_ = dataName;
		data.value_ = num;
		interScenedatas_.push_back(data);
	}
	template<typename T>
	void DeleteData(std::string dataName)
	{
		//同じ名前のデータを検索
		for (auto itr=interScenedatas_.begin();itr!=interScenedatas_.end();)
		{
			//あったらそのデータを書き換える
			if (itr->dataName_ == dataName && typeid(itr->value_).name() == typeid(T).name())
			{
				itr=interScenedatas_.erase(itr);
				break;
			}
		}
	}
	//void DataInput()
	template<typename T>
	T& GetData(const std::string& dataName)
	{
		//同じ名前のデータを検索
		for (Data& data : interScenedatas_)
		{
			//あったらそのデータを書き換える
			if (data.dataName_ == dataName)
			{
				T& a= std::get<T>(data.value_);
				return a;
				//return data.value_;
			}
		}
		
		//return rtn;
	}

};