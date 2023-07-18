#include "ModelManager_ECSver.h"

namespace ModelManager_ECSver
{
	std::unordered_map<std::string, std::shared_ptr<Fbx>> models_;

	std::shared_ptr<Fbx> ModelManager_ECSver::Load(std::string fileName)
	{
		if (models_.find(fileName) != models_.end())
		{
			return models_.find(fileName)->second;
		}

		std::shared_ptr<Fbx> pFbx = std::make_shared<Fbx>();
		if (FAILED(pFbx->Load(fileName)))
		{
			return nullptr;
		}
		models_.insert({ fileName,pFbx });
		return pFbx;
	}
}