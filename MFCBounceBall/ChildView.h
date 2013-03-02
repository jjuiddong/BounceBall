#pragma once

class CBall;
class CChildView : public CWnd
{
public:
	CChildView();
	virtual ~CChildView();
public:
	enum { MAX_BALL_COUNT=50, DEFAULT_RADIUS=10 };
	std::vector<CBall*> m_Balls;
	CBrush m_Brush[ 5];
public:
	void	MainLoop(int elapse_time);
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

