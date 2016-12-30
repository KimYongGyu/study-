
// Button1118View.h : CButton1118View Ŭ������ �������̽�
//

#pragma once


class CButton1118View : public CView
{
protected: // serialization������ ��������ϴ�.
	CButton1118View();
	DECLARE_DYNCREATE(CButton1118View)

// Ư���Դϴ�.
public:
	CButton1118Doc* GetDocument() const;
	CButton m_pushbutton;
	CButton m_checkbox;
	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;
	CButton m_groupbox;

	CButton m_b1;
	CButton m_b2;

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
	virtual ~CButton1118View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void OnButtonClicked(void);
};

#ifndef _DEBUG  // Button1118View.cpp�� ����� ����
inline CButton1118Doc* CButton1118View::GetDocument() const
   { return reinterpret_cast<CButton1118Doc*>(m_pDocument); }
#endif

