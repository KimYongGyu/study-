
// button2.h : button2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cbutton2App:
// �� Ŭ������ ������ ���ؼ��� button2.cpp�� �����Ͻʽÿ�.
//

class Cbutton2App : public CWinApp
{
public:
	Cbutton2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cbutton2App theApp;
