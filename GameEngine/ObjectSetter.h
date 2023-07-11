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
	/// jsonƒtƒ@ƒCƒ‹“Ç‚İ‚Ş
	/// </summary>
	/// <param name="fileName"></param>
	/// <returns>¬Œ÷‚µ‚½ê‡true,¸”s‚µ‚½‚çfalse</returns>
	bool DataLoad(std::string fileName);
	void SetObject();





};

