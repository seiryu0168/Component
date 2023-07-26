#pragma once
#include"../DirectX_11/Direct3D.h"
#include"../DirectX_11/Texture.h"
#include"DirectXMath.h"
#include"../GameObject/GameObject.h"
#include<list>

struct LineData
{
	float width;
	float endWidth;
	int   length;
	std::string textureName;
	LineData()
	{
		width = 0.5f;
		endWidth = 0.0f;
		length = 10;
		textureName = "Effect01.png";
	}

};
class LineParticle
{
	enum class LineMode
	{
		LINE_DEFAULT=0,
		LINE_CROSS,
	};

private:
	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWVP;
		XMFLOAT4	color;
	};

	//���_���
	struct VERTEX
	{
		XMFLOAT3 position;
		XMFLOAT3 uv;
	};

	float WIDTH_;//���C���p�[�e�B�N���̕�
	UINT LENGTH_;//���C���p�[�e�B�N���̃|�W�V�������L�������
	float endWidth_;
	XMFLOAT4 color_;
	//int* index_;

	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer* pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;

	std::shared_ptr<Texture> pTexture_;
	std::vector<int> indexList;
	std::list<XMFLOAT3> positionList_;
	GameObject* attachObject_;
	BLEND_MODE blendMode_;
public:
	LineParticle();
	LineParticle(GameObject* object);
	/// <summary>
	/// ���C���̈ʒu�ۑ�
	/// �ʒu���|�W�V�������X�g�ɒǉ�
	/// </summary>
	/// <param name="pos">���̊֐����Ă΂ꂽ���̈ʒu</param>
	void AddPosition(const XMFLOAT3& pos);
	/// <summary>
	/// �p�C�v��̃��C���p�[�e�B�N������
	/// </summary>
	/// <param name="pList"></param>
	/// <returns></returns>
	HRESULT CreateMeshPype(const std::list<XMFLOAT3>* pList);
	HRESULT CreateMeshPlate(const std::list<XMFLOAT3>* pList);
	/// <summary>
	/// ���C���p�[�e�B�N���Ɏg���摜�̃��[�h
	/// </summary>
	/// <param name="fileName"></param>
	/// <returns></returns>
	HRESULT Load(const std::string& fileName);
	/// <summary>
	/// ���C���p�[�e�B�N���̐F�ݒ�
	/// </summary>
	/// <param name="col">�F</param>
	void SetColor(const XMFLOAT4& col);
	/// <summary>
	/// �C���f�b�N�X����
	/// </summary>
	void SetIndex();

	void Update();
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();
	/// <summary>
	/// ���C���p�[�e�B�N���̊e�p�����[�^�ݒ�
	/// </summary>
	/// <param name="width">����</param>
	/// <param name="length">�|�W�V�����̕ۑ���</param>
	/// <param name="tipWidth">�I�[�̕�</param>
	void SetLineParameter(const LineData& data);
	void SetBlendMode(BLEND_MODE mode) { blendMode_ = mode; }
	void SetWidth(float width) { WIDTH_ = max(0,width); }
	void SetEndWidth(float endWidth) { endWidth_ = max(0, endWidth); }
	void SetLength(UINT length) { LENGTH_ = length; }
	/// <summary>
	/// �|�W�V�������X�g�̍폜
	/// </summary>
	GameObject* GetAttachedObject() { return attachObject_; }
	void DeleteLine();
	void Release();



};

