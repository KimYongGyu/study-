#pragma once
#include "afxwin.h"


// CArithmedicDlg ��ȭ �����Դϴ�.

class CArithmedicDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CArithmedicDlg)

public:
	CArithmedicDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CArithmedicDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ARITHMETIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboImage1;
	CComboBox m_comboImage2;
	int m_nFunction;
	void* m_pDoc1;
	void* m_pDoc2;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
