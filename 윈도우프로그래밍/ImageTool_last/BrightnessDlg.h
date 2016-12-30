#pragma once
#include "afxcmn.h"


// CBrightnessDlg 대화 상자입니다.

class CBrightnessDlg : public CDialog
{
	DECLARE_DYNAMIC(CBrightnessDlg)

public:
	CBrightnessDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CBrightnessDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_BRIGHTNESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	
	int         m_nBrightness;  // 밝기 변화량
	CSliderCtrl m_sliderBrightness;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeBrightnessEdit();
};
