#pragma once


// CContrastDlg 대화 상자입니다.

class CContrastDlg : public CDialog
{
	DECLARE_DYNAMIC(CContrastDlg)

public:
	CContrastDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CContrastDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CONTRAST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:

	int         m_nContrast;  // 컨트라스트 변화량
	CSliderCtrl m_sliderContrast;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeContrastEdit();
};
