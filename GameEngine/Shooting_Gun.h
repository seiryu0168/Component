#pragma once
#include"Engine/GameObject/GameObject.h"
class Shooting_Gun : public GameObject
{
	unsigned short playerNum_;
	XMVECTOR frontVec_;
public:
	Shooting_Gun(Object* parent);
	~Shooting_Gun();
	void Initialize() override;
	void Update() override;
	void Shot(const XMVECTOR& dir);
	XMVECTOR GetShotPos();
	void SetDraw(bool isDraw);
	void SetPlayerNum_(const unsigned short& num) { playerNum_ = num; }
	void Release() override;
};

