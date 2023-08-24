#include "Brightness.h"
//#include "Components/Image.h"
#include "Components/Transform.h"
#include "DirectX_11/Texture.h"
#include <memory>
#include "DirectX_11/Direct3D.h"

namespace
{
	std::unique_ptr<Texture> pTexture_;

	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;	//�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@

	Transform transform_;

	float Ratio = 1;

	struct CONSTANT_BUFFER
	{
		XMMATRIX matWorld;
		XMMATRIX matUVTrans;
		XMFLOAT4 color;
		XMFLOAT4 ChangeColor;
	};

	const struct VERTEX
	{
		XMVECTOR position;
		XMVECTOR uv;
	} vertices[] =
	{
		//1
		XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f),	XMVectorSet(0.0f,0.0f,0.0f,0.0f),	// �l�p�`�̒��_�i����j
		XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),	XMVectorSet(1.0f,0.0f,0.0f,0.0f),	// �l�p�`�̒��_�i�E��j
		XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),	XMVectorSet(1.0f,1.0f,0.0f,0.0f),	// �l�p�`�̒��_�i�E���j
		XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f),	XMVectorSet(0.0f,1.0f,0.0f,0.0f),   // �l�p�`�̒��_�i�����j
	};
	static const int vertexNum_ = 4;

	static const int index[] = { 0,1,2, 0,2,3 };

	static const int indexNum_ = 6;
}

namespace Brightness
{
	void CreateVB();
	void CreateIB();
	void CreateCB();
	
}

namespace Brightness
{
	void Initialize()
	{
		CreateVB();
		CreateIB();
		CreateCB();

		pTexture_ = std::make_unique<Texture>();
		pTexture_->Load("Assets\\Image\\Filter.png");

		/*Image_.Load("Assets\\Image\\Filter.png");
		Image_.SetPositionAtPixel({ 0,0,0 });
		Image_.SetSize({ (float)Direct3D::GetScreenWidth(), (float)Direct3D::GetScreenHeight(), 1 });
		Image_.SetAlpha(0);*/
		//transform_.position_ = { -1, -1,0 };
		transform_.scale_ = { (float)Direct3D::GetScreenWidth(), (float)Direct3D::GetScreenHeight(), 1 };
	}

	void SetRatio(float ratio)
	{
		Ratio = ratio;
	}

	void Draw()
	{
		Direct3D::SetShader(SHADER_TYPE::SHADER_2D);
		Direct3D::SetBlendMode(BLEND_MODE::BLEND_DEFAULT);
		Direct3D::SetDepthBufferWriteEnable(false);
		//�R���X�^���g�o�b�t�@�ɏ���n��
		transform_.Calclation();

		float rectX = pTexture_->GetWidth();
		float rectY = pTexture_->GetHeight();

		//��ʂ̃T�C�Y�ɍ��킹��s��
		XMMATRIX matImageSize = XMMatrixScaling((float)(1.0f / Direct3D::GetScreenWidth()), (float)(1.0f / Direct3D::GetScreenHeight()), 1.0f);
		//�؂蔲���T�C�Y�ɍ��킹��s��
		XMMATRIX matCut = XMMatrixScaling(rectX, rectY, 1.0f);
		CONSTANT_BUFFER cb;

		//�ŏI�I�ȍs��
		cb.matWorld = XMMatrixTranspose(matCut*transform_.GetWorldScaleMatrix() * /*matImageSize **/ transform_.GetWorldRotateMatrix() * transform_.GetWorldTranslateMatrix());

		XMMATRIX matTexTrans = XMMatrixTranslation(0, 0, 1.0f);
		XMMATRIX matTexScale = XMMatrixScaling(1, 1, 1.0f);

		cb.matUVTrans = XMMatrixTranspose(matTexScale * matTexTrans);
		cb.color = XMFLOAT4(0, 0, 0, Ratio);
		cb.ChangeColor = { 0,0,0,0 };

		D3D11_MAPPED_SUBRESOURCE pdata;
		Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPU����̃f�[�^�A�N�Z�X���~�߂�
		memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));					// �f�[�^��l�𑗂�

		ID3D11SamplerState* pSampler = pTexture_->GetSampler();
		Direct3D::pContext->PSSetSamplers(0, 1, &pSampler);
		ID3D11ShaderResourceView* pSRV = pTexture_->GetSRV();
		Direct3D::pContext->PSSetShaderResources(0, 1, &pSRV);

		Direct3D::pContext->Unmap(pConstantBuffer_, 0);//�ĊJ

		//���_�A�C���f�b�N�X�A�R���X�^���g�o�b�t�@���Z�b�g

		//���_�o�b�t�@
		UINT stride = sizeof(VERTEX);
		UINT offset = 0;
		Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);

		// �C���f�b�N�X�o�b�t�@�[���Z�b�g
		stride = sizeof(int);
		offset = 0;
		Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);

		//�R���X�^���g�o�b�t�@
		Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//���_�V�F�[�_�[�p
		Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//�s�N�Z���V�F�[�_�[�p

		Direct3D::pContext->DrawIndexed(indexNum_, 0, 0);

		Direct3D::SetDepthBufferWriteEnable(true);
	}

	void CreateVB()
	{
		D3D11_BUFFER_DESC bd_vertex;
		bd_vertex.ByteWidth = sizeof(VERTEX) * vertexNum_;
		bd_vertex.Usage = D3D11_USAGE_DEFAULT;
		bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd_vertex.CPUAccessFlags = 0;
		bd_vertex.MiscFlags = 0;
		bd_vertex.StructureByteStride = 0;
		D3D11_SUBRESOURCE_DATA data_vertex;
		data_vertex.pSysMem = vertices;
		HRESULT hr = Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);
	}

	void CreateIB()
	{
		D3D11_BUFFER_DESC   bd;
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = sizeof(int) * indexNum_;
		bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
		bd.CPUAccessFlags = 0;
		bd.MiscFlags = 0;

		D3D11_SUBRESOURCE_DATA InitData;
		InitData.pSysMem = index;
		InitData.SysMemPitch = 0;
		InitData.SysMemSlicePitch = 0;
		HRESULT hr = Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
	}

	void CreateCB()
	{
		D3D11_BUFFER_DESC cb;
		cb.ByteWidth = sizeof(CONSTANT_BUFFER);
		cb.Usage = D3D11_USAGE_DYNAMIC;
		cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		cb.MiscFlags = 0;
		cb.StructureByteStride = 0;

		// �R���X�^���g�o�b�t�@�̍쐬
		HRESULT hr = Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
	}
}