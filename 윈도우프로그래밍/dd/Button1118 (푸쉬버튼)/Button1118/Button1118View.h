
// Button1118View.h : CButton1118View 클래스의 인터페이스
//

#pragma once


class CButton1118View : public CView
{
protected: // serialization에서만 만들어집니다.
	CButton1118View();
	DECLARE_DYNCREATE(CButton1118View)

// 특성입니다.
public:
	CButton1118Doc* GetDocument() const;
	CButton m_pushbutton;
	CButton m_checkbox;
	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;
	CButton m_groupbox;

	CButton m_b1;
	CButton m_b2;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CButton1118View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void OnButtonClicked(void);
};

#ifndef _DEBUG  // Button1118View.cpp의 디버그 버전
inline CButton1118Doc* CButton1118View::GetDocument() const
   { return reinterpret_cast<CButton1118Doc*>(m_pDocument); }
#endif

