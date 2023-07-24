#pragma once
#include "../Engine/GameObject/Object.h"
#include "../Engine/Time.h"

//ミニゲームの枠組みとなる基底クラス
class Framework : public Object
{
protected:
	int Players_;	//プレイ人数
	Time::Watch GameTime_;	//ミニゲームの時間

	//プレイ人数分だけプレイヤーの生成を行う
	template<class T>
	void PlayerInitialize()
	{
		for (int i = 0; i < Players_; i++)
		{
			Instantiate<T>(this);
		}
	}

	//ミニゲームが終了したときに呼び出す関数
	void Finish();
public:
	Framework(Object* parent, const std::string& name);
	virtual ~Framework();
};

