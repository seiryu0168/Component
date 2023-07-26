#include "InterSceneData.h"
#include"Engine/SAFE_DELETE_RELEASE.h"
#include<vector>
namespace InterSceneData
{
    struct Data
    {
        std::string dataName = "";
        json data;
    };

    std::vector<Data> datas_;
    std::vector<Data*> dataList_;


    void AddData(const std::string& dataName,const json& jsonData)
    {
        for (Data& data : datas_)
        {
            if (data.dataName == dataName)
                return;
        }
        Data data;
        data.dataName = dataName;
        data.data = jsonData;
        datas_.push_back(data);
    }

    void DeleteData(const std::string& dataName)
    {
        for (auto itr = datas_.begin(); itr < datas_.end();)
        {
            if ((*itr).dataName == dataName)
            {
                itr = datas_.erase(itr);
                return;
            }
            itr++;
        }
    }

    json& GetData(const std::string& dataName)
    {
        for (Data& d :datas_)
        {
            if (d.dataName == dataName)
                return d.data;
        }
    }
}
