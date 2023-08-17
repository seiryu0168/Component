#include "Result_Multi.h"
#include "Engine/Components/Text.h"
#include "Engine/Components/Image.h"
#include "Engine/DirectX_11/Input.h"
#include "Engine/newSceneManager.h"
#include "InterSceneData.h"
#include <format>

namespace
{
	static const int DRAW = -1;
}

void Result_Multi::Initialize()
{
	Winner_ = InterSceneData::GetData<int>("ResultData");
	Text text;
	if (Winner_ != DRAW)
		text.SetText(std::format("プレイヤー{:d} Win!", Winner_ + 1));
	else
		text.SetText("DRAW");
	text.SetRatio(0.25f, 0.25f);
	text.SetTextSize(90);
	AddComponent<Text>(text);

	Text t;
	t.SetText("もう一度");
	t.SetRatio(0.7f, 0.7f);
	t.SetTextSize(48);
	AddComponent<Text>(t);

	Text text_;
	text_.SetText("メニューへ");
	text_.SetRatio(0.7f, 0.85f);
	text_.SetTextSize(48);
	AddComponent<Text>(text_);

	Image image;
	image.Load("Assets\\Image\\Buttons\\BTN_A.png", "Result_Multi");
	AddComponent<Image>(image);
	image.Load("Assets\\Image\\Buttons\\BTN_B.png", "Result_Multi");
	AddComponent<Image>(image);
}

void Result_Multi::Update()
{
	switch (Input::GetPadAnyButton())
	{
	case XINPUT_GAMEPAD_A:
		newSceneManager::ChangeScene(SCENE_ID::PLAY);
		break;
	case XINPUT_GAMEPAD_B:
		newSceneManager::ChangeScene(SCENE_ID::MENU);
		break;
	default:
		break;
	}
}

void Result_Multi::Draw()
{
}

void Result_Multi::Release()
{
}
