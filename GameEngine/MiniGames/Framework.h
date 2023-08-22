#pragma once
#include "../Engine/GameObject/Object.h"
#include "../Engine/Time.h"
#include "../Engine/Components/Text.h"

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
			auto p = Instantiate<T>(this);
			p->SetID(i);
		}
	}

	//StaticUpdateで呼び出すとpause処理が可能になる
	void Pause();
public:
	Framework(Object* parent, const std::string& name);
	virtual ~Framework();
};

