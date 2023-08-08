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
	const static XMFLOAT2  IMAGE_OFFSET = { 900.0f,1000 };
	const static float  IMAGE_RATIO = 5.0f;
}

SelectUI::SelectUI(Object* parent)
	:GameObject(parent, "SelectUI"),
	moveDir_(0),
	state_(SELECT_STATE::STATE_INPUT),
	buttonNum_(0),
	moveTime_(0),
	playCount_(1),
	countTextNum_(-1)
{
}

SelectUI::~SelectUI()
{
}

void SelectUI::Initialize()
{
	//テキスト
	{
		Text text1;
		text1.SetText("チキンレース");
		XMFLOAT3 pos = { 500,-1000.0f,0 };
		basePosList_.push_back(pos);
		text1.SetPosition({ pos.x, pos.y });
		text1.SetAlinmentType(LEFT_CENTER);
		text1.SetFont("GAGAGAGA FREE", 0, 3);
		moveUIList_.push_back((int)AddComponent<Text>(text1));
		
	}
	//テキスト2
	{
		Text text2;
		text2.SetText("Stage02");
		XMFLOAT3 pos = { 500.0f,-1500.0f,0 };
		basePosList_.push_back(pos);
		text2.SetPosition({ pos.x, pos.y });
		text2.SetAlinmentType(LEFT_CENTER);
		text2.SetFontStyle(DWRITE_FONT_STYLE_ITALIC, 0, 3);
		text2.SetFontWeight(DWRITE_FONT_WEIGHT_BOLD, 0, 5);
		moveUIList_.push_back((int)AddComponent<Text>(text2));
	}
	//テキスト3
	{
		Text text3;
		text3.SetText("Stage03");
		XMFLOAT3 pos = { 500.0f,-2000.0f,0 };
		basePosList_.push_back(pos);
		text3.SetPosition({ pos.x, pos.y });
		moveUIList_.push_back((int)AddComponent<Text>(text3));
	}

	//プレイヤーのカウントテキスト
	{
		Text countText("", "りいてがき筆", { 0,0,500,50 });
		countText.SetText("< "+std::to_string(playCount_)+" >");
		countText.SetPosition({ 2400,-1600 });
		countTextNum_=(int)AddComponent<Text>(countText);

	}

	//画像1
	{
		Image image1;
		image1.Load("Assets\\Image\\Image_Stage1.png");

		image1.SetPositionAtPixel({ -basePosList_[0].x + IMAGE_OFFSET.x,
									(basePosList_[0].y +IMAGE_OFFSET.y) * IMAGE_RATIO,
									basePosList_[0].z });
		AddComponent<Image>(image1);
	}
	//画像2
	{

		Image image2;
		image2.Load("Assets\\Image\\Image_Stage2.png");
		
		image2.SetPositionAtPixel({ -basePosList_[1].x + IMAGE_OFFSET.x,
									(basePosList_[1].y+IMAGE_OFFSET.y)* IMAGE_RATIO,
								    basePosList_[1].z });
		AddComponent<Image>(image2);
	}
	//画像3
	{

		Image image3;
		image3.Load("Assets\\Image\\Image_Stage3.png");
		
		image3.SetPositionAtPixel({ -basePosList_[2].x + IMAGE_OFFSET.x,
									(basePosList_[2].y+IMAGE_OFFSET.y)* IMAGE_RATIO,
									basePosList_[2].z });
		AddComponent<Image>(image3);
	}
	



}
void SelectUI::Input()
{
	//ボタンの処理
	moveDir_ = 0;
	//上に移動
		PlayerCount(Input::GetPadAnyDown());

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
		//動かしたセレクト画面の位置を確定させる
		for (XMFLOAT3& i : basePosList_)
		{
			i.y += MOVE * moveDir_;
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
	case SELECT_STATE::STATE_SELECTED:
		break;	
	default:
		break;
	}
}

void SelectUI::PlayerCount(const int& padButton)
{
	switch (padButton)
	{
	case XINPUT_GAMEPAD_DPAD_LEFT:
		if (playCount_ > 0)
		{
			playCount_--;
			GetComponent<Text>(countTextNum_).SetText("< " + std::to_string(playCount_) + " >");
		}
		break;
	case XINPUT_GAMEPAD_DPAD_RIGHT:
		if (playCount_ < Input::GetConnectedControllerCount())
		{
			playCount_++;
			GetComponent<Text>(countTextNum_).SetText("< " + std::to_string(playCount_) + " >");
		}
		break;
	default:
		break;
	}
}

void SelectUI::MoveButton(float ratio)
{
	float delta = MOVE * ratio * moveDir_;
	int i = 0;
	for (int& num : moveUIList_)
	{
		GetComponent<Image>(num).
				     SetPositionAtPixel({ -basePosList_[num].x + IMAGE_OFFSET.x,
										  (basePosList_[num].y+IMAGE_OFFSET.y + delta)*IMAGE_RATIO,
										   basePosList_[num].z });
		GetComponent<Text>(num).
					 SetPosition({ basePosList_[num].x,
								   basePosList_[num].y+delta });
		//i++;
	}
	//i = 0;
	//for (Entity& entity : GetComponentList<Text>())
	//{
	//	i++;
	//}
}

void SelectUI::PushedButton(int buttonNum)
{
	state_ = SELECT_STATE::STATE_SELECTED;
	newSceneManager::ChangeScene(SCENE_ID::PLAY);
}

void SelectUI::Release()
{
}
