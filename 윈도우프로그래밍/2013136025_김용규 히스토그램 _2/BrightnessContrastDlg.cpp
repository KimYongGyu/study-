// BrightnessContrastDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "BrightnessContrastDlg.h"
#include "afxdialogex.h"


// CBrightnessContrastDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CBrightnessContrastDlg, CDialogEx)

CBrightnessContrastDlg::CBrightnessContrastDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBrightnessContrastDlg::IDD, pParent)
	, m_nBrightness(0)
	, m_nContrast(0)
{

}

CBrightnessContrastDlg::~CBrightnessContrastDlg()
{
}

void CBrightnessContrastDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BRIGHTNESS_SLIDER, m_sliderBrightness);
	DDX_Text(pDX, IDC_BRIGHTNESS_EDIT, m_nBrightness);
	DDV_MinMaxInt(pDX, m_nBrightness, -255, 255);
	DDX_Control(pDX, IDC_CONTRAST_SLIDER, m_sliderContrast);
	DDX_Text(pDX, IDC_CONTRAST_EDIT, m_nContrast);
	DDV_MinMaxInt(pDX, m_nContrast, -100, 100);
}


BEGIN_MESSAGE_MAP(CBrightnessContrastDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_BRIGHTNESS_EDIT, &CBrightnessContrastDlg::OnEnChangeBrightnessEdit)
	ON_EN_CHANGE(IDC_CONTRAST_EDIT, &CBrightnessContrastDlg::OnEnChangeContrastEdit)
END_MESSAGE_MAP()


// CBrightnessContrastDlg �޽��� ó�����Դϴ�.


BOOL CBrightnessContrastDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_sliderBrightness.SetRange(-255,255);
	m_sliderBrightness.SetTicFreq(32);
	m_sliderBrightness.SetPageSize(32);

	m_sliderContrast.SetRange(-100,100);
	m_sliderContrast.SetTicFreq(20);
	m_sliderContrast.SetPageSize(20);
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CBrightnessContrastDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if(m_sliderBrightness.GetSafeHwnd() == pScrollBar->GetSafeHwnd())  // ��ũ���� ��ġ�� �˾Ƴ��� m_nBrightness�� �����մϴ�.
	{
		m_nBrightness = m_sliderBrightness.GetPos();
		UpdateData(FALSE);
	}
	else if (m_sliderContrast.GetSafeHwnd() == pScrollBar ->GetSafeHwnd())// ��ũ���� ��ġ�� �˾Ƴ��� m_nContrast�� �����մϴ�.
	{
		m_nContrast = m_sliderContrast.GetPos();
		UpdateData(FALSE);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CBrightnessContrastDlg::OnEnChangeBrightnessEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.
	UpdateData(TRUE);
	m_sliderBrightness.SetPos(m_nBrightness);
	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CBrightnessContrastDlg::OnEnChangeContrastEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.
	UpdateData(TRUE);
	m_sliderContrast.SetPos(m_nContrast);
	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}