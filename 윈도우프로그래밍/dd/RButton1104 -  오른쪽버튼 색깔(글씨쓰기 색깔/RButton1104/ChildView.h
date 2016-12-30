
// ChildView.h : CChildView 클래스의 인터페이스
//

#include <afxtempl.h>
#pragma once


// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();
	CArray<TCHAR, TCHAR>m_str; // 메모장의 배열
	COLORREF m_color; // 글씨 색

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTest1();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnTest2();
	afx_msg void OnTest3();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

