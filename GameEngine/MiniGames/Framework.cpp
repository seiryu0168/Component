#include "Framework.h"
#include "../Engine/DirectX_11/Input.h"
#include "../Engine/Brightness.h"

Framework::Framework(Object* parent, const std::string& name)
	: Object(parent, name), Players_(1), GameTime_()
{
}

Framework::~Framework()
{
}

void Framework::NotifiedUpdateT()
{
	//Brightness::SetRatio(0.2f);
}

void Framework::NotifiedUpdateF()
{
	//Brightness::SetRatio(0);
}

void Framework::Pause()
{
	if (Input::IsAnyPadDown(XINPUT_GAMEPAD_START))
	{
		SetUpdate(!isUpdate_);
	}
	Brightness::Draw();
}