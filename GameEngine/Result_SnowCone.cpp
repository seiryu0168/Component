#include "Result_SnowCone.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/Systems/ImageSystem.h"
#include"InterSceneData.h"

namespace
{
	const float SHOWTIME = 3.0f;
	const XMFLOAT2 DEFAULT_POS = { 1920 * 0.15f,1080 * 0.15f };
	const std::string ICE_NAME = "Assets/Image/SnowCone_IceImage.png";
	const std::string CUP_NAME = "Assets/Image/SnowCone_CupImage.png";
	const std::string SYRUP_NAME[] = { "Assets/Image/SnowCone_Syrup_RedImage.png","Assets/Image/SnowCone_Syrup_BlueImage.png","Assets/Image/SnowCone_Syrup_GreenImage.png" };
	const std::string TOPPING_NAME[] = { "Assets/Image/SnowCone_Topping_Adzuki.png","Assets/Image/SnowCone_Topping_Blueberry.png","Assets/Image/SnowCone_Topping_Raspberry.png" };
}

Result_SnowCone::Result_SnowCone(Object* parent)
	:Result_Single(parent,"Result_SnowCone"),
	status_(CountStatus::STAY),
	count_(0)
{
}

Result_SnowCone::~Result_SnowCone()
{
}

void Result_SnowCone::Initialize()
{
	score_ = InterSceneData::GetData<int>("ResultData");

	Text text("åãâ ", "ÇËÇ¢ÇƒÇ™Ç´ïM", { 0,0,200,50 });
	text.SetPosition({ 750,0 });
	text.SetTextSize(100);
	AddComponent<Text>(text);

	Text scoreText("ê≥âÇµÇΩêî 0", "ÇËÇ¢ÇƒÇ™Ç´ïM", { 0,0,500,50 });
	scoreText.SetPosition({ 500,500 });
	resultTextNum_ = AddComponent<Text>(scoreText);

	time_ = std::make_unique<Time::Watch>();
	time_->UnLock();
	interval_ = Clamp<float>((SHOWTIME / (float)score_), 0.2f, 1.0f);
}

void Result_SnowCone::Update()
{
	switch (status_)
	{
	case Result_SnowCone::CountStatus::STAY:
		Stay();
		break;
	case Result_SnowCone::CountStatus::SHOW:
		Show();
		break;
	case Result_SnowCone::CountStatus::FINISH:
		break;
	default:
		break;
	}
}

void Result_SnowCone::Stay()
{
	if (time_->GetSeconds<float>() >= 1.0f)
		status_ = CountStatus::SHOW;
}

void Result_SnowCone::Show()
{
	if ((interval_ * count_) <= time_->GetSeconds<float>() - 1.0f)
	{
		Create(count_);
		count_++;
		GetComponent<Text>(resultTextNum_).SetText("ê≥âÇµÇΩêî " + std::to_string(count_));

	}
	if (count_ > score_)
	{
		GetComponent<Text>(resultTextNum_).SetText("ê≥âÇµÇΩêî " + std::to_string(score_));
		time_->Lock();
		ShowCommand();
		status_ = CountStatus::FINISH;
	}
}

void Result_SnowCone::ShowCommand()
{
	Text retryText("Ç‡Ç§àÍìx", "ÇËÇ¢ÇƒÇ™Ç´ïM", { 0,0,500,50 });
	retryText.SetRatio(0.7f, 0.7f);
	retryText.SetTextSize(48);
	AddComponent<Text>(retryText);

	Text toMenuText_("ÉÅÉjÉÖÅ[Ç÷", "ÇËÇ¢ÇƒÇ™Ç´ïM", { 0,0,500,50 });
	toMenuText_.SetRatio(0.7f, 0.85f);
	toMenuText_.SetTextSize(48);
	AddComponent<Text>(toMenuText_);

	{
		Image image(0, 0);
		image.Load("Assets\\Image\\Buttons\\BTN_A.png", "Result_Multi");
		AddComponent<Image>(image);
	}
	{
		Image image(0, 0);
		image.Load("Assets\\Image\\Buttons\\BTN_B.png", "Result_Multi");
		AddComponent<Image>(image);
	}
}

void Result_SnowCone::Create(int num)
{
	if (score_ <= num)
		return;

	int size = InterSceneData::GetData<std::vector<SNOWCONE_DATA>>("SuccessData")[num].size_;
	int syrupNum = InterSceneData::GetData<std::vector<SNOWCONE_DATA>>("SuccessData")[num].syrup;
	int toppingNum = InterSceneData::GetData<std::vector<SNOWCONE_DATA>>("SuccessData")[num].topping_;
	XMFLOAT3 pos = { (DEFAULT_POS.x * num) - 1700,DEFAULT_POS.y * (num / 5) + 300 ,0 };
	Image iceImage(0, 0);
	iceImage.Load(ICE_NAME);
	iceImage.SetPositionAtPixel({ pos.x,pos.y + 180,0 });
	iceImage.SetSize({ 1, 1.0f+(float)size, 0 });
	AddComponent<Image>(iceImage);

	Image cupImage(0, 0);
	cupImage.Load(CUP_NAME);
	cupImage.SetPositionAtPixel(pos);
	AddComponent<Image>(cupImage);

	Image syrupImage(0, 0);
	syrupImage.Load(SYRUP_NAME[syrupNum]);
	syrupImage.SetPositionAtPixel({ pos.x,pos.y + 180,0 });
	syrupImage.SetSize({ 1, 1.0f + (float)size, 0});
	AddComponent<Image>(syrupImage);

	float toppingPosition = (pos.y+180) + (256.0f * (1.0f+size)) - 30.0f;
	Image toppingImage(0, 0);
	toppingImage.Load(TOPPING_NAME[toppingNum]);
	toppingImage.SetSize({1.0f/(1+size),1,0});
	toppingImage.SetPositionAtPixel({ pos.x,toppingPosition,0 });
	AddComponent<Image>(toppingImage);

}

void Result_SnowCone::Release()
{
}
