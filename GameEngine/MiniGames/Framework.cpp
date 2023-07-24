#include "Framework.h"

void Framework::Finish()
{
}

Framework::Framework(Object* parent, const std::string& name)
	: Object(parent, name), Players_(1), GameTime_()
{
}

Framework::~Framework()
{
}
