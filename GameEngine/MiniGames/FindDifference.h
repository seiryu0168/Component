#pragma once
#include "Framework.h"

//選択肢
enum class CHOICES
{
	ABOVE,
	UNDER,
	LEFT,
	RIGHT
};

class FindDifference : public Framework
{
public:
	FindDifference(Object* parent);
	~FindDifference();

	void Initialize() override;
	void Release() override;

	/// <summary>Player側から入力を取得する</summary>
	/// <param name="select">選択した手</param>
	/// <param name="Playernum">プレイヤーの番号</param>
	void SendData(CHOICES select, int Playernum);
};

