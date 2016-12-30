
// Button1118View.cpp : CButton1118View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Button1118.h"
#endif

#include "Button1118Doc.h"
#include "Button1118View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButton1118View

IMPLEMENT_DYNCREATE(CButton1118View, CView)

BEGIN_MESSAGE_MAP(CButton1118View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_BN_CLICKED(101, OnButtonClicked)
	ON_BN_CLICKED(107, OnButtonClicked)
	ON_BN_CLICKED(108, OnButtonClicked)
END_MESSAGE_MAP()

// CButton1118View ����/�Ҹ�

CButton1118View::CButton1118View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CButton1118View::~CButton1118View()
{
}

BOOL CButton1118View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CButton1118View �׸���

void CButton1118View::OnDraw(CDC* /*pDC*/)
{
	CButton1118Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CButton1118View �μ�

BOOL CButton1118View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CButton1118View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CButton1118View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CButton1118View ����

#ifdef _DEBUG
void CButton1118View::AssertValid() const
{
	CView::AssertValid();
}

void CButton1118View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CButton1118Doc* CButton1118View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CButton1118Doc)));
	return (CButton1118Doc*)m_pDocument;
}
#endif //_DEBUG


// CButton1118View �޽��� ó����


int CButton1118View::OnCreate(LPCREATESTRUCT lpCreateStruct) // �����ߴ� �������� ��¸��
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_pushbutton.Create(_T("Ǫ�� ��ư"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(20, 20, 160, 50), this, 101);
	m_checkbox.Create(_T("üũ �ڽ�"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, CRect(20, 60, 160, 90), this, 102);
	m_3state.Create(_T("3���� üũ �ڽ�"), WS_CHILD | WS_VISIBLE | BS_AUTO3STATE, CRect(20, 100, 160, 130), this, 103);
	m_radio1.Create(_T("���� ��ư1"), WS_CHILD | WS_VISIBLE | WS_GROUP |  BS_AUTORADIOBUTTON, CRect(20, 170, 160, 200), this, 104);
	m_radio2.Create(_T("���� ��ư2"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, CRect(20, 210, 160, 240), this, 105);
	m_groupbox.Create(_T("�׷� �ڽ�"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, CRect(10, 140, 170, 250), this, 106);
	m_b1.Create(_T("b1 ��ư"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(0, 0, 40, 20), this, 107);
	m_b2.Create(_T("b2 ��ư"),  WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(60, 0, 100, 20), this, 108);
	// ��ư ��Ʈ���� �ʱ�ȭ�Ѵ�.
	m_checkbox.SetCheck(1);
	m_3state.SetCheck(2);
	m_radio2.SetCheck(1);

	m_b1.SetCheck(1);
	m_b2.SetCheck(2);
	return 0;
}


void CButton1118View::OnButtonClicked(void)
{
	int state_checkbox = m_checkbox.GetCheck();
	int state_3state = m_3state.GetCheck();
	int state_radio1 = m_radio1.GetCheck();
	int state_radio2 = m_radio2.GetCheck();

	CString str;
	str.Format(_T("��ư ���� : %d, %d %d, %d"), state_checkbox, state_3state, state_radio1, state_radio2);
	MessageBox(str, _T("Button1 ����"), MB_ICONINFORMATION);
}
