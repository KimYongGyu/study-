#pragma once


// CFileNewDlg 대화 상자입니다.

class CFileNewDlg : public CDialog
{
	DECLARE_DYNAMIC(CFileNewDlg)

public:
	CFileNewDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFileNewDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FILE_NEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// 이미지 가로, 세로 크기
	int m_nWidth;
	int m_nHeight;

	// 이미지 색상 타입(그레이스케일 또는 트루칼라)
	int m_nType;
};
