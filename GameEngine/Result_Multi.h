#pragma once
#include"Engine/GameObject/GameObject.h"
class Result_Multi : public GameObject
{
	int Winner_;
	bool isChange_;
public:
	Result_Multi(Object* parent) : Result_Multi(parent, "Result_Multi") {}
	Result_Multi(Object* parent, const std::string& name) : GameObject(parent, name), Winner_(), isChange_(false){}
	virtual ~Result_Multi() {}

	void Initialize() override;
	//リザルト画面に載せる情報を増やすときに使う
	virtual void MoreInfo() {}
	void Update() override;
	void Draw() override;
	void Release() override;
};

