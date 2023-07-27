#pragma once
#include "Framework.h"

class CommandMemory : public Framework
{
	std::vector<int> cmList_;	//コマンドの配列
	std::vector<int>::iterator itr_;	//コマンドの配列に対するイテレータ
	int NowPlayer_;				//現在操作中のプレイヤー

	Text* text_;
public:
	CommandMemory(Object* parent);
	~CommandMemory();

	void Initialize() override;

	//送られたボタンのidが合っているか検証する
	void sendCommand(int Button, int Playerid);


};

