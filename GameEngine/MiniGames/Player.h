#pragma once
#include "../Engine/GameObject/GameObject.h"

//�v���C���[�̊��N���X
class Player : public GameObject
{
	//�v���C���[�̔ԍ�
	int PlayerNum_;
public:
	Player(Object* parent, const std::string& name);
	virtual ~Player() {}
};

