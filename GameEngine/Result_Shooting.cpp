#include "Result_Shooting.h"
#include"InterSceneData.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/Systems/ImageSystem.h"
#include"Engine/ResourceManager/json.hpp"
#include<fstream>
#include"Engine/DirectX_11/Input.h"
#include"Engine/newSceneManager.h"

namespace
{
	const float SHOWTIME = 3.0f;
	const XMFLOAT2 RETURN_TEXT_POS = { 750,700 };
}

Result_Shooting::Result_Shooting(Object* parent)
	:Result_Single(parent,"Result_Shooting"),
	status_(CountStatus::STAY),
	count_(0),resultTextNum_(0),
	interval_(0)
{
}

Result_Shooting::~Result_Shooting()
{
}

void Result_Shooting::Initialize()
{
	time_ = std::make_unique<Time::Watch>();
	time_->UnLock();
	Text text("Œ‹‰Ê", "‚è‚¢‚Ä‚ª‚«•M", { 0,0,200,50 });
	text.SetPosition({ 750,0 });
	text.SetTextSize(100);
	AddComponent<Text>(text);

	score_ = InterSceneData::GetData<int>("ResultData");
	Text scoreText("—‚Æ‚µ‚½” 0", "‚è‚¢‚Ä‚ª‚«•M", {0,0,500,50});
	scoreText.SetPosition( {500,500 });
	resultTextNum_ = AddComponent<Text>(scoreText);
	{
		Image image;
		image.Load("Assets/Image/Shooting_ResultBackGroundImage.jpg");
		AddComponent<Image>(image);
	}

	interval_ = Clamp<float>((SHOWTIME / (float)score_),0.2f,1.0f);
}

void Result_Shooting::Update()
{
	switch (status_)
	{
	case CountStatus::STAY:
		Stay();
		break;
	case CountStatus::SHOW:
		ShowResult();
		break;
	case CountStatus::FINISH:
		Finish();
		break;
	}
}

void Result_Shooting::Stay()
{
	if (time_->GetSeconds<float>() >= 1.0f)
		status_ = CountStatus::SHOW;
}

void Result_Shooting::ShowResult()
{

	if ((interval_ * count_) <= time_->GetSeconds<float>()-1.0f)
	{
		count_++;
		GetComponent<Text>(resultTextNum_).SetText("—‚Æ‚µ‚½” " + std::to_string(count_));
	}
	if (count_ > score_)
	{
		GetComponent<Text>(resultTextNum_).SetText("—‚Æ‚µ‚½” " + std::to_string(score_));
		time_->Lock();
		ShowCommand();
		status_ = CountStatus::FINISH;
	}
}

void Result_Shooting::ShowCommand()
{
	Text retryText("‚à‚¤ˆê“x", "‚è‚¢‚Ä‚ª‚«•M", { 0,0,500,50 });
	retryText.SetRatio(0.7f, 0.7f);
	retryText.SetTextSize(48);
	AddComponent<Text>(retryText);

	Text toMenuText_("ƒƒjƒ…[‚Ö", "‚è‚¢‚Ä‚ª‚«•M", { 0,0,500,50 });
	toMenuText_.SetRatio(0.7f, 0.85f);
	toMenuText_.SetTextSize(48);
	AddComponent<Text>(toMenuText_);

	Image image;
	image.Load("Assets\\Image\\Buttons\\BTN_A.png", "Result_Multi");
	AddComponent<Image>(image);
	image.Load("Assets\\Image\\Buttons\\BTN_B.png", "Result_Multi");
	AddComponent<Image>(image);
}

void Result_Shooting::Finish()
{
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
		newSceneManager::ChangeScene(SCENE_ID::MENU);
}

void Result_Shooting::Release()
{
}
