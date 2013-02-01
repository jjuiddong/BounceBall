// �� MFC ���� �ҽ� �ڵ�� MFC Microsoft Office Fluent ����� �������̽�("Fluent UI")�� 
// ����ϴ� ����� ���� �ָ�, MFC C++ ���̺귯�� ����Ʈ��� ���Ե� 
// Microsoft Foundation Classes Reference �� ���� ���� ������ ���� 
// �߰������� �����Ǵ� �����Դϴ�.  
// Fluent UI�� ����, ��� �Ǵ� �����ϴ� �� ���� ��� ����� ������ �����˴ϴ�.  
// Fluent UI ���̼��� ���α׷��� ���� �ڼ��� ������ 
// http://msdn.microsoft.com/officeui�� �����Ͻʽÿ�.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// ChildView.cpp : CChildView Ŭ������ ����
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



// CChildView �޽��� ó����

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
