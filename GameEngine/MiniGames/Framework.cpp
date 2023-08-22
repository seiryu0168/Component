#include "Framework.h"
#include "../Engine/DirectX_11/Input.h"

Framework::Framework(Object* parent, const std::string& name)
	: Object(parent, name), Players_(1), GameTime_()
{
}

Framework::~Framework()
{
}

void Framework::Pause()
{
	if (Input::IsAnyPadDown(XINPUT_GAMEPAD_START))
	{
		SetUpdate(!isUpdate_);
	}
}