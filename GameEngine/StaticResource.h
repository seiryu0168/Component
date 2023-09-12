#pragma once
#include"Engine/Components/Image.h"
#include"Engine/Components/Text.h"
#include<unordered_map>
#include<string>
namespace StaticResource
{	
	void AddImage(std::string imageName, Image image);
	Image GetImage(std::string imageName);
	void StaticImageLoad(std::string imageName, std::string fileName,int cameraNum,int layerNum);
	void AddText(std::string textName,Text text);
	Text GetText(std::string textName);

	void RemoveImage(std::string imageName);
	void RemoveText(std::string textName);

	void Draw();
	void Release();
};

