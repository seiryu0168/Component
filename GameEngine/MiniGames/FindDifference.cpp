#include "FindDifference.h"
#include "P_FindDifference.h"

FindDifference::FindDifference(Object* parent)
	: Framework(parent, "FindDifference")
{
}

FindDifference::~FindDifference()
{
}

void FindDifference::Initialize()
{
	Players_ = 2;
	PlayerInitialize<P_FindDifference>();
}

void FindDifference::Release()
{
}

void FindDifference::SendData(CHOICES select, int Playernum)
{
}
