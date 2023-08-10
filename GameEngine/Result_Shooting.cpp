#include "Result_Shooting.h"
#include"InterSceneData.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/DirectX_11/Input.h"
#include"Engine/newSceneManager.h"

Result_Shooting::Result_Shooting(Object* parent)
	:Result_Single(parent,"Result_Shooting")
{
}

Result_Shooting::~Result_Shooting()
{
}

void Result_Shooting::Initialize()
{
	score_ = InterSceneData::GetData<float>("ResultData");
	Text scoreText(std::to_string(score_), "‚è‚¢‚Ä‚ª‚«•M", { 0,0,100,50 });
	AddComponent<Text>(scoreText);
}

void Result_Shooting::Update()
{
	if (Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
		newSceneManager::ChangeScene(SCENE_ID::MENU);
}

void Result_Shooting::Release()
{
}
