#include "Result_SnowCone.h"
#include"Engine/Systems/TextSystem.h"
#include"InterSceneData.h"
Result_SnowCone::Result_SnowCone(Object* parent)
	:Result_Single(parent,"Result_SnowCone")
{
}

Result_SnowCone::~Result_SnowCone()
{
}

void Result_SnowCone::Initialize()
{
	Text scoreText(std::to_string(InterSceneData::GetData<int>("ResultData")), "‚è‚¢‚Ä‚ª‚«•M", { 0,0,500,50 });
	AddComponent<Text>(scoreText);
}

void Result_SnowCone::Release()
{
}
