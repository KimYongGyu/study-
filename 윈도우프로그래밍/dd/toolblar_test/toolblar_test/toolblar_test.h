
// toolblar_test.h : toolblar_test ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Ctoolblar_testApp:
// �� Ŭ������ ������ ���ؼ��� toolblar_test.cpp�� �����Ͻʽÿ�.
//

class Ctoolblar_testApp : public CWinApp
{
public:
	Ctoolblar_testApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ctoolblar_testApp theApp;
