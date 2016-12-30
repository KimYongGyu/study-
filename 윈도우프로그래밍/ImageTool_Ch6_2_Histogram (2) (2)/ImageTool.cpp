// ImageTool.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "ImageToolDoc.h"
#include "ImageToolView.h"

#include "Dib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageToolApp

BEGIN_MESSAGE_MAP(CImageToolApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CImageToolApp::OnAppAbout)
	// 표준 파일을 기초로 하는 문서 명령입니다.
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// 표준 인쇄 설정 명령입니다.
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_EDIT_PASTE, &CImageToolApp::OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, &CImageToolApp::OnUpdateEditPaste)
END_MESSAGE_MAP()


// CImageToolApp 생성

CImageToolApp::CImageToolApp()
: m_pNewDib(NULL), pImageDocTemplate(NULL)
{
}

CImageToolApp::~CImageToolApp()
{
	if( m_pNewDib != NULL )
		delete m_pNewDib;
}


// 유일한 CImageToolApp 개체입니다.

CImageToolApp theApp;


// CImageToolApp 초기화

BOOL CImageToolApp::InitInstance()
{
	// 응용 프로그램 매니페스트가 ComCtl32.dll 버전 6 이상을 사용하여 비주얼 스타일을
	// 사용하도록 지정하는 경우, Windows XP 상에서 반드시 InitCommonControlsEx()가 필요합니다. 
	// InitCommonControlsEx()를 사용하지 않으면 창을 만들 수 없습니다.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 응용 프로그램에서 사용할 모든 공용 컨트롤 클래스를 포함하도록
	// 이 항목을 설정하십시오.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_ImageToolTYPE,
		RUNTIME_CLASS(CImageToolDoc),
		RUNTIME_CLASS(CChildFrame),
		RUNTIME_CLASS(CImageToolView));
	if(!pDocTemplate)
		return false;

	pImageDocTemplate = new CMultiDocTemplate(IDR_ImageToolTYPE,
		RUNTIME_CLASS(CImageToolDoc),
		RUNTIME_CLASS(CChildFrame),
		RUNTIME_CLASS(CImageToolView));
	if(!pImageDocTemplate)
		return false;

	AddDocTemplate(pDocTemplate);
	AddDocTemplate(pImageDocTemplate);
	CWinApp::InitInstance();

	// OLE 라이브러리를 초기화합니다.
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 응용 프로그램 마법사에서 생성된 응용 프로그램"));
	LoadStdProfileSettings(4);  // MRU를 포함하여 표준 INI 파일 옵션을 로드합니다.
	// 응용 프로그램의 문서 템플릿을 등록합니다. 문서 템플릿은
	//  문서, 프레임 창 및 뷰 사이의 연결 역할을 합니다.
/*	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_ImageToolTYPE,
		RUNTIME_CLASS(CImageToolDoc),
		RUNTIME_CLASS(CChildFrame), // 사용자 지정 MDI 자식 프레임입니다.
		RUNTIME_CLASS(CImageToolView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate); */ 

	// 주 MDI 프레임 창을 만듭니다.
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;

	// 접미사가 있을 경우에만 DragAcceptFiles를 호출합니다.
	//  MDI 응용 프로그램에서는 m_pMainWnd를 설정한 후 바로 이러한 호출이 발생해야 합니다.
	// 끌어서 놓기에 대한 열기를 활성화합니다.
	m_pMainWnd->DragAcceptFiles();

	// DDE Execute 열기를 활성화합니다.
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	// 표준 셸 명령, DDE, 파일 열기에 대한 명령줄을 구문 분석합니다.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// 프로그램 시작 시 빈 창을 띄우지 않는다.
	if ( cmdInfo.m_nShellCommand == CCommandLineInfo::FileNew )
		cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;

	// 명령줄에 지정된 명령을 디스패치합니다.
	// 응용 프로그램이 /RegServer, /Register, /Unregserver 또는 /Unregister로 시작된 경우 FALSE를 반환합니다.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 주 창이 초기화되었으므로 이를 표시하고 업데이트합니다.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}



// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// 대화 상자를 실행하기 위한 응용 프로그램 명령입니다.
void CImageToolApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CImageToolApp 메시지 처리기

void CImageToolApp::OnEditPaste()
{
	CDib dib;
	dib.PasteFromClipboard();

	AfxNewImage(dib);
}

void CImageToolApp::OnUpdateEditPaste(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(IsClipboardFormatAvailable(CF_DIB));
}

// 전역 함수 정의

void AfxNewImage(CDib& dib)
{
	theApp.m_pNewDib = &dib;
	AfxGetMainWnd()->SendMessage(WM_COMMAND, ID_FILE_NEW);
}

