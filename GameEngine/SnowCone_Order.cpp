#include "SnowCone_Order.h"
#include"Engine/ResourceManager/CsvReader.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/Systems/ImageSystem.h"
#include"InterSceneData.h"
#include"MiniGames/SnowConeMaking.h"
namespace
{
	const int ORDER_LIMIT = 3;
	const XMFLOAT2 TEXTPOS[3] = { {530,100},{880,100},{1230,100} };
	const XMFLOAT3 MENUIMAGE_POS[] = { {-600,800,0},{100,800,0},{800,800,0} };
}
SnowCone_Order::SnowCone_Order(Object* parent)
	:GameObject(parent,"SnowCone_Order"),
	orderTextNum_(0)
{
}

SnowCone_Order::~SnowCone_Order()
{
}

void SnowCone_Order::Initialize()
{
	CsvReader reader("Assets/GameDatas/SnowConeDatas/SnowCone_Order.csv");
	
	for (int i = 0; i < reader.GetColumns(0); i++)
	{
		sizeTextList_.push_back(reader.GetString(0, i));
	}
	for (int i = 0; i < reader.GetColumns(1); i++)
	{
		syrupTextList_.push_back(reader.GetString(1, i));
	}
	for (int i = 0; i < reader.GetColumns(2); i++)
	{
		toppingTextList_.push_back(reader.GetString(2, i));
	}

	for (int i = 0; i < ORDER_LIMIT; i++)
	{
		InitOrder();
		orderTextNum_++;
	}

	for (XMFLOAT3 pos : MENUIMAGE_POS)
	{
		Image image(0);
		image.Load("Assets/Image/SnowCone_MenuBackImage.png");
		image.SetPositionAtPixel(pos);
		image.SetSize({ 1.3f,1.3,0 });
		AddComponent<Image>(image);
	}
}

void SnowCone_Order::CreateOrder()
{
	//ランダムに注文を生成
	std::mt19937 mt(rnd_());
	std::uniform_int_distribution<int> rand3(0, 2);
	Order order;
	order.size_ = rand3(mt);
	order.syrup_ = rand3(mt);
	order.topping_ = rand3(mt);
	
	//オーダーがいっぱいじゃないなら
	if (orderList_.size() <= ORDER_LIMIT)
	{
		std::string orderStr = sizeTextList_[order.size_] + "\n" +
							   syrupTextList_[order.syrup_] + "\n" +
							   toppingTextList_[order.topping_];
		GetComponent<Text>(orderTextNum_).SetText(orderStr);
	}
	orderList_[orderTextNum_] = order;
}

void SnowCone_Order::InitOrder()
{
	//ランダムに注文を生成
	std::mt19937 mt(rnd_());
	std::uniform_int_distribution<int> rand3(0, 2);
	Order order;
	order.size_ = rand3(mt);
	order.syrup_ = rand3(mt);
	order.topping_ = rand3(mt);

	if (orderList_.size() < ORDER_LIMIT)
	{
		std::string orderStr = sizeTextList_[order.size_] + "\n" +
			syrupTextList_[order.syrup_] + "\n" +
			toppingTextList_[order.topping_];

		Text text(orderStr, "りいてがき筆", { 0,0,500,50 });
		text.SetTextSize(40);
		text.SetPosition(TEXTPOS[orderTextNum_]);
		text.SetColor({ 1, 0, 0, 1 });
		AddComponent<Text>(text);
		orderList_.push_back(order);
	}
}

void SnowCone_Order::Judge(int size, int syrup, int topping)
{
	//出されたかき氷が注文と合ってるかどうか
	for(int i=0;i<orderList_.size();i++)
	{
		//合ってる場合、その注文を消して新しいオーダーを生成
		if (orderList_[i].size_ == size && orderList_[i].syrup_ == syrup && orderList_[i].topping_ == topping)
		{
			//RemoveComponent<Text>(i);
			//orderList_.erase(orderList_.begin() + i);
			orderTextNum_ = i;
			((SnowConeMaking*)GetParent())->ScoreUpdate(1);
			SNOWCONE_DATA data;
			data.size_ = size;
			data.syrup = syrup;
			data.topping_ = topping;
			successOrderList_.push_back(data);
			CreateOrder();
			return;
		}
	}
}

void SnowCone_Order::SendResultData()
{
	InterSceneData::DeleteData<std::vector<SNOWCONE_DATA>>("SuccessData");
	InterSceneData::AddData("SuccessData", successOrderList_);
}

void SnowCone_Order::Release()
{
}
