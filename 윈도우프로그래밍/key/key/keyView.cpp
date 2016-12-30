
// keyView.cpp : CkeyView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "key.h"
#endif

#include "keyDoc.h"
#include "keyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CkeyView

IMPLEMENT_DYNCREATE(CkeyView, CView)

BEGIN_MESSAGE_MAP(CkeyView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CkeyView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(Rec, &CkeyView::OnRec)
	ON_COMMAND(Circle, &CkeyView::OnCircle)
	ON_COMMAND(Line, &CkeyView::OnLine)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CkeyView 생성/소멸

CkeyView::CkeyView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	rMove = false;
	cMove = false;
	lMove = false;

	num = 0;
}

CkeyView::~CkeyView()
{
}

BOOL CkeyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CkeyView 그리기

void CkeyView::OnDraw(CDC* /*pDC*/)
{
	CkeyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CkeyView 인쇄


void CkeyView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CkeyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CkeyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CkeyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CkeyView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CkeyView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CkeyView 진단

#ifdef _DEBUG
void CkeyView::AssertValid() const
{
	CView::AssertValid();
}

void CkeyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CkeyDoc* CkeyView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CkeyDoc)));
	return (CkeyDoc*)m_pDocument;
}
#endif //_DEBUG


// CkeyView 메시지 처리기


void CkeyView::OnRec()
{
	CClientDC dc(this);

	num = 1;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CkeyView::OnCircle()
{
	CClientDC dc(this);

	num = 2;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CkeyView::OnLine()
{
	CClientDC dc(this);

	num = 3;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CkeyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	if(num == 1) {
		rMove = true;
		cMove = false;
		lMove = false;
	}
	else if(num == 2) {
		cMove = true;
		rMove = false;
		lMove = false;
	}
	else if(num == 3) {
		lMove = true;
		cMove = false;
		rMove = false;
	}

	SP.x = EP.x = point.x;
	SP.y = EP.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CkeyView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	dc.SelectStockObject(NULL_BRUSH);
	dc.SetROP2(R2_COPYPEN);
	
	EP.x = point.x;
	EP.y = point.y;

	if(num == 1) {
		rMove = false;
	}
	if(num == 2) {
		cMove = false;
	}
	if(num == 3) {
		dc.MoveTo(SP.x, SP.y);
		dc.LineTo(EP.x, EP.y);
		lMove = false;
	}
	ClientToScreen(&point);
	CView::OnLButtonUp(nFlags, point);
}


void CkeyView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(rMove == true ){
   CClientDC dc(this);
   dc.SelectStockObject(NULL_BRUSH);
   dc.SetROP2(R2_NOT);
   
   dc.Rectangle(SP.x+1, SP.y+1, EP.x+1, EP.y+1);
   EP.x = point.x;
   EP.y = point.y;
   dc.Rectangle(SP.x+1, SP.y+1, EP.x+1, EP.y+1);
  }

  if(cMove == true ){
   CClientDC dc(this);
   dc.SelectStockObject(NULL_BRUSH);
   dc.SetROP2(R2_NOT);
   
   dc.Ellipse(SP.x+1, SP.y+1, EP.x+1, EP.y+1);
   EP.x = point.x;
   EP.y = point.y;
   dc.Ellipse(SP.x+1, SP.y+1, EP.x+1, EP.y+1);
  }
  if(lMove == true) {
	  CClientDC dc(this);
	  dc.SelectStockObject(NULL_BRUSH);
	  dc.SetROP2(R2_NOT);
	  dc.MoveTo(SP.x, SP.y);
	  dc.LineTo(EP.x, EP.y);
	}
	CView::OnMouseMove(nFlags, point);
}
