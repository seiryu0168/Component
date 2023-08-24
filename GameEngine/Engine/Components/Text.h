#pragma once
#include"../DirectX_11/Direct2D.h"
//#include"Engine/DirectX_11/Direct3D.h"
#include<string>
typedef D2D_RECT_F TEXT_RECT;//left top right bottom
typedef D2D1_POINT_2F TEXT_POSITION;

	struct FontData
	{
		float fontSize_;
		std::wstring fontName_;		//フォント名
		std::wstring locale_;			//ロケール
		DWRITE_FONT_WEIGHT	fontWaight_;		//フォントの太さ
		DWRITE_FONT_STYLE   fontStyle_;			//フォントスタイル
		DWRITE_FONT_STRETCH fontStretch_;
		IDWriteFontCollection* pCollection_;	//フォントコレクション
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
	size_t				  textLength_;		//テキストの長さ
	D2D1_RECT_F			  layoutRect_;		//レイアウトレクト
	std::wstring		  pText_;			//テキスト
	std::wstring		  pFontName_;
	ID2D1SolidColorBrush* pColorBrush_;		//ブラシ
	//IDWriteFactory5*		  pWriteFactory_;	//文字描画のファクトリ
	IDWriteTextFormat*	  pTextFormat_;     //テキストフォーマット
	IDWriteTextLayout*	  pLayout_;			//テキストレイアウト
	int renderTargetNum_;
	int layerNum_;
	TEXT_POSITION defaultPos_;
public:
	TEXT_POSITION				  transform2D;		//座標
	Text(const int& renderTargetNum=0);
	Text(const std::string& text, const std::string& fontName, const TEXT_RECT& rect, int renderTargetNum = 0 , const DWRITE_FONT_WEIGHT& wight = DWRITE_FONT_WEIGHT_NORMAL, const DWRITE_FONT_STYLE& style = DWRITE_FONT_STYLE_NORMAL, const DWRITE_FONT_STRETCH& stretch = DWRITE_FONT_STRETCH_NORMAL, const ALIGNMENT_TYPE& type = LEFT_TOP);
	//Text(std::string text);
	~Text();
	int Load(const std::string& text, const std::string& fontName, const TEXT_RECT& rect, const ALIGNMENT_TYPE& type);
	void Initialize();
	void Draw();
	void SetAlignmentType(const ALIGNMENT_TYPE& type);
	void SetColor(const XMFLOAT4& color);
	HRESULT SetFont(const FontData& data);
	HRESULT SetFont(const std::string& fontName, const UINT32& startPos = 0, const UINT32& length=UINT32_MAX);
	HRESULT SetText(const std::string& text);
	HRESULT SetTextSize(float size,UINT32 startPos,UINT32 length);
	HRESULT SetTextSize(float size);
	HRESULT SetFontCollection(IDWriteFontCollection* collection,UINT32 startPos,UINT32 length);
	HRESULT SetFontWeight(DWRITE_FONT_WEIGHT weightType,UINT32 startPos,UINT32 length);
	HRESULT SetFontStyle(DWRITE_FONT_STYLE style,const UINT32& startPos,const UINT32& length);
	
	void SetTransform(const TEXT_POSITION& pos);
	void SetTextLayout();
	void SetRatio(float ratioX,float ratioY);
	void SetPosition(const XMFLOAT2& position);
	void SetRect(const TEXT_RECT& rect);
	const TEXT_RECT& GetRect() const { return layoutRect_; }
	int GetTextSize() const;
	void Release();

};

