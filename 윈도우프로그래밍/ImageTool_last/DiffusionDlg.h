#pragma once


// CDiffusionDlg 대화 상자입니다.

class CDiffusionDlg : public CDialog
{
	DECLARE_DYNAMIC(CDiffusionDlg)

public:
	CDiffusionDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDiffusionDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIFFUSION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	float m_fLambda;
	float m_fK;
	int m_nIteration;
};
