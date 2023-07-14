#include "ObjectSetter.h"
#include"RootObject.h"
#include"TestObject.h"
ObjectSetter::ObjectSetter()
{

}

ObjectSetter::ObjectSetter(Object* sceneObject)
{
	sceneObject_ = sceneObject;
}

ObjectSetter::~ObjectSetter()
{
}

bool ObjectSetter::DataLoad(std::string fileName)
{
	return false;
}

void ObjectSetter::SetObject()
{
	sceneObject_->Instantiate<TestObject>(sceneObject_);
}

void ObjectSetter::DeleteObject()
{
	//SAFE_DELETE(sceneObject_);
}
