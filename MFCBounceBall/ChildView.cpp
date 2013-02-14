
#include "stdafx.h"
#include "MFCBounceBall.h"
#include "ChildView.h"
#include "Ball.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView
CChildView::CChildView() :
	m_Balls(MAX_BALL_COUNT)
{
	m_Brush[ 0].CreateSolidBrush( RGB(255,255,0) );
	m_Brush[ 1].CreateSolidBrush( RGB(0,255,0) );
	m_Brush[ 2].CreateSolidBrush( RGB(0,0,255) );
	m_Brush[ 3].CreateSolidBrush( RGB(255,0,0) );
	m_Brush[ 4].CreateSolidBrush( RGB(255,255,255) );
}

CChildView::~CChildView()
{
	sharedmemory::Release();
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
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

	sharedmemory::Init( "BounceBall", sharedmemory::SHARED_SERVER, 10240 );

	for (int i=0; i < MAX_BALL_COUNT; ++i)
		m_Balls[ i] = new CBall( CPoint((i+1)*30, (i+1)*30), DEFAULT_RADIUS );

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this);

	CRect cr;
	GetClientRect(cr);

	CDC memDC;
	CBitmap myBitmap;
	CBitmap *pOldBitmap;

	memDC.CreateCompatibleDC( &dc );
	myBitmap.CreateCompatibleBitmap( &dc, cr.Width(), cr.Height() );
	pOldBitmap = memDC.SelectObject( &myBitmap );
	memDC.PatBlt(0,0, cr.Width(), cr.Height(), WHITENESS );

	for (int i=0; i < MAX_BALL_COUNT; ++i)
	{
		memDC.SelectObject( &m_Brush[ m_Balls[ i]->GetColor()] );
		memDC.Ellipse(  m_Balls[ i]->GetRect() );		
	}

	dc.BitBlt(0, 0, cr.Width(), cr.Height(), &memDC, 0, 0, SRCCOPY);

	dc.SelectObject( pOldBitmap );
	myBitmap.DeleteObject();
	ReleaseDC( &memDC );
	DeleteDC( memDC );
}

void	CChildView::MainLoop(int elapse_time)
{
	CRect cr;
	GetClientRect(cr);
	for (int i=0; i < MAX_BALL_COUNT; ++i)
		m_Balls[ i]->Move( cr, m_Balls, elapse_time );
	InvalidateRect(NULL);
}

BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}
