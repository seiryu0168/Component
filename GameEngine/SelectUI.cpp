#include "SelectUI.h"
#include"Engine/Systems/ImageSystem.h"
#include"Easing.h"
#include"Engine/DirectX_11/Input.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/newSceneManager.h"
#include"InterSceneData.h"

#include "ImGui/imgui.h"
namespace
{
	const static float	MOVE = -500.0f;
	const static int	MAX_MOVE_TIME = 11;
	//const static XMINT2 MAX_SELECT = { 0,4 };
	const static XMFLOAT2  IMAGE_OFFSET = { 900.0f,600.0f };
	const static float  IMAGE_RATIO = 5.0f;
	const static int	TEXT_SIZE_DEFAULT = 54;
	const static int	TEXT_SIZE_PICKUP = 90;

	//それぞれのテキストの位置
	const std::map<int, XMFLOAT2> Position = {
		{-2, {500, 400}},
		{-1, {500, -100}},
		{ 0, {500, -600}},
		{1, {500, -1100}},
		{2, {500, -1600}},
		{3, {500, -2100}}
	};

	const static XMFLOAT3 POSITION_DEFAULT = { -9999,0,0 };
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
	//テキスト
	{
		Text text1("Game1", "りいてがき筆", { 0,0,500,50 });
		/*XMFLOAT3 pos = { 500,-600.0f,0 };
		basePosList_.push_back(pos);*/
		//text1.SetPosition({ pos.x, pos.y });
		//text1.SetAlinmentType(LEFT_CENTER);
		moveUIList_.push_back((int)AddComponent<Text>(text1));
		
	}
	//テキスト2
	{
		Text text2("Game2", "りいてがき筆", { 0,0,500,50 });
		//text2.SetText("Stage02");
		/*XMFLOAT3 pos = { 500.0f,-1100.0f,0 };
		basePosList_.push_back(pos);*/
		//text2.SetPosition({ pos.x, pos.y });
		//text2.SetAlinmentType(LEFT_CENTER);
		//text2.SetFontStyle(DWRITE_FONT_STYLE_ITALIC, 0, 3);
		//text2.SetFontWeight(DWRITE_FONT_WEIGHT_BOLD, 0, 5);
		moveUIList_.push_back((int)AddComponent<Text>(text2));
	}
	//テキスト3
	{
		Text text3("Game3", "りいてがき筆", { 0,0,500,50 });
		//text3.SetText("Stage03");
		/*XMFLOAT3 pos = { 500.0f,-1600.0f,0 };
		basePosList_.push_back(pos);*/
		//text3.SetPosition({ pos.x, pos.y });
		moveUIList_.push_back((int)AddComponent<Text>(text3));
	}
	//テキスト2
	{
		Text text2("Game4", "りいてがき筆", { 0,0,500,50 });
		//text2.SetText("Stage04");
		/*XMFLOAT3 pos = { 500.0f,-1100.0f,0 };
		basePosList_.push_back(pos);*/
		//text2.SetPosition({ pos.x, pos.y });
		text2.SetAlinmentType(LEFT_CENTER);
		text2.SetFontStyle(DWRITE_FONT_STYLE_ITALIC, 0, 3);
		text2.SetFontWeight(DWRITE_FONT_WEIGHT_BOLD, 0, 5);
		moveUIList_.push_back((int)AddComponent<Text>(text2));
	}
	//テキスト3
	{
		Text text3("Game5", "りいてがき筆", { 0,0,500,50 });
		//text3.SetText("Stage05");
		/*XMFLOAT3 pos = { 500.0f,-1600.0f,0 };
		basePosList_.push_back(pos);*/
		//text3.SetPosition({ pos.x, pos.y });
		moveUIList_.push_back((int)AddComponent<Text>(text3));
	}
	//テキスト3
	{
		Text text3("Game6", "りいてがき筆", { 0,0,500,50 });
		text3.SetText("Stage06");
		/*XMFLOAT3 pos = { 500.0f,-1600.0f,0 };
		basePosList_.push_back(pos);*/
		//text3.SetPosition({ pos.x, pos.y });
		moveUIList_.push_back((int)AddComponent<Text>(text3));
	}
	//テキスト4
	{
		Text text4("Game7", "りいてがき筆", { 0,0,500,50 });
		//text3.SetText("Stage06");
		/*XMFLOAT3 pos = { 500.0f,-1600.0f,0 };
		basePosList_.push_back(pos);*/
		//text3.SetPosition({ pos.x, pos.y });
		moveUIList_.push_back((int)AddComponent<Text>(text4));
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

		/*image1.SetPositionAtPixel({ -basePosList_[0].x + IMAGE_OFFSET.x,
									(basePosList_[0].y +IMAGE_OFFSET.y) * IMAGE_RATIO,
									basePosList_[0].z });*/
		AddComponent<Image>(image1);
	}
	//画像2
	{

		Image image2;
		image2.Load("Assets\\Image\\Image_Stage2.png");
		
		/*image2.SetPositionAtPixel({ -basePosList_[1].x + IMAGE_OFFSET.x,
									(basePosList_[1].y+IMAGE_OFFSET.y)* IMAGE_RATIO,
								    basePosList_[1].z });*/
		AddComponent<Image>(image2);
	}
	//画像3
	{

		Image image3;
		image3.Load("Assets\\Image\\Image_Stage3.png");
		
		/*image3.SetPositionAtPixel({ -basePosList_[2].x + IMAGE_OFFSET.x,
									(basePosList_[2].y+IMAGE_OFFSET.y)* IMAGE_RATIO,
									basePosList_[2].z });*/
		AddComponent<Image>(image3);
	}
	//画像2
	{

		Image image2;
		image2.Load("Assets\\Image\\Parrot.jpg");

		/*image2.SetPositionAtPixel({ -basePosList_[1].x + IMAGE_OFFSET.x,
									(basePosList_[1].y + IMAGE_OFFSET.y) * IMAGE_RATIO,
									basePosList_[1].z });*/
		AddComponent<Image>(image2);
	}
	//画像3
	{

		Image image3;
		image3.Load("Assets\\Image\\Parrot.jpg");

		/*image3.SetPositionAtPixel({ -basePosList_[2].x + IMAGE_OFFSET.x,
									(basePosList_[2].y + IMAGE_OFFSET.y) * IMAGE_RATIO,
									basePosList_[2].z });*/
		AddComponent<Image>(image3);
	}
	//画像3
	{

		Image image3;
		image3.Load("Assets\\Image\\Parrot.jpg");

		/*image3.SetPositionAtPixel({ -basePosList_[2].x + IMAGE_OFFSET.x,
									(basePosList_[2].y + IMAGE_OFFSET.y) * IMAGE_RATIO,
									basePosList_[2].z });*/
		AddComponent<Image>(image3);
	}
	//画像3
	{

		Image image3;
		image3.Load("Assets\\Image\\Parrot.jpg");

		/*image3.SetPositionAtPixel({ -basePosList_[2].x + IMAGE_OFFSET.x,
									(basePosList_[2].y + IMAGE_OFFSET.y) * IMAGE_RATIO,
									basePosList_[2].z });*/
		AddComponent<Image>(image3);
	}
	
