#include "R_ChickenRace.h"
#include "Engine/Components/Text.h"
#include "InterSceneData.h"
#include <format>

R_ChickenRace::R_ChickenRace(Object* parent)
	:Result_Multi(parent, "R_ChickenRace")
{
}

R_ChickenRace::~R_ChickenRace()
{
}

void R_ChickenRace::MoreInfo()
{
	for (int i = 0; i < 2; i++)
	{
		float time = InterSceneData::GetData<float>(std::format("time_{:d}", i));
		int target = InterSceneData::GetData<int>("time_target");
		float error = time - target;
		Text text(std::format("ÉvÉåÉCÉÑÅ[{:d}\n{:g}ïb\n(åÎç∑ : {:g}ïb)", i + 1, time, error), "", { 0,0,700,50 });
		text.SetRatio(0.15f + (i * 0.45f), 0.35f);
		AddComponent<Text>(text);
	}
}
