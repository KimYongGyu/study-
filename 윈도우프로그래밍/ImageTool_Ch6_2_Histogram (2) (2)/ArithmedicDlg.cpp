// ArithmedicDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "ArithmedicDlg.h"
#include "afxdialogex.h"
#include "ImageToolDoc.h"


// CArithmedicDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CArithmedicDlg, CDialogEx)

CArithmedicDlg::CArithmedicDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CArithmedicDlg::IDD, pParent)
	, m_nFunction(0), m_pDoc1(NULL), m_pDoc2(NULL)
{

}

CArithmedicDlg::~CArithmedicDlg()
{
}

void CArithmedicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_IMAGE_1, m_comboImage1);
	DDX_Control(pDX, IDC_COMBO_IMAGE_2, m_comboImage2);
	DDX_Radio(pDX, IDC_FUNCTION_1, m_nFunction);
}


BEGIN_MESSAGE_MAP(CArithmedicDlg, CDialogEx)
END_MESSAGE_MAP()


// CArithmedicDlg �޽��� ó�����Դϴ�.


BOOL CArithmedicDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	int nIndex = 0;
	CString strTitle;

	CImageToolApp* pApp = (CImageToolApp*)AfxGetApp();
	POSITION pos = pApp->pImageDocTemplate->GetFirstDocPosition();

	while(pos != NULL)
	{
		CImageToolDoc* pDoc = (CImageToolDoc*)pApp->pImageDocTemplate->GetNextDoc(pos);
		if(pDoc->m_Dib.GetBitCount() != 8)
			continue;

		strTitle = pDoc->GetTitle();

		m_comboImage1.InsertString(nIndex, strTitle);
		m_comboImage2.InsertString(nIndex, strTitle);

		m_comboImage1.SetItemDataPtr(nIndex, (void*)pDoc);
		m_comboImage2.SetItemDataPtr(nIndex, (void*)pDoc);

		nIndex++;
	}

	m_comboImage1.SetCurSel(0);
	m_comboImage2.SetCurSel(0);
	if(nIndex > 1) m_comboImage2.SetCurSel(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CArithmedicDlg::OnBnClickedOk() {
	m_pDoc1 = (CImageToolDoc*)m_comboImage1.GetItemDataPtr(m_comboImage1.GetCurSel());
	m_pDoc2 = (CImageToolDoc*)m_comboImage2.GetItemDataPtr(m_comboImage1.GetCurSel());

	CDialogEx::OnOK();
}
