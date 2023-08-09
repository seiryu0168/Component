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
		//�������O�̃f�[�^������
		for (Data& data : interScenedatas_)
		{
			//�������炻�̃f�[�^������������
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
		//�������O�̃f�[�^������
		for (auto itr=interScenedatas_.begin();itr!=interScenedatas_.end();)
		{
			//�������炻�̃f�[�^������������
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
		//�������O�̃f�[�^������
		for (Data& data : interScenedatas_)
		{
			//�������炻�̃f�[�^������������
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