
// ChildView.cpp : CChildView Ŭ������ ����
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



// CChildView �޽��� ó����

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
	font.CreatePointFont(150, _T("�ü�"));
	dc.SelectObject(&font);
	dc.SetTextColor(m_color);  // �۾� ����
	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT);
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
	if(nChar ==_T('\b')) {    // ������ ��� ó��
		if(m_str.GetSize() >0)
			m_str.RemoveAt(m_str.GetSize()-1);
	}
	else { m_str.Add(nChar);}
	Invalidate();
	CWnd::OnChar(nChar, nRepCnt, nFlags);
}
