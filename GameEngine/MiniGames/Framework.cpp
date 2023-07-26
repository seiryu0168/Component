#include "Framework.h"

Framework::Framework(Object* parent, const std::string& name)
	: Object(parent, name), Players_(1), GameTime_()
{
}

Framework::~Framework()
{
}
