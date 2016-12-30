
// changeCursorView.cpp : CchangeCursorView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "changeCursor.h"
#endif

#include "changeCursorDoc.h"
#include "changeCursorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CchangeCursorView

IMPLEMENT_DYNCREATE(CchangeCursorView, CView)

BEGIN_MESSAGE_MAP(CchangeCursorView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CchangeCursorView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SETCURSOR()
	ON_COMMAND(ID_32771, &CchangeCursorView::On32771)
	ON_COMMAND(ID_32772, &CchangeCursorView::On32772)
	ON_COMMAND(ID_32773, &CchangeCursorView::On32773)
END_MESSAGE_MAP()

// CchangeCursorView 생성/소멸

CchangeCursorView::CchangeCursorView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	a = 0;
}

CchangeCursorView::~CchangeCursorView()
{
}

BOOL CchangeCursorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CchangeCursorView 그리기

void CchangeCursorView::OnDraw(CDC* /*pDC*/)
{
	CchangeCursorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CchangeCursorView 인쇄


void CchangeCursorView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CchangeCursorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CchangeCursorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CchangeCursorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CchangeCursorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CchangeCursorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CchangeCursorView 진단

#ifdef _DEBUG
void CchangeCursorView::AssertValid() const
{
	CView::AssertValid();
}

void CchangeCursorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CchangeCursorDoc* CchangeCursorView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CchangeCursorDoc)));
	return (CchangeCursorDoc*)m_pDocument;
}
#endif //_DEBUG


// CchangeCursorView 메시지 처리기


BOOL CchangeCursorView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	
	if(nHitTest == HTCLIENT){
		CPoint point;
		::GetCursorPos(&point);
		ScreenToClient(&point);
		CRgn rgn;
		rgn.CreateRectRgn(0,0,400,100);
		if(a==1){
		if(rgn.PtInRegion(point))
			::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		else
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		}
		if(a==2){
		if(rgn.PtInRegion(point))
			::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR2));
		else
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		}
		if(a==3){
		if(rgn.PtInRegion(point))
			::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR3));
		else
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		}
		return true;
			}
	
	return CView::OnSetCursor(pWnd, nHitTest, message);
}


void CchangeCursorView::On32771()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	a=1;
}


void CchangeCursorView::On32772()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	a=2;
}


void CchangeCursorView::On32773()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	a=3;
}
