
// MIDAS_APP_SW_5_CLASSDGRView.h : CMIDAS_APP_SW_5_CLASSDGRView Ŭ������ �������̽�
//

#pragma once
#include "Brushs.h"
#include "Line.h"
#include "mRectangle.h"
class CMIDAS_APP_SW_5_CLASSDGRView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMIDAS_APP_SW_5_CLASSDGRView();
	DECLARE_DYNCREATE(CMIDAS_APP_SW_5_CLASSDGRView)

// Ư���Դϴ�.
public:
	CMIDAS_APP_SW_5_CLASSDGRDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMIDAS_APP_SW_5_CLASSDGRView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	//Brush
	Brushs* m_Brush;
	CPoint m_StartPos;
	CPoint m_EndPos;

	M_Polygon* m_SelectRect;
	bool m_StartToMove;
	bool m_SelectObject;

	M_Polygon* findrect(CPoint);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDrawRect();
	afx_msg void OnDrawLine();
	afx_msg void OnEraseAll();
	afx_msg void OnEraser();
	afx_msg void OnRedo();
	afx_msg void OnUndo();
	afx_msg void OnAddClass();
};

#ifndef _DEBUG  // MIDAS_APP_SW_5_CLASSDGRView.cpp�� ����� ����
inline CMIDAS_APP_SW_5_CLASSDGRDoc* CMIDAS_APP_SW_5_CLASSDGRView::GetDocument() const
   { return reinterpret_cast<CMIDAS_APP_SW_5_CLASSDGRDoc*>(m_pDocument); }
#endif
