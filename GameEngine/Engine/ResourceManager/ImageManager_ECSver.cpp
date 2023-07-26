#include "ImageManager_ECSver.h"
namespace ImageManager_ECSver
{

		std::unordered_map<std::string, std::shared_ptr<Sprite>> images_;
    std::shared_ptr<Sprite> Load(const std::string& fileName)
    {	
			if (auto itr = images_.find(fileName); itr != images_.end())
			{
				return itr->second;
			}

			std::shared_ptr<Sprite> image = std::make_shared<Sprite>();
			if (FAILED(image->Load(fileName)))
			{
				return nullptr;
			}
			
			images_.insert({ fileName,image });


			return image;
    }
	void Release()
	{
		images_.clear();
	}
}
