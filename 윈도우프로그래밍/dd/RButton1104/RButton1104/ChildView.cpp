
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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnTest1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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


void CChildView::OnTest2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnTest3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
