#include "SnowCone_ToppingMenu.h"

SnowCone_ToppingMenu::SnowCone_ToppingMenu(Object* parent, const std::string& name)
	:GameObject(parent,name),
	state_(SELECT_STATE::INPUT),
	selectNum_(0)
{
	time_ = std::make_unique<Time::Watch>();
}

SnowCone_ToppingMenu::~SnowCone_ToppingMenu()
{
}

void SnowCone_ToppingMenu::Initialize()
{
}

void SnowCone_ToppingMenu::Reset()
{
	selectNum_ = 0;
	state_ = SELECT_STATE::INPUT;
}

void SnowCone_ToppingMenu::Release()
{
}
