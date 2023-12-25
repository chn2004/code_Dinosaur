
// dinoView.h : interface of the CdinoView class
//

#pragma once

#include "Game.h"

class CdinoView : public CView
{
protected: // create from serialization only
	CdinoView() noexcept;
	DECLARE_DYNCREATE(CdinoView)

// Attributes
public:
	CdinoDoc* GetDocument() const;

// Operations
public:
	Game game;
	int kd;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CdinoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	int batdaugame();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in dinoView.cpp
inline CdinoDoc* CdinoView::GetDocument() const
   { return reinterpret_cast<CdinoDoc*>(m_pDocument); }
#endif

