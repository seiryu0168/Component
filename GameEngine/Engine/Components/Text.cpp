#include "Text.h"
#include<locale.h>
#include<filesystem>

Text::Text()
{
	textLength_	   = 0;
	transform2D = { 0,0 };
	layoutRect_ = { 0,0,100,100 };

	pText_		   = L"";
	pColorBrush_   = nullptr;
	//pWriteFactory_ = nullptr;
	pTextFormat_   = nullptr;
	pLayout_	   = nullptr;
	Initialize();

}
Text::~Text()
{
	//Release();
}

int Text::GetTextSize() const
{
	return (int)pLayout_->GetFontSize();
}

void Text::Release()
{
	SAFE_RELEASE(pTextFormat_);
	//SAFE_RELEASE(pWriteFactory_);
	//SAFE_RELEASE(pColorBrush_);
}

int Text::Load(const std::string& text, const std::string& fontName, const TEXT_RECT& rect, const STARTING_TYPE& type)
{
	//フォント名用の配列用意
	size_t ret;
	FontData data;
	int a=mbstowcs_s(&ret, (wchar_t*)data.fontName_.c_str(), fontName.length() + 1, fontName.c_str(), fontName.length());
	size_t textSize;

	//描画するテキスト用の配列を用意する
	textLength_ = text.length()+1;

	//現在のロケール取得
	std::string locale= setlocale(LC_CTYPE, NULL);
	
	data.locale_ = (wchar_t*)L"en-us";
	//ロケールを日本語に変更
	setlocale(LC_CTYPE, "ja-jp");
	//描画するテキストをstringからwstringに変換
	mbstowcs_s(&textSize, (wchar_t*)pText_.c_str(), textLength_, text.c_str(), text.length());
	//ロケールを元に戻す
	setlocale(LC_CTYPE, locale.c_str());
	//変換した文字数
	textLength_ = textSize;

	//HRESULT hr=DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&pWriteFactory_));
	////テキストフォーマットにフォントを設定
	//hr=SetFont(data);
	//if (FAILED(hr))
	//{
	//	return hr;
	//}
	//pWriteFactory_->CreateTextFormat(pFontName_, NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL,72.0f, L"ja-jp", &pTextFormat_);
	//アライメント設定
	HRESULT hr;
	SetAlinmentType(type);
	//描画のためのブラシ作成
	hr=D2D::GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &pColorBrush_);
	if (FAILED(hr))
	{
		return hr;
	}
	//テキスト表示の領域設定
	layoutRect_ = rect;
	
	//テキストレイアウト作成
	hr=D2D::GetDWriteFactory()->CreateTextLayout(pText_.c_str(), (UINT32)textLength_, pTextFormat_, (layoutRect_.right - layoutRect_.left), (layoutRect_.bottom - layoutRect_.top), &pLayout_);
	if (FAILED(hr))
	{
		return hr;
	}

	return 0;
}

void Text::Initialize()
{
	//フォント名用の配列用意
	//size_t ret;
	FontData data;
	std::wstring fontName= L"Arial";
	std::wstring&& text = L"sumple";
	//size_t textSize;
	data.fontName_ = fontName;
	data.pCollection_ = D2D::GetCollection();

	//描画するテキスト用の配列を用意する
	textLength_ = text.length() + 1;

	pText_ = text;

	//現在のロケール取得
	std::string locale = setlocale(LC_CTYPE, NULL);

	data.locale_ = (wchar_t*)L"en-us";
	data.fontWaight_ = DWRITE_FONT_WEIGHT_NORMAL;
	data.fontStyle_ = DWRITE_FONT_STYLE_NORMAL;
	data.fontStretch_=DWRITE_FONT_STRETCH_NORMAL;

	//HRESULT hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&pWriteFactory_));
	//assert(FAILED(hr) == false);
	
	HRESULT hr;
	//テキストフォーマットにフォントを設定
	hr = SetFont(data);
	assert(FAILED(hr) == false);
	//アライメント設定
	SetAlinmentType(LEFT_TOP);
	//描画のためのブラシ作成
	hr = D2D::GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &pColorBrush_);
	assert(FAILED(hr) == false);
	//テキスト表示の領域設定
	layoutRect_ = {0,0,500,100};

	//テキストレイアウト作成
	hr = D2D::GetDWriteFactory()->CreateTextLayout(pText_.c_str(), (UINT32)textLength_, pTextFormat_, (layoutRect_.right - layoutRect_.left), (layoutRect_.bottom - layoutRect_.top), &pLayout_);
	assert(FAILED(hr) == false);
}

