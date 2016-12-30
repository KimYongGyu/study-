#pragma once


// CGaussianDlg 대화 상자입니다.

class CGaussianDlg : public CDialog
{
	DECLARE_DYNAMIC(CGaussianDlg)

public:
	CGaussianDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CGaussianDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_GAUSSIAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CSliderCtrl m_sliderSigma;
	float m_fSigma;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeSigmaEdit();
};
