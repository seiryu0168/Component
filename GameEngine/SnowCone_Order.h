#pragma once
#include"Engine/GameObject/GameObject.h"
#include<random>
class SnowCone_Order : public GameObject
{
	struct Order
	{
		float size_;
		int syrup_;
		int topping_;
	};

	int orderTextNum_;

	std::vector<Order> orderList_;
	std::vector<std::string> sizeTextList_;
	std::vector<std::string> syrupTextList_;
	std::vector<std::string> toppingTextList_;

	std::vector<std::string> orderTextList_;

	std::random_device rnd_;
	
public:
	SnowCone_Order(Object* parent);
	~SnowCone_Order();

	void Initialize() override;
	void CreateOrder();
	void InitOrder();
	void Judge(int size, int syrup, int topping);
	void Release() override;
};

