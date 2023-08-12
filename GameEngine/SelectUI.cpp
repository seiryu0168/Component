#include "SelectUI.h"
#include"Engine/Systems/ImageSystem.h"
#include"Easing.h"
#include"Engine/DirectX_11/Input.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/newSceneManager.h"
#include"InterSceneData.h"
#include"Engine/ResourceManager/CsvReader.h"

#include "ImGui/imgui.h"
namespace
{
	const static float	MOVE = 0.35f;
	const static int	MAX_MOVE_TIME = 11;
	const static XMFLOAT2  IMAGE_OFFSET = { 0.55f,-0.49f };
	const static float  IMAGE_RATIO = -10.0f;
	const static int	TEXT_SIZE_DEFAULT = 54;
	const static int	TEXT_SIZE_PICKUP = 90;

	//それぞれのテキストの位置
	const std::map<int, XMFLOAT2> Position = {
		{-2, {0.15f, -0.2f}},
		{-1, {0.15f, 0.15f}},
		{ 0, {0.15f, 0.5f}},
		{ 1, {0.15f, 0.85f}},
		{ 2, {0.15f, 1.2f}},
	};

	const static XMFLOAT3 POSITION_DEFAULT = { -9999,-9999,0 };
}

SelectUI::SelectUI(Object* parent)
	:GameObject(parent, "SelectUI"),
	moveDir_(0),
	state_(SELECT_STATE::STATE_INPUT),
	buttonNum_(0),
	moveTime_(0),
	playCount_(1),
	countTextNum_(-1),
	buttonCount_(0),
	inputInterval_(0),
	Selection_()
{
}

SelectUI::~SelectUI()
{
}

