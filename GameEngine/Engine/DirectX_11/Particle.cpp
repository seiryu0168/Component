#include "Particle.h"
#include"../GameObject/Camera.h"

Particle::Particle()
{
}

Particle::Particle(GameObject* object)
	:attacheObject_(object)
{

}

//�f�X�g���N�^
Particle::~Particle()
{
	Release();
}

//������
void Particle::Initialize()
{
}

//�X�V
void Particle::Update()
{
	UpdateEmitter();
	UpdateParticle();
}

void Particle::UpdateParticle()
{
	for (auto particleCount = particleList_.begin(); particleCount != particleList_.end();)
	{
		//�p�[�e�B�N���̎������Ȃ��Ȃ�����
		if ((*particleCount)->life == 0)
		{
			(*particleCount)->pEmitter->particleCount--;
			SAFE_DELETE(*particleCount);
			particleCount = particleList_.erase(particleCount);
		}

		//�����Ă�ꍇ
		else
		{
			(*particleCount)->life--;

			//�p�[�e�B�N���̈ʒu���X�V
			(*particleCount)->nowData.position+= (*particleCount)->deltaData.position;
			//(*particleCount)->nowData.position.y += (*particleCount)->deltaData.position.y;
			//(*particleCount)->nowData.position.z += (*particleCount)->deltaData.position.z;

			//�p�[�e�B�N���̑��x(�ړ���)�������x�ōX�V
			(*particleCount)->deltaData.position *= (*particleCount)->acceleration;
			//(*particleCount)->deltaData.position.y *= (*particleCount)->acceleration;
			//(*particleCount)->deltaData.position.z *= (*particleCount)->acceleration;
			
			//�d��
			(*particleCount)->deltaData.position += XMVectorSet(0,-(*particleCount)->gravity,0,0);

			//�g�嗦���X�V
			(*particleCount)->nowData.scale.x *= (*particleCount)->deltaData.scale.x;
			(*particleCount)->nowData.scale.y *= (*particleCount)->deltaData.scale.y;

			//�F�X�V
			(*particleCount)->nowData.color.x += (*particleCount)->deltaData.color.x; //R
			(*particleCount)->nowData.color.y += (*particleCount)->deltaData.color.y; //G
			(*particleCount)->nowData.color.z += (*particleCount)->deltaData.color.z; //B
			(*particleCount)->nowData.color.w += (*particleCount)->deltaData.color.w; //A
			
			particleCount++;
		}

	}
}

