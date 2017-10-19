
// openglCallBackView.h : interface of the CopenglCallBackView class
//

#pragma once
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glext.h"
#include "wglext.h"

#include <memory>

class CopenglCallBackView : public CView
{
protected: // create from serialization only
	CopenglCallBackView();
	DECLARE_DYNCREATE(CopenglCallBackView)

// Attributes
public:
	CopenglCallBackDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CopenglCallBackView();
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
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnDestroy();
    afx_msg void OnSize(UINT nType, int cx, int cy);
public:
    CClientDC* m_pClientDC;
    CPoint m_pStartLocation;
    bool m_bLButtonDown;
    class mathImpl;
    std::shared_ptr< mathImpl > m_pMathImpl;
public:
    void GLsetting();
    bool PixelFormatSetting();

    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMove(int x, int y);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in openglCallBackView.cpp
inline CopenglCallBackDoc* CopenglCallBackView::GetDocument() const
   { return reinterpret_cast<CopenglCallBackDoc*>(m_pDocument); }
#endif

