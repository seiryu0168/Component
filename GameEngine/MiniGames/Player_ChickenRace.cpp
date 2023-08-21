#include "Player_ChickenRace.h"
#include "ChickenRace.h"
#include "../Engine/DirectX_11/Input.h"
#include <format>
#include "../Engine/Components/Particle.h"

Player_ChickenRace::Player_ChickenRace(Object* parent)
	: Player(parent, "Player_ChickenRace"), watch_(), text_(nullptr), TargetTime_(0), CallFin_(false)
{
}

void Player_ChickenRace::Initialize()
{
	Text text("", "ninepin", { 0,0,500, 50 });
	text.SetRatio(0.18f + Playerid_ * 0.49f, 0.61f);
	AddComponent<Text>(text);

	//コンポーネントを回収し、加工可能にする
	text_ = &GetComponent<Text>();
}

void Player_ChickenRace::Update()
{
	if (!CallFin_)
	{
		float f = watch_.GetSeconds<float>();

		//余計な桁を表示しない
		text_->SetText(std::format("{:g}", f));

		if (Input::GetPadOnlyDown(Playerid_))
		{
			if (watch_.IsLock())
			{
				watch_.UnLock();
				CreateParticle();
			}
			else
			{
				Finish();
				return;
			}
		}

		//1秒かけて時間を見えなくする
		if (f >= 2)
		{
			text_->SetColor({ 1,1,1, std::lerp(1.0f, 0.0f, f - 2) });
		}
	}
}

void Player_ChickenRace::Draw()
{
}

void Player_ChickenRace::Release()
{
}

void Player_ChickenRace::CreateParticle()
{
	//火花
	Particle particle(this);
	EmitterData data;
	data.position = XMFLOAT3(0, 0.05f, 0);
	data.delay = 5;
	data.number = 15;
	data.lifeTime = 20;
	data.dir = XMFLOAT3(0, 1, 0);
	data.dirErr = XMFLOAT3(150, 150, 90);
	data.gravity = 0.001f;
	data.speedErr = 0.8f;
	data.size = XMFLOAT2(0.2f, 0.2f);
	data.sizeErr = XMFLOAT2(0.4f, 0.4f);
	data.scale = XMFLOAT2(1, 1);
	data.color = XMFLOAT4(1, 1, 0.1f, 1);
	data.deltaColor = XMFLOAT4(0, -1.0f / 20, 0, -1.0f / 20);
	data.textureFileName = "Assets\\Image\\Cloud.png";
	data.firstSpeed = 0.1f;
	data.blendMode = BLEND_MODE::BLEND_ADD;
	particle.SetData(data);
	AddComponent<Particle>(particle);
}

void Player_ChickenRace::Finish()
{
	watch_.Lock();
	text_->SetColor({ 1,1,1,1 });
	text_->SetText(std::format("{:g}", watch_.GetSeconds<float>()));
	ChickenRace* c = (ChickenRace*)GetParent();
	c->SendTime(this, watch_.GetSeconds<float>());
	RemoveComponent<Particle>();
	CallFin_ = true;
}