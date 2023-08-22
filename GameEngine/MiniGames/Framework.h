#pragma once
#include "../Engine/GameObject/Object.h"
#include "../Engine/Time.h"
#include "../Engine/Components/Text.h"

//�~�j�Q�[���̘g�g�݂ƂȂ���N���X
class Framework : public Object
{
protected:
	int Players_;	//�v���C�l��
	Time::Watch GameTime_;	//�~�j�Q�[���̎���

	//�v���C�l���������v���C���[�̐������s��
	template<class T>
	void PlayerInitialize()
	{
		for (int i = 0; i < Players_; i++)
		{
			auto p = Instantiate<T>(this);
			p->SetID(i);
		}
	}

	//StaticUpdate�ŌĂяo����pause�������\�ɂȂ�
	void Pause();
public:
	Framework(Object* parent, const std::string& name);
	virtual ~Framework();
};