void Particle::UpdateEmitter()
{
	for (auto emitterCount = emitterList_.begin(); emitterCount != emitterList_.end();)
	{
		//����ł�G�~�b�^�[�̏���
		if ((*emitterCount)->isDead)
		{
			//�p�[�e�B�N���o�ĂȂ���΍폜
			if ((*emitterCount)->particleCount == 0)
			{
				(*emitterCount)->pBillBoard->Release();
				SAFE_DELETE((*emitterCount)->pBillBoard);
				SAFE_DELETE(*emitterCount);
				emitterCount = emitterList_.erase(emitterCount);
			}
			else
				emitterCount++;
		}
		else
		{
			//�p�[�e�B�N���𔭐�������
			if ((*emitterCount)->data.delay == 0 || ((*emitterCount)->frameCount % (*emitterCount)->data.delay) == 0)
			{
				for (int particleNum = 0; particleNum < (*emitterCount)->data.number; particleNum++)
				{
					ParticleData* pParticle = new ParticleData;
					
					//�����ʒu
					pParticle->nowData.position = XMLoadFloat3(&(*emitterCount)->data.position);
					float deltaX = (float)((*emitterCount)->data.positionErr.x == 0 ? 0 : rand() % (int)((*emitterCount)->data.positionErr.x * 201) - ((*emitterCount)->data.positionErr.x * 100))/100.0f;
					float deltaY = (float)((*emitterCount)->data.positionErr.y == 0 ? 0 : rand() % (int)((*emitterCount)->data.positionErr.y * 201) - ((*emitterCount)->data.positionErr.y * 100))/100.0f;
					float deltaZ = (float)((*emitterCount)->data.positionErr.z == 0 ? 0 : rand() % (int)((*emitterCount)->data.positionErr.z * 201) - ((*emitterCount)->data.positionErr.z * 100))/100.0f;

					pParticle->nowData.position += XMVectorSet(deltaX,deltaY,deltaZ,0);
	

					//�����T�C�Y
					deltaX = (float)((*emitterCount)->data.sizeErr.x == 0 ? 0 : rand() % (int)((*emitterCount)->data.sizeErr.x * 201) - ((*emitterCount)->data.sizeErr.x * 100)) / 100.0f + 1.0f;
					deltaY = (float)((*emitterCount)->data.sizeErr.y == 0 ? 0 : rand() % (int)((*emitterCount)->data.sizeErr.y * 201) - ((*emitterCount)->data.sizeErr.y * 100)) / 100.0f + 1.0f;
					pParticle->nowData.scale.x = (*emitterCount)->data.size.x * deltaX;
					pParticle->nowData.scale.y = (*emitterCount)->data.size.y * deltaY;

					//�����F
					pParticle->nowData.color = (*emitterCount)->data.color;

					//�p�[�e�B�N�����˕���
					XMVECTOR vecDir = XMLoadFloat3(&(*emitterCount)->data.dir);
					deltaX = (float)((*emitterCount)->data.dirErr.x == 0 ? 0 : rand() % (int)((*emitterCount)->data.dirErr.x * 201) - ((*emitterCount)->data.dirErr.x * 100)) / 100.0f;
					deltaY = (float)((*emitterCount)->data.dirErr.y == 0 ? 0 : rand() % (int)((*emitterCount)->data.dirErr.y * 201) - ((*emitterCount)->data.dirErr.y * 100)) / 100.0f;
					deltaZ = (float)((*emitterCount)->data.dirErr.z == 0 ? 0 : rand() % (int)((*emitterCount)->data.dirErr.z * 201) - ((*emitterCount)->data.dirErr.z * 100)) / 100.0f;

					XMMATRIX matX = XMMatrixRotationX(XMConvertToRadians(deltaX));
					XMMATRIX matY = XMMatrixRotationY(XMConvertToRadians(deltaY));
					XMMATRIX matZ = XMMatrixRotationZ(XMConvertToRadians(deltaZ));

					vecDir = XMVector3TransformCoord(vecDir, matX * matY * matZ);

					float spd = (float)((*emitterCount)->data.speedErr == 0 ? 0 : (int)((*emitterCount)->data.speedErr * 201) - ((*emitterCount)->data.speedErr * 100)) / 100.0f+1.0f;
		
					vecDir = XMVector3Normalize(vecDir) * (*emitterCount)->data.firstSpeed * spd;
					//XMStoreFloat3(&pParticle->deltaData.position, vecDir);
					pParticle->deltaData.position = vecDir;
					pParticle->deltaData.scale = (*emitterCount)->data.scale;		//�p�[�e�B�N���̊g�嗦
					pParticle->deltaData.color = (*emitterCount)->data.deltaColor;	//�p�[�e�B�N���̐F
				

					pParticle->life = (*emitterCount)->data.lifTime;				//�p�[�e�B�N���̎���
					pParticle->gravity = (*emitterCount)->data.gravity;				//�p�[�e�B�N���̂ɂ�����d��
					pParticle->acceleration = (*emitterCount)->data.acceleration;	//�p�[�e�B�N���̉����x
					
					pParticle->pEmitter = *emitterCount;

					//�쐬�����p�[�e�B�N�������X�g�ɓ����
					particleList_.push_back(pParticle);

					pParticle->pEmitter->particleCount++;
				}
			}

			//�p�[�e�B�N���̔��ˊԊu��0�t���[���̏ꍇ�A�ꔭ�o���č폜
			if ((*emitterCount)->data.delay == 0)
			{
				(*emitterCount)->isDead = true;
			}

			emitterCount++;
		}
	}
}

int Particle::ParticleStart(EmitterData data)
{
	int handle = 0;
	for (auto emitterCount : emitterList_)
	{
		handle++;
	}

	Emitter* pEmitter = new Emitter;

	pEmitter->data = data;
	pEmitter->frameCount = 0;

	pEmitter->pBillBoard = new BillBoard;
	pEmitter->pBillBoard->Load(data.textureFileName);
	emitterList_.push_back(pEmitter);
	handle = emitterList_.size() - 1;
	pEmitter->hParticle = handle;
	return handle;
	//return handle;
}

void Particle::KillEmitter(int hEmitter)
{
	for (auto itr : emitterList_)
	{
		if (itr->hParticle == hEmitter)
		{
			itr->isDead = true;
			return;
		}
	}
}

void Particle::SetData(EmitterData data)
{
	int handle = 0;
	for (auto emitterCount : emitterList_)
	{
		handle++;
	}

	Emitter* pEmitter = new Emitter;

	pEmitter->data = data;
	pEmitter->frameCount = 0;

	pEmitter->pBillBoard = new BillBoard;
	pEmitter->pBillBoard->Load(data.textureFileName);
	emitterList_.push_back(pEmitter);
	handle = emitterList_.size() - 1;
	pEmitter->hParticle = handle;
	//return handle;
}

//�`��
void Particle::Draw()
{
	Update();
	Direct3D::SetShader(SHADER_TYPE::SHADER_EFF);
	Direct3D::SetBlendMode(BLEND_MODE::BLEND_ADD);

	for (auto i = particleList_.begin(); i != particleList_.end(); i++)
	{
		XMMATRIX matW;

		//�ړ��s��
		XMFLOAT3 pos = StoreFloat3((*i)->nowData.position);
		XMMATRIX matTrans = XMMatrixTranslation(pos.x, pos.y, pos.z);
		
		//�g��s��
		XMMATRIX matScale = XMMatrixScaling((*i)->nowData.scale.x, (*i)->nowData.scale.y, 1.0f);

		matW = matScale * Camera::GetBillBoardMatrix() * matTrans;
		(*i)->pEmitter->pBillBoard->Draw(matW, (*i)->nowData.color);
	}
}

//�J��
void Particle::Release()
{
	for (auto itr = particleList_.begin(); itr != particleList_.end(); itr++)
	{
		SAFE_DELETE(*itr);
	}

}