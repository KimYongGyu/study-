
// Button1118.h : Button1118 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CButton1118App:
// �� Ŭ������ ������ ���ؼ��� Button1118.cpp�� �����Ͻʽÿ�.
//

class CButton1118App : public CWinApp
{
public:
	CButton1118App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CButton1118App theApp;
