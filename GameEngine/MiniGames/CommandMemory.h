#pragma once
#include "Framework.h"

class CommandMemory : public Framework
{
	std::vector<int> cmList_;	//�R�}���h�̔z��
	std::vector<int>::iterator itr_;	//�R�}���h�̔z��ɑ΂���C�e���[�^
	int NowPlayer_;				//���ݑ��쒆�̃v���C���[

	Text* text_;
public:
	CommandMemory(Object* parent);
	~CommandMemory();

	void Initialize() override;

	//����ꂽ�{�^����id�������Ă��邩���؂���
	void sendCommand(int Button, int Playerid);


};

