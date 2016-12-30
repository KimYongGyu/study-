#pragma once


// CHistogramDlg 대화 상자입니다.


class CHistogramDlg : public CDialog
{
	DECLARE_DYNAMIC(CHistogramDlg)

public:
	CHistogramDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CHistogramDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_HISTOGRAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	int m_Histogram[256];

public:
	void SetImage(CDib& dib);

	afx_msg void OnPaint();
};
