
// keyView.cpp : CkeyView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
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

// CkeyView ����/�Ҹ�

CkeyView::CkeyView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CkeyView �׸���

void CkeyView::OnDraw(CDC* /*pDC*/)
{
	CkeyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CkeyView �μ�


void CkeyView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CkeyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CkeyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CkeyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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


// CkeyView ����

#ifdef _DEBUG
void CkeyView::AssertValid() const
{
	CView::AssertValid();
}

void CkeyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CkeyDoc* CkeyView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CkeyDoc)));
	return (CkeyDoc*)m_pDocument;
}
#endif //_DEBUG


// CkeyView �޽��� ó����


void CkeyView::OnRec()
{
	CClientDC dc(this);

	num = 1;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CkeyView::OnCircle()
{
	CClientDC dc(this);

	num = 2;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CkeyView::OnLine()
{
	CClientDC dc(this);

	num = 3;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CkeyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