	for (int i = 0; i < moveUIList_.size(); i++)
	{
		GetComponent<Text>(i).SetPosition(Position.at(2));
		GetComponent<Text>(i).SetTextSize(TEXT_SIZE_DEFAULT);
		GetComponent<Image>(i).SetPosition(POSITION_DEFAULT);
		basePosList_.push_back(POSITION_DEFAULT);
	}

	Selection_[-2] = moveUIList_.end() - 2;
	Selection_[-1] = moveUIList_.end() - 1;
	Selection_[0] = moveUIList_.begin();
	Selection_[1] = Selection_[0] + 1;
	Selection_[2] = Selection_[1] + 1;
	Selection_[3] = Selection_[2] + 1;
	buttonNum_ = *Selection_[0];
	
	GetComponent<Text>(buttonNum_).SetTextSize(TEXT_SIZE_PICKUP);


	UIPositioning();
}
void SelectUI::Input()
{
	//ボタンの処理
	moveDir_ = 0;
	//上に移動
	PlayerCount(Input::GetPadAnyDown());

	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_DPAD_UP) || Input::GetLStick_Y() > 0)
	{
		moveDir_ = 1;

		GetComponent<Text>(buttonNum_).SetTextSize(TEXT_SIZE_DEFAULT);
		state_ = SELECT_STATE::STATE_MOVE;

		ItrIncrement();
	}
	//下に移動
	else if (Input::IsPadButtonDown(XINPUT_GAMEPAD_DPAD_DOWN) || Input::GetLStick_Y() < 0)
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
	for(auto&& itr : Selection_)
	{
		GetComponent<Image>(*itr.second).
			SetPositionAtPixel({ -basePosList_[*itr.second].x + IMAGE_OFFSET.x,
								 (basePosList_[*itr.second].y + IMAGE_OFFSET.y + delta) * IMAGE_RATIO,
								  basePosList_[*itr.second].z });
		GetComponent<Text>(*itr.second).
			SetPosition({ basePosList_[*itr.second].x,
						  basePosList_[*itr.second].y + delta });
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
	InterSceneData::AddData<int>("PlayerCount", playCount_);
	InterSceneData::AddData<int>("GameNumber", buttonNum_);
	state_ = SELECT_STATE::STATE_SELECTED;
	newSceneManager::ChangeScene(SCENE_ID::PLAY);
}

void SelectUI::Release()
{
}

void SelectUI::ItrIncrement()
{
	Selection_[3] = Selection_[2];
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
	Selection_[2] = Selection_[3];
	if (++Selection_[3] == end(moveUIList_))
		Selection_[3] = moveUIList_.begin();

	buttonNum_ = *Selection_[0];
}

void SelectUI::UIPositioning()
{
	for (int i = -2; i <= 3; i++)
	{
		GetComponent<Text>(*Selection_[i]).SetPosition(Position.at(i));
		basePosList_[*Selection_[i]] = { Position.at(i).x, Position.at(i).y, 0 };
		GetComponent<Image>(*Selection_[i]).
			SetPositionAtPixel({ -Position.at(i).x + IMAGE_OFFSET.x,
								 (Position.at(i).y + IMAGE_OFFSET.y) * IMAGE_RATIO, 0 });
	}
}