void SelectUI::Initialize()
{

	CsvReader reader("Assets/GameDatas/GameData.csv");
	for (int i = 0; i < reader.GetLines(); i++)
	{
		Text text(reader.GetString(i,0), "りいてがき筆", {0,0,500,50});
		moveUIList_.push_back((int)AddComponent<Text>(text));
		playerCountList_.push_back(reader.GetInt(i, 1));
	}
	////テキスト
	//{
	//	Text text1("Game1", "りいてがき筆", { 0,0,500,50 });
	//	moveUIList_.push_back((int)AddComponent<Text>(text1));
	//
	//}
	////テキスト2
	//{
	//	Text text2("Game2", "りいてがき筆", { 0,0,500,50 });
	//	moveUIList_.push_back((int)AddComponent<Text>(text2));
	//}
	////テキスト3
	//{
	//	Text text3("Game3", "りいてがき筆", { 0,0,500,50 });
	//	moveUIList_.push_back((int)AddComponent<Text>(text3));
	//}
	////テキスト2
	//{
	//	Text text2("Game4", "りいてがき筆", { 0,0,500,50 });
	//	text2.SetAlinmentType(LEFT_CENTER);
	//	text2.SetFontStyle(DWRITE_FONT_STYLE_ITALIC, 0, 3);
	//	text2.SetFontWeight(DWRITE_FONT_WEIGHT_BOLD, 0, 5);
	//	moveUIList_.push_back((int)AddComponent<Text>(text2));
	//}
	////テキスト3
	//{
	//	Text text3("Game5", "りいてがき筆", { 0,0,500,50 });
	//	moveUIList_.push_back((int)AddComponent<Text>(text3));
	//}
	////テキスト3
	//{
	//	Text text3("Game6", "りいてがき筆", { 0,0,500,50 });
	//	text3.SetText("Stage06");
	//	moveUIList_.push_back((int)AddComponent<Text>(text3));
	//}
	////テキスト4
	//{
	//	Text text4("Game7", "りいてがき筆", { 0,0,500,50 });
	//	moveUIList_.push_back((int)AddComponent<Text>(text4));
	//}

	////プレイヤーのカウントテキスト
	//{
	//	Text countText("", "りいてがき筆", { 0,0,500,50 });
	//	countText.SetText("< " + std::to_string(playCount_) + " >");
	//	countText.SetPosition({ 2400,-1600 });
	//	countTextNum_ = (int)AddComponent<Text>(countText);
	//
	//}

	//画像1
	{
		Image image1;
		image1.Load("Assets\\Image\\Image_Stage1.png");
		AddComponent<Image>(image1);
	}
	//画像2
	{

		Image image2;
		image2.Load("Assets\\Image\\Image_Stage2.png");
		AddComponent<Image>(image2);
	}
	//画像3
	{

		Image image3;
		image3.Load("Assets\\Image\\Image_Stage3.png");
		AddComponent<Image>(image3);
	}
	//画像4
	{

		Image image2;
		image2.Load("Assets\\Image\\Parrot.jpg");
		AddComponent<Image>(image2);
	}
	//画像5
	{

		Image image3;
		image3.Load("Assets\\Image\\Parrot.jpg");
		AddComponent<Image>(image3);
	}
	//画像6
	{

		Image image3;
		image3.Load("Assets\\Image\\Parrot.jpg");
		AddComponent<Image>(image3);
	}

	for (int i = 0; i < moveUIList_.size(); i++)
	{
		GetComponent<Text>(i).SetRatio(Position.at(2).x, Position.at(2).y);
		GetComponent<Text>(i).SetTextSize(TEXT_SIZE_DEFAULT);
		GetComponent<Image>(i).SetPosition(POSITION_DEFAULT);
		basePosList_.push_back(POSITION_DEFAULT);
	}

	Selection_[-2] = moveUIList_.end() - 2;
	Selection_[-1] = moveUIList_.end() - 1;
	Selection_[0] = moveUIList_.begin();
	Selection_[1] = Selection_[0] + 1;
	Selection_[2] = Selection_[1] + 1;
	buttonNum_ = *Selection_[0];

	GetComponent<Text>(buttonNum_).SetTextSize(TEXT_SIZE_PICKUP);


	UIPositioning();
}
void SelectUI::Input()
{
	//ボタンの処理
	moveDir_ = 0;
	//上に移動
	//PlayerCount(Input::GetPadAnyDown());

	if (Input::IsPadButton(XINPUT_GAMEPAD_DPAD_UP) || Input::GetLStick_Y() > 0)
	{
		moveDir_ = 1;

		GetComponent<Text>(buttonNum_).SetTextSize(TEXT_SIZE_DEFAULT);
		state_ = SELECT_STATE::STATE_MOVE;

		ItrIncrement();
	}
	//下に移動
	else if (Input::IsPadButton(XINPUT_GAMEPAD_DPAD_DOWN) || Input::GetLStick_Y() < 0)
	{
		moveDir_ = -1;

		GetComponent<Text>(buttonNum_).SetTextSize(TEXT_SIZE_DEFAULT);
		state_ = SELECT_STATE::STATE_MOVE;

		ItrDecrement();
	}
	else if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
	{
		PushedButton(buttonNum_);
	}

	ImGui::Begin("Select");
	ImGui::Text(std::to_string(buttonNum_).c_str());
	ImGui::End();
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
		GetComponent<Text>(buttonNum_).SetTextSize(TEXT_SIZE_PICKUP);
		UIPositioning();
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

//void SelectUI::PlayerCount(const int& padButton)
//{
//	switch (padButton)
//	{
//	case XINPUT_GAMEPAD_DPAD_LEFT:
//		if (playCount_ > 0)
//		{
//			playCount_--;
//			GetComponent<Text>(countTextNum_).SetText("< " + std::to_string(playCount_) + " >");
//		}
//		break;
//	case XINPUT_GAMEPAD_DPAD_RIGHT:
//		if (playCount_ < Input::GetConnectedControllerCount())
//		{
//			playCount_++;
//			GetComponent<Text>(countTextNum_).SetText("< " + std::to_string(playCount_) + " >");
//		}
//		break;
//	default:
//		break;
//	}
//}

void SelectUI::MoveButton(float ratio)
{
	float delta = MOVE * ratio * moveDir_;
	for (auto&& itr : Selection_)
	{
		GetComponent<Image>(*itr.second).
			SetPosition({ -basePosList_[*itr.second].x + IMAGE_OFFSET.x,
								 (basePosList_[*itr.second].y + IMAGE_OFFSET.y + delta) * IMAGE_RATIO,
								  basePosList_[*itr.second].z });
		GetComponent<Text>(*itr.second).
			SetRatio(basePosList_[*itr.second].x,
				basePosList_[*itr.second].y + delta);
	}
	//for (int& num : moveUIList_)
	//{
	//	GetComponent<Image>(num).
	//			     SetPositionAtPixel({ -basePosList_[num].x + IMAGE_OFFSET.x,
	//									  (basePosList_[num].y+IMAGE_OFFSET.y + delta)*IMAGE_RATIO,
	//									   basePosList_[num].z });
	//	GetComponent<Text>(num).
	//				 SetPosition({ basePosList_[num].x,
	//							   basePosList_[num].y+delta });
	//	//i++;
	//}
	//i = 0;
	//for (Entity& entity : GetComponentList<Text>())
	//{
	//	i++;
	//}
}

void SelectUI::PushedButton(int buttonNum)
{
	InterSceneData::DeleteData<int>("PlayerCount");
	InterSceneData::DeleteData<int>("GameNumber");
	InterSceneData::AddData<int>("PlayerCount", playerCountList_[buttonNum_]);
	InterSceneData::AddData<int>("GameNumber", buttonNum_);
	state_ = SELECT_STATE::STATE_SELECTED;
	newSceneManager::ChangeScene(SCENE_ID::PLAY);
}

void SelectUI::Release()
{
}

void SelectUI::ItrIncrement()
{
	Selection_[2] = Selection_[1];
	Selection_[1] = Selection_[0];
	Selection_[0] = Selection_[-1];
	Selection_[-1] = Selection_[-2];
	if (Selection_[-2] == begin(moveUIList_))
		Selection_[-2] = moveUIList_.end();
	--Selection_[-2];

	buttonNum_ = *Selection_[0];
}

void SelectUI::ItrDecrement()
{
	Selection_[-2] = Selection_[-1];
	Selection_[-1] = Selection_[0];
	Selection_[0] = Selection_[1];
	Selection_[1] = Selection_[2];
	if (++Selection_[2] == end(moveUIList_))
		Selection_[2] = moveUIList_.begin();

	buttonNum_ = *Selection_[0];
}

void SelectUI::UIPositioning()
{
	for (int i = -2; i <= 2; i++)
	{
		GetComponent<Text>(*Selection_[i]).SetRatio(Position.at(i).x, Position.at(i).y);
		basePosList_[*Selection_[i]] = { Position.at(i).x, Position.at(i).y, 0 };
		GetComponent<Image>(*Selection_[i]).
			SetPosition({ -Position.at(i).x + IMAGE_OFFSET.x,
								 (Position.at(i).y + IMAGE_OFFSET.y) * IMAGE_RATIO, 0 });
	}
}