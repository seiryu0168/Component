#include "Shooting_Gun.h"
#include"Engine/Systems/ModelSystem.h"
#include"Engine/Systems/ImageSystem.h"
#include"Engine/Systems/TextSystem.h"
#include"Engine/ResourceManager/Audio.h"
#include"Shooting_Bullet.h"

namespace
{
	 static const int MAX_BULLET = 10;
	 //const XMFLOAT2 
}

Shooting_Gun::Shooting_Gun(Object* parent)
	:GameObject(parent,"Shooting_Gun"), bulletCount_(MAX_BULLET), frontVec_(), playerNum_(0), textNum_()
{
}

Shooting_Gun::~Shooting_Gun()
{
}

void Shooting_Gun::Initialize()
{
	transform_->position_ = XMVectorSet(0, -5, 20, 0);
	Test_Model_ECSver model(this);
	model.Load("Assets/Model/Shooting_Gun.fbx");
	model.SetDraw(false);
	AddComponent<Test_Model_ECSver>(model);

	Text text("", "りいてがき筆", { 0,0,500,50 },playerNum_);
	text.SetText("X"+std::to_string(MAX_BULLET));
	text.SetTextSize(40);
	text.SetRatio( 0.57f,0.55f );
	textNum_ = AddComponent<Text>(text);

	Image image(playerNum_);
	image.Load("Assets/Image/Shooting_CorkBullet.png");
	image.SetSize({ 0.3f,0.3f,0 });
	image.SetPositionAtPixel({ 170,-170,0 });
	AddComponent<Image>(image);

	hAudio_Shot_ = Audio::Load("Assets/Audio/Shooting_ShotPon.wav",false,1.0f,7);
	assert(hAudio_Shot_ >= 0);
}

void Shooting_Gun::Update()
{
}

void Shooting_Gun::Shot(const XMVECTOR& dir)
{
	if (bulletCount_ == 0)
		return;
	Audio::Play(hAudio_Shot_);
	Shooting_Bullet* bullet = Instantiate<Shooting_Bullet>(GetParent()->GetParent());
	bullet->SetPlayerNum(playerNum_);
	bullet->GetTransform()->position_ = GetShotPos();
	bullet->GetTransform()->rotate_ = ((GameObject*)GetParent())->GetTransform()->rotate_;
	bullet->SetDir(dir);
	bulletCount_--;
	GetComponent<Text>(textNum_).SetText("X"+std::to_string(bulletCount_));
}

XMVECTOR Shooting_Gun::GetShotPos()
{
	return GetComponent<Test_Model_ECSver>().GetBone("Bone");
}

void Shooting_Gun::SetDraw(bool isDraw)
{
	GetComponent<Test_Model_ECSver>().SetDraw(isDraw);
}

int Shooting_Gun::GetShotCount()
{
	return (MAX_BULLET - bulletCount_);
	// TODO: return ステートメントをここに挿入します
}

void Shooting_Gun::Reload()
{
	bulletCount_ = MAX_BULLET;
	GetComponent<Text>(textNum_).SetText("X"+std::to_string(bulletCount_));
}

void Shooting_Gun::Release()
{
}
