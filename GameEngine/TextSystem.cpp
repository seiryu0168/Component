#include "TextSystem.h"
#include"Coordinator.h"
TextSystem::TextSystem()
{
}

void TextSystem::Update()
{
	for (Entity entity : entities_)
	{
		Coordinator::GetComponent<Text>(entity).Draw();
	}
}
