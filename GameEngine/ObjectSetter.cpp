#include "ObjectSetter.h"
#include"RootObject.h"
ObjectSetter::ObjectSetter()
{

}

ObjectSetter::ObjectSetter(Object* sceneObject)
{
	sceneObject_ = sceneObject;
}

bool ObjectSetter::DataLoad(std::string fileName)
{
	return false;
}

void ObjectSetter::SetObject()
{
}
