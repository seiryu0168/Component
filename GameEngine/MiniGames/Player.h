#pragma once
#include "../Engine/GameObject/GameObject.h"

//プレイヤーの基底クラス
class Player : public GameObject
{
	//プレイヤーの番号
	int PlayerNum_;
public:
	Player(Object* parent, const std::string& name);
	virtual ~Player() {}
};

