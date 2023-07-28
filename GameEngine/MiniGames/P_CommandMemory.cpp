#include "P_CommandMemory.h"
#include "CommandMemory.h"
#include "../Engine/DirectX_11/Input.h"

P_CommandMemory::P_CommandMemory(Object* parent)
	: Player(parent, "P_CommandMemory"), memory_((CommandMemory*)parent)
{
}

P_CommandMemory::~P_CommandMemory()
{
}

void P_CommandMemory::Initialize()
{
}

void P_CommandMemory::Update()
{
	if (WORD button = Input::GetPadAnyDown(Playerid_); button != NULL)
	{
		memory_->sendCommand(button, Playerid_);
	}
}

void P_CommandMemory::Release()
{
}
