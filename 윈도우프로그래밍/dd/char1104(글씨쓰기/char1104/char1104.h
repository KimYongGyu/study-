
// char1104.h : char1104 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cchar1104App:
// �� Ŭ������ ������ ���ؼ��� char1104.cpp�� �����Ͻʽÿ�.
//

class Cchar1104App : public CWinApp
{
public:
	Cchar1104App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cchar1104App theApp;
