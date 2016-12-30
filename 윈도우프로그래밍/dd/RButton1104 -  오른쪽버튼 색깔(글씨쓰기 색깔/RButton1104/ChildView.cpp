
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "RButton1104.h"
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
	ON_COMMAND(ID_TEST_1, &CChildView::OnTest1)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_TEST_2, &CChildView::OnTest2)
	ON_COMMAND(ID_TEST_3, &CChildView::OnTest3)
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
	dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT);// 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnTest1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_color = RGB(255, 0,0);
}


void CChildView::OnTest2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_color = RGB(0, 255,0);
}


void CChildView::OnTest3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_color = RGB(0, 0,255);
}

void CChildView::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CMenu menu;
	menu.LoadMenu(IDR_MAINFRAME);
	CMenu* pMenu = menu.GetSubMenu(3);  //mainframe의 메뉴가 왼쪽부터 0, 1, 2, 3 이므로
	pMenu -> TrackPopupMenu(
		TPM_LEFTALIGN | TPM_RIGHTBUTTON,   // TPM_LEFTALIGN or TPM_RIGHTBUTTON
		point.x, point.y, AfxGetMainWnd());
}

void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if(nChar ==_T('\b')) {    // 지웠을 경우 처리
		if(m_str.GetSize() >0)
			m_str.RemoveAt(m_str.GetSize()-1);
	}
	else { m_str.Add(nChar);}
	Invalidate();
	CWnd::OnChar(nChar, nRepCnt, nFlags);
}
