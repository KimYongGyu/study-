
// RButton1104.h : RButton1104 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CRButton1104App:
// �� Ŭ������ ������ ���ؼ��� RButton1104.cpp�� �����Ͻʽÿ�.
//

class CRButton1104App : public CWinApp
{
public:
	CRButton1104App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRButton1104App theApp;
