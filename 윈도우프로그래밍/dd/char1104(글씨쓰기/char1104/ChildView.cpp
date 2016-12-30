
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "char1104.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_color = RGB(255, 0,0);
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this);
	
	
	CFont font;
	font.CreatePointFont(150, _T("궁서"));
	dc.SelectObject(&font);
	dc.SetTextColor(m_color);  // 글씨 색깔
	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT);
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
	if(nChar ==_T('\b')) {    // 지웠을 경우 처리
		if(m_str.GetSize() >0)
			m_str.RemoveAt(m_str.GetSize()-1);
	}
	else { m_str.Add(nChar);}
	Invalidate();
	CWnd::OnChar(nChar, nRepCnt, nFlags);
}