void Text::Draw()
{
	Direct3D::SetDepthBufferWriteEnable(false);
	D2D::GetRenderTarget()->BeginDraw();
	D2D::GetRenderTarget()->DrawTextLayout(transform2D, pLayout_, pColorBrush_);
	//D2D::GetRenderTarget()->DrawText(pText_, textLength_, pTextFormat_,
	//							    { transform2D.x + layoutRect_.left,
	//								  transform2D.y + layoutRect_.top,
	//								  transform2D.x + layoutRect_.right,
	//								  transform2D.y + layoutRect_.bottom }, pColorBrush_);
	D2D::GetRenderTarget()->EndDraw();
	Direct3D::SetDepthBufferWriteEnable(true);
}
void Text::SetColor(const XMFLOAT4& color)
{
	D2D1_COLOR_F colorF = { color.x, color.y,color.z,color.w };
	pColorBrush_->SetColor(colorF);
}
void Text::SetRatio(float ratioX, float ratioY)
{
	transform2D.x = Direct3D::GetScreenWidth() * ratioX;
	transform2D.y = Direct3D::GetScreenHeight() * ratioY;
}

void Text::SetPosition(const XMFLOAT2& position)
{
	transform2D.x = 0.5f*position.x+0.5f*Direct3D::GetScreenWidth();
	transform2D.y = -(0.5f * position.y)+ 0.5f * Direct3D::GetScreenHeight();
}

void Text::SetTextLayout()
{
	//pWriteFactory_->CreateTextLayout()
}

HRESULT Text::SetText(const std::string& text)
{
	//size_t textSize;
	//textLength_ = text.length() + 1;
	//wchar_t* txt = nullptr;
	//SAFE_DELETE(pText_);
	//txt = new wchar_t[textLength_];
	std::filesystem::path str = text;
	std::string locale = setlocale(LC_CTYPE, NULL);
	setlocale(LC_CTYPE, "ja-jp");
	//MultiByteToWideChar()
	//errno_t err = mbstowcs_s(&textSize, txt, textLength_, text.c_str(), text.length()+2);
	//std::wstring wStr(txt);
	pText_ = str.wstring();
	setlocale(LC_CTYPE, locale.c_str());
	textLength_ = pText_.length();
	SAFE_RELEASE(pLayout_);
	return D2D::GetDWriteFactory()->CreateTextLayout(pText_.c_str(), (UINT32)textLength_, pTextFormat_, (layoutRect_.right - layoutRect_.left), (layoutRect_.bottom - layoutRect_.top), &pLayout_);
}

HRESULT Text::SetFontWeight(DWRITE_FONT_WEIGHT weightType, UINT32 startPos, UINT32 length)
{
	DWRITE_TEXT_RANGE range;
	range.length = length;
	range.startPosition = startPos;
	return pLayout_->SetFontWeight(weightType, range);
}

HRESULT Text::SetFontStyle(DWRITE_FONT_STYLE style, const UINT32& startPos, const UINT32& length)
{
	HRESULT hr;
	DWRITE_TEXT_RANGE range;
	range.length = length;
	range.startPosition = startPos;
	return pLayout_->SetFontStyle(style, range);
}




HRESULT Text::SetTextSize(float size, UINT32 startPos, UINT32 length)
{
	HRESULT hr;
	if ((long long)startPos + length >= (UINT)textLength_)
	{
		length = startPos + length - (UINT32)textLength_;
	}
	hr = pLayout_->SetFontSize(size, { startPos,length });
	return hr;
}
HRESULT Text::SetTextSize(float size)
{
	HRESULT hr;
	UINT32 fontNameSize = pTextFormat_->GetFontFamilyNameLength() * 2;
	UINT32 localeSize = pTextFormat_->GetLocaleNameLength() * 2;

	//フォントデータ作成
	FontData data;

	data.fontSize_ = size;
	
	hr = pTextFormat_->GetFontFamilyName((WCHAR*)data.fontName_.c_str(), fontNameSize);
	if (FAILED(hr))
		return hr;

	hr = pTextFormat_->GetLocaleName((WCHAR*)data.locale_.c_str(), localeSize);
	if (FAILED(hr))
		return hr;
	//書式設定
	SAFE_RELEASE(pTextFormat_);
	hr = D2D::GetDWriteFactory()->CreateTextFormat((WCHAR*)data.fontName_.c_str(), data.pCollection_, data.fontWaight_, data.fontStyle_, data.fontStretch_, data.fontSize_, data.locale_.c_str(), &pTextFormat_);
	if (FAILED(hr))
		return hr;
	SAFE_RELEASE(pLayout_);
	hr = D2D::GetDWriteFactory()->CreateTextLayout(pText_.c_str(), (UINT32)textLength_, pTextFormat_, (layoutRect_.right - layoutRect_.left), (layoutRect_.bottom - layoutRect_.top), &pLayout_);
		return hr;
}

