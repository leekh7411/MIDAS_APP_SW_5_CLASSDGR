
// MIDAS_APP_SW_5_CLASSDGRDoc.cpp : CMIDAS_APP_SW_5_CLASSDGRDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MIDAS_APP_SW_5_CLASSDGR.h"
#endif

#include "MIDAS_APP_SW_5_CLASSDGRDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMIDAS_APP_SW_5_CLASSDGRDoc

IMPLEMENT_DYNCREATE(CMIDAS_APP_SW_5_CLASSDGRDoc, CDocument)

BEGIN_MESSAGE_MAP(CMIDAS_APP_SW_5_CLASSDGRDoc, CDocument)
END_MESSAGE_MAP()


// CMIDAS_APP_SW_5_CLASSDGRDoc ����/�Ҹ�

CMIDAS_APP_SW_5_CLASSDGRDoc::CMIDAS_APP_SW_5_CLASSDGRDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMIDAS_APP_SW_5_CLASSDGRDoc::~CMIDAS_APP_SW_5_CLASSDGRDoc()
{
}

BOOL CMIDAS_APP_SW_5_CLASSDGRDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	
	return TRUE;
}




// CMIDAS_APP_SW_5_CLASSDGRDoc serialization

void CMIDAS_APP_SW_5_CLASSDGRDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CMIDAS_APP_SW_5_CLASSDGRDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CMIDAS_APP_SW_5_CLASSDGRDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMIDAS_APP_SW_5_CLASSDGRDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMIDAS_APP_SW_5_CLASSDGRDoc ����

#ifdef _DEBUG
void CMIDAS_APP_SW_5_CLASSDGRDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMIDAS_APP_SW_5_CLASSDGRDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMIDAS_APP_SW_5_CLASSDGRDoc ����