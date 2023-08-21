#include "Shooting_ScoreUI.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/Coordinator.h"
namespace
{
	const XMFLOAT2 MODE_SINGLE = { 0,0 };
}

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
		Text text(i);// ("", "りいてがき筆", { 0,0,10,500 });
		text.SetText("落とした数 0");
		text.SetFont("りいてがき筆");
		Coordinator::AddComponent<Text>(entity, text);
	}
}

void Shooting_ScoreUI::TextUpdate(const unsigned short& playerNum, std::string text)
{
	if (playerNum < uiEntities_.size())
	{
		std::string&& str = "得点 " + text;
		Coordinator::GetComponent<Text>(uiEntities_[playerNum]).SetText(str);
		Coordinator::GetComponent<Text>(uiEntities_[playerNum]).SetFont("りいてがき筆", 0, str.length());
	}
}
