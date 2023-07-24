#pragma once
#include"Engine/GameObject/GameObject.h"
class SelectUI : public GameObject
{
private:
	enum class SELECT_STATE
	{
		STATE_INPUT = 0,
		STATE_MOVE,
		STATE_SELECTED,
	};
	short moveDir_;
	SELECT_STATE state_;
	int buttonCount_;
	int buttonNum_;
	int moveTime_;
	int inputInterval_;
	void Input();
	void Move();
	std::vector<XMFLOAT3> basePosList_;
public:
	SelectUI(Object* parent);
	~SelectUI();
	void Initialize() override;
	void Update() override;
	void MoveButton(float ratio);
	void PushedButton();
	void Release() override;
};

