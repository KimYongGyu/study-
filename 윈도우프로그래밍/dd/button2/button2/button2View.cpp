
// button2View.cpp : Cbutton2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "button2.h"
#endif

#include "button2Doc.h"
#include "button2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cbutton2View

IMPLEMENT_DYNCREATE(Cbutton2View, CFormView)

BEGIN_MESSAGE_MAP(Cbutton2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &Cbutton2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cbutton2View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cbutton2View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cbutton2View::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Cbutton2View::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Cbutton2View::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Cbutton2View::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Cbutton2View::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &Cbutton2View::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &Cbutton2View::OnBnClickedButton10)
END_MESSAGE_MAP()

// Cbutton2View 생성/소멸

Cbutton2View::Cbutton2View()
	: CFormView(Cbutton2View::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cbutton2View::~Cbutton2View()
{
}

void Cbutton2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_checkbox);
	DDX_Control(pDX, IDC_CHECK2, m_3state);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_EDIT3, m_edit2);
	DDX_Control(pDX, IDC_BUTTON2, m_cal1);
	DDX_Control(pDX, IDC_BUTTON3, m_cal2);
	DDX_Control(pDX, IDC_BUTTON4, m_cal3);
	DDX_Control(pDX, IDC_BUTTON5, m_cal4);
	DDX_Control(pDX, IDC_BUTTON6, m_cal5);
	DDX_Control(pDX, IDC_BUTTON7, m_cal6);
	DDX_Control(pDX, IDC_BUTTON8, m_cal7);
	DDX_Control(pDX, IDC_BUTTON9, m_cal8);
	DDX_Control(pDX, IDC_BUTTON10, m_cal9);
}

BOOL Cbutton2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cbutton2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//      초기에 값을 어떻게 설정할것인가하는 함수
	m_checkbox.SetCheck(1);
	m_3state.SetCheck(1);
	m_radio2.SetCheck(1);
	m_edit.SetLimitText(20);
	m_edit2.SetLimitText(20);
}


// Cbutton2View 진단

#ifdef _DEBUG
void Cbutton2View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cbutton2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cbutton2Doc* Cbutton2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cbutton2Doc)));
	return (Cbutton2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cbutton2View 메시지 처리기

// 해당 버튼을 더블클릭하면 해당함수가 자동으로 생성함!!!
void Cbutton2View::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int state_checkbox = m_checkbox.GetCheck();
	int state_3state = m_3state.GetCheck();
	int state_radio1 = m_radio1.GetCheck();
	int state_radio2 = m_radio2.GetCheck();

	CString str;
	str.Format(_T(" 버튼 상태 : %d,%d,%d,%d"),
		state_checkbox,state_3state,state_radio1,state_radio2);
//	MessageBox(str,_T("Button2 예제"), MB_ICONINFORMATION);
	m_edit.SetWindowTextW(str);

}


void Cbutton2View::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T(" 1"));
	m_edit2.SetWindowTextW(str);
}


void Cbutton2View::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T(" 2"));
	m_edit2.SetWindowTextW(str);
}


void Cbutton2View::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T(" 3"));
	m_edit2.SetWindowTextW(str);
}


void Cbutton2View::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T(" 4"));
	m_edit2.SetWindowTextW(str);
}


void Cbutton2View::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T(" 5"));
	m_edit2.SetWindowTextW(str);
}


void Cbutton2View::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T(" 6"));
	m_edit2.SetWindowTextW(str);
}


void Cbutton2View::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T(" 7"));
	m_edit2.SetWindowTextW(str);
}


void Cbutton2View::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T(" 8"));
	m_edit2.SetWindowTextW(str);
}


void Cbutton2View::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T(" 9"));
	m_edit2.SetWindowTextW(str);
}
