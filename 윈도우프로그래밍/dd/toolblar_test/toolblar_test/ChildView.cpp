
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "toolblar_test.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	test = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CONTEXTMENU()
	ON_WM_CHAR()
	ON_COMMAND(ID_RED, &CChildView::OnRed)
	ON_COMMAND(ID_GREEN, &CChildView::OnGreen)
	ON_COMMAND(ID_BLUE, &CChildView::OnBlue)
	ON_COMMAND(ID_a, &CChildView::Ona)
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
}



void CChildView::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	CMenu menu;
	menu.LoadMenu(IDR_MAINFRAME);
	CMenu* pMenu = menu.GetSubMenu(4);  //mainframe의 메뉴가 왼쪽부터 0, 1, 2, 3 이므로
	pMenu -> TrackPopupMenu(
		TPM_LEFTALIGN | TPM_RIGHTBUTTON,   // TPM_LEFTALIGN or TPM_RIGHTBUTTON
		point.x, point.y, AfxGetMainWnd());
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


void CChildView::OnRed()
{
		m_color = RGB(255, 0,0);
		Invalidate();
	
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnGreen()
{
		m_color = RGB(0, 255,0);
		Invalidate();
	
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnBlue()
{
	m_color = RGB(0, 0,255);
	Invalidate();
	
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::Ona()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_color = RGB(200, 50,50);
	Invalidate();
}
