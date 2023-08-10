#pragma once
#include"Engine/GameObject/GameObject.h"
#include <map>

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
	unsigned short playCount_;

	int countTextNum_;
	int moveTime_;
	int inputInterval_;
	void Input();
	void Move();
	std::vector<int> moveUIList_;
	std::vector<XMFLOAT3> basePosList_;

	std::map<int, std::vector<int>::iterator> Selection_;

	void ItrIncrement();
	void ItrDecrement();
	void UIPositioning();

public:
	SelectUI(Object* parent);
	~SelectUI();
	void Initialize() override;
	void Update() override;
	void PlayerCount(const int& padButton);
	void MoveButton(float ratio);
	void PushedButton(int buttonNum);
	void Release() override;
};

