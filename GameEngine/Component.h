#pragma once

class Object;
class Component
{
private:

protected:
	Component* parent_;
	int componentID_;
	Object* attacheObject_;
public:
	Component(Object* atcObj, Component* parent = nullptr);
	Component();

	virtual ~Component() {};
	void SetParent(Component* parent);
	Component* GetParent() const;
	//virtual void Draw() {};
	virtual void Start() {};
	virtual void Update() {};
};

