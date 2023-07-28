#include "SelectUI.h"
#include"Engine/Systems/ImageSystem.h"
#include"Easing.h"
#include"Engine/DirectX_11/Input.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/newSceneManager.h"
namespace
{
	const static float	MOVE = -500.0f;
	const static int	MAX_MOVE_TIME = 11;
	const static XMINT2 MAX_SELECT = { 0,4 };
	const static float  IMAGE_OFFSET = 1500.0f;
}

SelectUI::SelectUI(Object* parent)
	:GameObject(parent,"SelectUI"),
	moveDir_(0),
	state_(SELECT_STATE::STATE_INPUT),
	buttonNum_(0),
	moveTime_(0)
{
}

SelectUI::~SelectUI()
{
}

void SelectUI::Initialize()
{
	//画像1
	{
		Image image1;
		image1.Load("Assets\\Image\\Effect01.png");
		XMFLOAT3 pos = { -900,1000.0f,0 };
		basePosList_.push_back(pos);
		pos.x += IMAGE_OFFSET;
		image1.SetPositionAtPixel(pos);
		AddComponent<Image>(image1);
	}
	//画像2
	{

		Image image2;
		image2.Load("Assets\\Image\\Smoke.png");
		XMFLOAT3 pos = { -900.0f,0.0f,0 };
		basePosList_.push_back(pos);
		pos.x += IMAGE_OFFSET;
		image2.SetPositionAtPixel(pos);
		AddComponent<Image>(image2);
	}
	//画像3
	{

		Image image3;
		image3.Load("Assets\\Image\\Fire.png");
		XMFLOAT3 pos = { -900.0f,-1000.0f,0 };
		basePosList_.push_back(pos);
		pos.x += IMAGE_OFFSET;
		image3.SetPositionAtPixel(pos);
		AddComponent<Image>(image3);
	}
	//テキスト
	{
		Text text1;
		text1.SetText("デアイカ");
		text1.SetPosition({ basePosList_[0].x, basePosList_[0].y });
		text1.SetFont("ShotaroV3 KT", 0, 5);
		AddComponent<Text>(text1);
	}
	//テキスト2
	{
		Text text2;
		text2.SetText("Stage02");
		text2.SetPosition({ basePosList_[1].x, basePosList_[1].y });
		text2.SetFontStyle(DWRITE_FONT_STYLE_ITALIC, 0, 3);
		text2.SetFontWeight(DWRITE_FONT_WEIGHT_BOLD, 0, 5);
		AddComponent<Text>(text2);
	}
	//テキスト3
	{
		Text text3;
		text3.SetText("Stage03");
		text3.SetPosition({ basePosList_[2].x, basePosList_[2].y });
		AddComponent<Text>(text3);
	}

}
void SelectUI::Input()
{
	//ボタンの処理
	moveDir_ = 0;
	//上に移動
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_DPAD_UP))
	{
		moveDir_ = 1;
		////ボタンが
		if (buttonNum_ > MAX_SELECT.x)
		{
			buttonNum_--;
			state_ = SELECT_STATE::STATE_MOVE;
		}
	}
	//下に移動
	else if (Input::IsPadButtonDown(XINPUT_GAMEPAD_DPAD_DOWN))
	{
		moveDir_ = -1;

		////ボタンの番号が最後尾じゃなかったら移動モードに切り替える
		if (buttonNum_ < MAX_SELECT.y)
		{
			buttonNum_++;
			state_ = SELECT_STATE::STATE_MOVE;
		}
	}
	else if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
	{
		PushedButton(buttonNum_);
	}


}

void SelectUI::Move()
{
	moveTime_++;
	moveTime_ = min(moveTime_, MAX_MOVE_TIME);
	//動き終わったか
	if (moveTime_ >= MAX_MOVE_TIME)
	{
		state_ = SELECT_STATE::STATE_INPUT;
		moveTime_ = 0;
		int i = 0;
		//動かしたセレクト画面の位置を確定させる
		for (Entity& entity : GetComponentList<Image>())
		{
			basePosList_[i].y += MOVE * moveDir_;
			Coordinator::GetComponent<Image>(entity).
						 SetPositionAtPixel({ basePosList_[i].x + IMAGE_OFFSET,
						                      basePosList_[i].y,
						                      basePosList_[i].z });
			i++;
		}
		i = 0;
		for (Entity& entity : GetComponentList<Text>())
		{
			Coordinator::GetComponent<Text>(entity).
						 SetPosition({ basePosList_[i].x,
									   basePosList_[i].y });
			i++;
		}
		return;
	}
	//セレクト画面を動かす
	MoveButton(Easing::EaseInCubic((float)moveTime_ / (float)(MAX_MOVE_TIME - 1)));
}

void SelectUI::Update()
{
	switch (state_)
	{
	case SELECT_STATE::STATE_INPUT:
		Input();
		break;
	case SELECT_STATE::STATE_MOVE:
		Move();
		break;
	default:
		break;
	}
}

void SelectUI::MoveButton(float ratio)
{
	float delta = MOVE * ratio * moveDir_;
	int i = 0;
	for (Entity& entity : GetComponentList<Image>())
	{
		Coordinator::GetComponent<Image>(entity).
				     SetPositionAtPixel({ basePosList_[i].x + IMAGE_OFFSET,
										  basePosList_[i].y + delta,
										  basePosList_[i].z });
		i++;
	}
	i = 0;
	for (Entity& entity : GetComponentList<Text>())
	{
		Coordinator::GetComponent<Text>(entity).
					 SetPosition({ basePosList_[i].x,
								   basePosList_[i].y+delta });
		i++;
	}
}

void SelectUI::PushedButton(int buttonNum)
{

	newSceneManager::ChangeScene(SCENE_ID::MENU);
}

void SelectUI::Release()
{
}
