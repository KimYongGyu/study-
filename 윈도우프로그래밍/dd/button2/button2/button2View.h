
// button2View.h : Cbutton2View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class Cbutton2View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	Cbutton2View();
	DECLARE_DYNCREATE(Cbutton2View)

public:
	enum{ IDD = IDD_BUTTON2_FORM };

// Ư���Դϴ�.
public:
	Cbutton2Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~Cbutton2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CButton m_checkbox;
	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;
	afx_msg void OnBnClickedButton1();
	CEdit m_edit;
	CEdit m_edit2;
	CButton m_cal1;
	CButton m_cal2;
	CButton m_cal3;
	CButton m_cal4;
	CButton m_cal5;
	CButton m_cal6;
	CButton m_cal7;
	CButton m_cal8;
	CButton m_cal9;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
};

#ifndef _DEBUG  // button2View.cpp�� ����� ����
inline Cbutton2Doc* Cbutton2View::GetDocument() const
   { return reinterpret_cast<Cbutton2Doc*>(m_pDocument); }
#endif

