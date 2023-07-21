#include "TextureManager.h"
#include"../SAFE_DELETE_RELEASE.h"
namespace TextureManager
{
	struct textureData
	{
		std::shared_ptr<Texture> pTexture_;
		std::string fileName_;
		textureData() : pTexture_(nullptr), fileName_("") {}
	};
	std::vector<std::shared_ptr<textureData>> textureList_;
}

int TextureManager::Load(const std::string& fileName)
{
	std::unique_ptr<textureData> pTextureData = std::make_unique<textureData>();
	pTextureData->fileName_ = fileName;
	pTextureData->pTexture_ = nullptr;
	
	for (auto&& itr : textureList_)
	{
		if (fileName == itr->fileName_)
		{
			pTextureData->pTexture_ = itr->pTexture_;

			break;
		}
	}
	if (pTextureData->pTexture_ == nullptr)
	{
		pTextureData->pTexture_ = std::make_shared<Texture>();
		pTextureData->pTexture_->Load(pTextureData->fileName_);
	}
	textureList_.push_back(std::move(pTextureData));
	return (int)textureList_.size() - 1;
}

Texture* TextureManager::GetTexture(int textureHandle)
{
	return textureList_[textureHandle]->pTexture_.get();
}

void TextureManager::Release()
{
	//for (auto&& itr : textureList_)
	//{
	//	bool isRef = false;
	//	for (int j = i + 1; j < textureList_.size(); j++)
	//	{
	//		if (itr->pTexture_ == textureList_[j]->pTexture_)
	//		{
	//			isRef = true;
	//		}
	//	}
	//	if (isRef==false)
	//	{
	//		//SAFE_DELETE(textureList_[i]->pTexture_);
	//	}
	//	//SAFE_DELETE(textureList_[i]);
	//}

	textureList_.clear();
}