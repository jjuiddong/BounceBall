// 이 MFC 샘플 소스 코드는 MFC Microsoft Office Fluent 사용자 인터페이스("Fluent UI")를 
// 사용하는 방법을 보여 주며, MFC C++ 라이브러리 소프트웨어에 포함된 
// Microsoft Foundation Classes Reference 및 관련 전자 문서에 대해 
// 추가적으로 제공되는 내용입니다.  
// Fluent UI를 복사, 사용 또는 배포하는 데 대한 사용 약관은 별도로 제공됩니다.  
// Fluent UI 라이선싱 프로그램에 대한 자세한 내용은 
// http://msdn.microsoft.com/officeui를 참조하십시오.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFCBounceBall.h"
#include "ChildView.h"
#include "Ball.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_Brush[ 0].CreateSolidBrush( RGB(255,255,0) );
	m_Brush[ 1].CreateSolidBrush( RGB(0,255,0) );
	m_Brush[ 2].CreateSolidBrush( RGB(0,0,255) );
	m_Brush[ 3].CreateSolidBrush( RGB(255,0,0) );


}

CChildView::~CChildView()
{
	sharedmemory::Release();
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	sharedmemory::Init( "BounceBall", sharedmemory::SHARED_SERVER, 1024 );

	for (int i=0; i < MAX_BALL_COUNT; ++i)
	{
		m_Balls[ i] = new CBall( CPoint((i+1)*30, (i+1)*30), 10 );
	}

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this);

	for (int i=0; i < MAX_BALL_COUNT; ++i)
	{
		dc.SelectObject( &m_Brush[ m_Balls[ i]->GetColor()] );
		dc.Ellipse(  m_Balls[ i]->GetRect() );		
	}

}

void	CChildView::MainLoop(int elapse_time)
{
	CRect cr;
	GetClientRect(cr);

	// move
	for (int i=0; i < MAX_BALL_COUNT; ++i)
	{
		m_Balls[ i]->Move( cr, elapse_time );
	}
	InvalidateRect(NULL);
}
