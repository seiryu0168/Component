#include "Result_Shooting.h"
#include"InterSceneData.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/Systems/ImageSystem.h"

#include"Engine/DirectX_11/Input.h"
#include"Engine/newSceneManager.h"

namespace
{
	const float SHOWTIME = 3.0f;
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
	Text text("結果", "りいてがき筆", { 0,0,200,50 });
	text.SetPosition({ 1500,0 });
	text.SetTextSize(100);
	AddComponent<Text>(text);

	score_ = InterSceneData::GetData<int>("ResultData");
	Text scoreText("落とした数 0", "りいてがき筆", {0,0,500,50});
	scoreText.SetPosition({ 1000,-1000 });
	resultTextNum_ = AddComponent<Text>(scoreText);

	Image image;
	image.Load("Assets/Image/Buttons/BTN_A.png");
	image.SetPosition({ 0,-0.5,0 });
	image.SetAlpha(0);
	buttonImageNum_ = AddComponent<Image>(image);


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
		GetComponent<Text>(resultTextNum_).SetText("落とした数 " + std::to_string(count_));
	}
	if (count_ > score_)
	{
		GetComponent<Text>(resultTextNum_).SetText("落とした数 " + std::to_string(score_));
		GetComponent<Image>(buttonImageNum_).SetAlpha(1.0f);
		time_->Lock();
		status_ = CountStatus::FINISH;
	}
}

void Result_Shooting::Finish()
{
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
		newSceneManager::ChangeScene(SCENE_ID::MENU);
}

void Result_Shooting::Release()
{
}
