
#include "stdafx.h"
#include "Ball.h"


float rand_rng() // 0.00 ~ 1.00f
{
	return (rand() % 100)/100.f;
}

CBall::CBall(POINT pos, int radian) : 
	m_Radius(radian)
{
	m_Pos = Vector2((float)pos.x, (float)pos.y);
	m_Velocity = Vector2(
		(rand_rng() *0.2f - 0.2f),
		(rand_rng() *0.2f - 0.2f) );
}

void CBall::Move(const CRect &windowRect, int elapse_time)
{
	float x = m_Velocity.x * elapse_time;
	float y = m_Velocity.y * elapse_time;
	m_Pos.x += x;
	m_Pos.y += y;

	if (m_Velocity.x < 0 && m_Pos.x - m_Radius  < 0 )
		m_Velocity.x = -m_Velocity.x;

	if (m_Velocity.x > 0 && m_Pos.x + m_Radius  > windowRect.right)
		m_Velocity.x = -m_Velocity.x;	

	if (m_Velocity.y < 0 && m_Pos.y - m_Radius < 0 )
		m_Velocity.y = -m_Velocity.y;

	if (m_Velocity.y > 0 &&  m_Pos.y + m_Radius  > windowRect.bottom)
		m_Velocity.y = -m_Velocity.y;

}