HRESULT Text::SetFontCollection(IDWriteFontCollection* collection, UINT32 startPos, UINT32 length)
{
	DWRITE_TEXT_RANGE range;
	range.startPosition = startPos;
	range.length = length;
	HRESULT hr = pLayout_->SetFontCollection(collection, range);
	return hr;
}

HRESULT Text::SetFont(const FontData& data)
{
	FontData fData;
	fData.fontName_ = data.fontName_;
	fData.pCollection_ = data.pCollection_;
	fData.locale_ = data.locale_;
	fData.fontWaight_ = data.fontWaight_;
	fData.fontStyle_ = data.fontStyle_;
	fData.fontStretch_ = data.fontStretch_;
	HRESULT hr= D2D::GetDWriteFactory()->CreateTextFormat(fData.fontName_.c_str(), fData.pCollection_, data.fontWaight_/*DWRITE_FONT_WEIGHT_REGULAR*/, data.fontStyle_/*DWRITE_FONT_STYLE_NORMAL*/, data.fontStretch_/*DWRITE_FONT_STRETCH_NORMAL*/, data.fontSize_, data.locale_.c_str(), &pTextFormat_);
	assert(hr==S_OK);
	return hr;
}
HRESULT Text::SetFont(const std::string& fontName, const UINT32& startPos, const UINT32& length)
{
	std::filesystem::path str = fontName;
	DWRITE_TEXT_RANGE range;
	range.startPosition = startPos;
	range.length = length;
	BOOL isFont = false;
	std::filesystem::path name = fontName;
	UINT32 index;
	D2D::GetCollection()->FindFamilyName((wchar_t*)name.wstring().c_str(), &index, &isFont);
	if (isFont == false)
	{
		D2D::GetSystemFontCollection()->FindFamilyName((wchar_t*)name.wstring().c_str(), &index, &isFont);
		if (isFont)
			pLayout_->SetFontCollection(D2D::GetSystemFontCollection(), range);
		else
			return E_FAIL;
	}
	
	pLayout_->SetFontCollection(D2D::GetCollection(),range);
	HRESULT hr = pLayout_->SetFontFamilyName(str.wstring().c_str(), range);
	return hr;
}
void Text::SetTransform(const TEXT_POSITION& pos)
{
	transform2D = pos;
}

void Text::SetRect(const TEXT_RECT& rect)
{	
	layoutRect_ = rect;
}
void Text::SetAlinmentType(const STARTING_TYPE& type)
{

	switch (type)
	{
	case LEFT_TOP:
		//原点左上
		pTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
		pTextFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
		break;

	case LEFT_CENTER:
		//原点左
		pTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
		pTextFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
		break;
	
	case LEFT_BOTTOM:
		//原点左下
		pTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
		pTextFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_FAR);
		break;

	case CENTER_TOP:
		//原点上
		pTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		pTextFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
		break;
	
	case CENTER_CENTER:
		//原点中央
		pTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		pTextFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
		break;
	
	case CENTER_BOTTOM:
		//原点下
		pTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		pTextFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_FAR);
		break;

	case RIGHT_TOP:
		//原点右上
		pTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING);
		pTextFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
		break;
	case RIGHT_CENTER:
		//原点右
		pTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING);
		pTextFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
		break;

	case RIGHT_BOTTOM:
		//原点右下
		pTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING);
		pTextFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_FAR);
		break;

	default:
		//デフォルト
		pTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
		pTextFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
		break;
	}
}

