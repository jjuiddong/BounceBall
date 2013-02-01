
#include "stdafx.h"
#include "Ball.h"


CBall::CBall(POINT pos, int radian) : 
	m_Radian(radian)
{
	m_Pos = Vector2((float)pos.x, (float)pos.y);
	m_Velocity = Vector2(0.2f, 0.2f);
}

void CBall::Move(const CRect &windowRect, int elapse_time)
{
	float x = m_Velocity.x * elapse_time;
	float y = m_Velocity.y * elapse_time;
	m_Pos.x += x;
	m_Pos.y += y;

	if (m_Velocity.x < 0 && m_Pos.x - m_Radian  < 0 )
		m_Velocity.x = -m_Velocity.x;

	if (m_Velocity.x > 0 && m_Pos.x + m_Radian  > windowRect.right)
		m_Velocity.x = -m_Velocity.x;	

	if (m_Velocity.y < 0 && m_Pos.y - m_Radian < 0 )
		m_Velocity.y = -m_Velocity.y;

	if (m_Velocity.y > 0 &&  m_Pos.y + m_Radian  > windowRect.bottom)
		m_Velocity.y = -m_Velocity.y;

}
