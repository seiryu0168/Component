#include "Shooting_ScoreUI.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/Coordinator.h"
Shooting_ScoreUI::Shooting_ScoreUI()
{
}

Shooting_ScoreUI::~Shooting_ScoreUI()
{
}

void Shooting_ScoreUI::Init(const unsigned short& playerCount, std::string initText)
{
	for (int i = 0; i < playerCount; i++)
	{
		Entity entity=Coordinator::CreateEntity();
		uiEntities_.push_back(entity);
		Text text;// ("", "�肢�Ă����M", { 0,0,10,500 });
		text.SetText("���_ 0");
		text.SetFont("�肢�Ă����M");
		Coordinator::AddComponent<Text>(entity, text);
	}
}

void Shooting_ScoreUI::TextUpdate(const unsigned short& playerNum, std::string text)
{
	if (playerNum < uiEntities_.size())
	{
		std::string&& str = "���_ " + text;
		Coordinator::GetComponent<Text>(uiEntities_[playerNum]).SetText(str);
		Coordinator::GetComponent<Text>(uiEntities_[playerNum]).SetFont("�肢�Ă����M", 0, str.length());
	}
}
