#include "ObjectSetter.h"
#include"RootObject.h"
#include"TestObject.h"
#include"TestObjectChild.h"
ObjectSetter::ObjectSetter() : ObjectSetter(nullptr)
{

}

ObjectSetter::ObjectSetter(Object* sceneObject)
{
	sceneObject_ = sceneObject;
}

ObjectSetter::~ObjectSetter()
{
}

bool ObjectSetter::DataLoad(const std::string& fileName)
{
	return false;
}

void ObjectSetter::SetObject()
{
	sceneObject_->Instantiate<TestObject>(sceneObject_);
	sceneObject_->Instantiate<TestObjectChild>(sceneObject_);
}

void ObjectSetter::DeleteObject()
{
	//SAFE_DELETE(sceneObject_);
}
