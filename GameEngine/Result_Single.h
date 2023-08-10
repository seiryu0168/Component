#pragma once
#include"Engine/GameObject/GameObject.h"
template<typename T>
class Result_Single : public GameObject
{
protected:
	T score_;
public:
	Result_Single(Object* parent, std::string name)
		:GameObject(parent, name) {}
	~Result_Single() {};

};

