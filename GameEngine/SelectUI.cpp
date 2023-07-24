#include "SelectUI.h"
#include"Engine/Systems/ImageSystem.h"
#include"Easing.h"
#include"Engine/DirectX_11/Input.h"
#include"Engine/newSceneManager.h"
namespace
{
	const static float MOVE = 1.0f;
	const static int MAX_MOVE_TIME = 11;
}
void SelectUI::Input()
{
	//ボタンの処理
	moveDir_ = 0;
	//上に移動
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_DPAD_UP))
	{
		moveDir_ = -1;
		////ボタンが
		//if (buttonNum_ > 0)
		state_ = SELECT_STATE::STATE_MOVE;
	}
	//下に移動
	else if (Input::IsPadButtonDown(XINPUT_GAMEPAD_DPAD_DOWN))
	{
		moveDir_ = 1;
		////ボタンの番号が最後尾じゃなかったら移動モードに切り替える
		//if (buttonNum_ < (buttonCount_ - 1))
		state_ = SELECT_STATE::STATE_MOVE;
	}
	else if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
		newSceneManager::ChangeScene(SCENE_ID::MENU);


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
			Coordinator::GetComponent<Image>(entity).SetPosition(basePosList_[i]);
			i++;
		}
		return;
	}
	//セレクト画面を動かす
	MoveButton(Easing::EaseInCubic((float)moveTime_ / (float)(MAX_MOVE_TIME - 1)));
}

SelectUI::SelectUI(Object* parent)
	:GameObject(parent,"SelectUI"),
	moveDir_(0),
	state_(SELECT_STATE::STATE_INPUT),
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
		XMFLOAT3 pos = { -0.4f,-1.0f,0 };
		basePosList_.push_back(pos);
		image1.SetPosition(pos);
		AddComponent<Image>(image1);
	}
	//画像2
	{

		Image image2;
		image2.Load("Assets\\Image\\Smoke.png");
		XMFLOAT3 pos = { -0.4f,0.0f,0 };
		basePosList_.push_back(pos);
		image2.SetPosition(pos);
		AddComponent<Image>(image2);
	}
	//画像3
	{

		Image image3;
		image3.Load("Assets\\Image\\Fire.png");
		XMFLOAT3 pos = { -0.4f,1.0f,0 };
		basePosList_.push_back(pos);
		image3.SetPosition(pos);
		AddComponent<Image>(image3);
	}

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
		Coordinator::GetComponent<Image>(entity).SetPosition({ basePosList_[i].x,
															   basePosList_[i].y + delta,
															   basePosList_[i].z });
		i++;
		////ボタンを移動させる
		//ImageManager::SetImagePos(i.hButtonPict_,
		//	XMFLOAT3(i.position_.x,
		//		i.position_.y + delta,
		//		0));
		//ImageManager::SetImagePos(i.hMissionPict_,
		//	XMFLOAT3(400.0f,
		//		(i.position_.y + delta) * 3.0f,
		//		0));
		//i.buttonText_->SetPosition({ i.position_.x - i.buttonText_->GetRect().right,
		//							 i.position_.y + i.buttonText_->GetRect().bottom + delta });
	}
}

void SelectUI::PushedButton()
{

}

void SelectUI::Release()
{
}
