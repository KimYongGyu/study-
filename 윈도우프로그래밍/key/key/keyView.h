
// keyView.h : CkeyView Ŭ������ �������̽�
//

#pragma once


class CkeyView : public CView
{
protected: // serialization������ ��������ϴ�.
	CkeyView();
	DECLARE_DYNCREATE(CkeyView)

// Ư���Դϴ�.
public:
	CkeyDoc* GetDocument() const;

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
	virtual ~CkeyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRec();
	afx_msg void OnCircle();
	afx_msg void OnLine();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	bool cMove;
	bool rMove;
	bool lMove;
	CPoint SP;
	CPoint EP;
	int num;
};

#ifndef _DEBUG  // keyView.cpp�� ����� ����
inline CkeyDoc* CkeyView::GetDocument() const
   { return reinterpret_cast<CkeyDoc*>(m_pDocument); }
#endif

