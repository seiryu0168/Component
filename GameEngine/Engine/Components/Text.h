#pragma once
#include"../DirectX_11/Direct2D.h"
//#include"Engine/DirectX_11/Direct3D.h"
#include<string>
typedef D2D_RECT_F TEXT_RECT;//left top right bottom
typedef D2D1_POINT_2F TEXT_POSITION;

	struct FontData
	{
		float fontSize_;
		std::wstring fontName_;		//�t�H���g��
		std::wstring locale_;			//���P�[��
		DWRITE_FONT_WEIGHT	fontWaight_;		//�t�H���g�̑���
		DWRITE_FONT_STYLE   fontStyle_;			//�t�H���g�X�^�C��
		DWRITE_FONT_STRETCH fontStretch_;
		IDWriteFontCollection* pCollection_;	//�t�H���g�R���N�V����
		FontData()
		{
			fontSize_ = 72.0f;
			fontWaight_ = DWRITE_FONT_WEIGHT_REGULAR;
			fontStyle_ = DWRITE_FONT_STYLE_NORMAL;
			fontStretch_ = DWRITE_FONT_STRETCH_NORMAL;
			pCollection_ = nullptr;
		}
	};

class Text
{
private:
	size_t				  textLength_;		//�e�L�X�g�̒���
	D2D1_RECT_F			  layoutRect_;		//���C�A�E�g���N�g
	std::wstring		  pText_;			//�e�L�X�g
	std::wstring		  pFontName_;
	ID2D1SolidColorBrush* pColorBrush_;		//�u���V	
	IDWriteFactory*		  pWriteFactory_;	//�����`��̃t�@�N�g��
	IDWriteTextFormat*	  pTextFormat_;     //�e�L�X�g�t�H�[�}�b�g
	IDWriteTextLayout*	  pLayout_;			//�e�L�X�g���C�A�E�g
public:
	TEXT_POSITION				  transform2D;		//���W
	Text();
	//Text(std::string text);
	~Text();
	int Load(const std::string& text, const std::string& fontName, const TEXT_RECT& rect, const STARTING_TYPE& type);
	void Initialize();
	void Draw();
	void SetAlinmentType(const STARTING_TYPE& type);
	HRESULT SetFont(const FontData& data);
	void SetColor(const XMFLOAT4& color);
	HRESULT SetTextSize(float size,UINT32 startPos,UINT32 length);
	HRESULT SetTextSize(float size);
	HRESULT SetFontWeight(DWRITE_FONT_WEIGHT weightType,UINT32 startPos,UINT32 length);
	HRESULT SetText(const std::string& text);
	void SetTransform(const TEXT_POSITION& pos);
	void SetTextLayout();
	void SetRatio(float ratioX,float ratioY);
	void SetPosition(const XMFLOAT2& position);
	void SetRect(const TEXT_RECT& rect);
	const TEXT_RECT& GetRect() const { return layoutRect_; }
	int GetTextSize() const;
	void Release();

};
