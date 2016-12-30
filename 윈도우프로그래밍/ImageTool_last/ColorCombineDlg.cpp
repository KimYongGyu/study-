// ColorCombineDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "ColorCombineDlg.h"
#include "afxdialogex.h"

#include "ImageToolDoc.h"


// CColorCombineDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CColorCombineDlg, CDialogEx)

CColorCombineDlg::CColorCombineDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CColorCombineDlg::IDD, pParent)
	, m_strColorSpace(_T(""))
	,m_pDoc1(NULL)
	,m_pDoc2(NULL)
	,m_pDoc3(NULL)
{}
CColorCombineDlg::~CColorCombineDlg(){}

void CColorCombineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COLOR_SPACE, m_strColorSpace);
	DDX_Control(pDX, IDC_COMBO_IMAGE1, m_comboimage1);
	DDX_Control(pDX, IDC_COMBO_IMAGE2, m_comboimage2);
	DDX_Control(pDX, IDC_COMBO_IMAGE3, m_comboimage3);
}


BEGIN_MESSAGE_MAP(CColorCombineDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CColorCombineDlg::OnBnClickedOk)
END_MESSAGE_MAP()

// CColorCombineDlg 메시지 처리기입니다.


BOOL CColorCombineDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	int nIndex = 0;
	CString strTitle;
	CImageToolApp* pApp = (CImageToolApp*)AfxGetApp();
	CImageToolDoc* pDoc = NULL;
	POSITION pos = pApp->m_pImageDocTemplate->GetFirstDocPosition();

	while( pos != NULL){
		pDoc = (CImageToolDoc*)pApp->m_pImageDocTemplate->GetNextDoc(pos);
		if (pDoc->m_Dib.GetBitCount() != 8) continue;

		strTitle = pDoc->GetTitle();

		m_comboimage1.InsertString(nIndex, strTitle);
		m_comboimage2.InsertString(nIndex, strTitle);
		m_comboimage3.InsertString(nIndex, strTitle);

		m_comboimage1.SetItemDataPtr(nIndex, (void*)pDoc);
		m_comboimage2.SetItemDataPtr(nIndex, (void*)pDoc);
		m_comboimage3.SetItemDataPtr(nIndex, (void*)pDoc);

		nIndex++;
	}
	if(nIndex == 0){
		AfxMessageBox(_T("그레이스케일 영상이 없습니다."));
		SendMessage(WM_COMMAND, IDCANCEL, 0);
	}
	m_comboimage1.SetCurSel(0);
	m_comboimage2.SetCurSel(0);
	m_comboimage3.SetCurSel(0);
	if(nIndex > 1) m_comboimage2.SetCurSel(1);
	if(nIndex > 2) m_comboimage3.SetCurSel(2);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
void CColorCombineDlg::OnBnClickedOk(){
	m_pDoc1 = (CImageToolDoc*)m_comboimage1.GetItemDataPtr(m_comboimage1.GetCurSel());
	m_pDoc2 = (CImageToolDoc*)m_comboimage2.GetItemDataPtr(m_comboimage2.GetCurSel());
	m_pDoc3 = (CImageToolDoc*)m_comboimage3.GetItemDataPtr(m_comboimage3.GetCurSel());

	CDialogEx::OnOK();
}