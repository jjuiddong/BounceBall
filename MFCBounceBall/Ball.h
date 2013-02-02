//------------------------------------------------------------------------
// Name:    Ball.h
// Author:  jjuiddong
// Date:    2/1/2013
// 
// 
//------------------------------------------------------------------------
#ifndef __BALL_H__
#define __BALL_H__

struct Vector2
{
	float x, y;
	Vector2() {}
	Vector2(float _x, float _y) : x(_x), y(_y) {}
};

DECLARE_TYPE_NAME(CBall)
class CBall : public sharedmemory::CSharedMem<CBall, TYPE_NAME(CBall)>
{
public:
	CBall() {}
	CBall(POINT pos, int radian);
	virtual ~CBall() {}

	enum Color
	{
		YELLOW,
		GREEN,
		BLUE,
		RED
	};

protected:
	Vector2 m_Pos;
	Vector2 m_Velocity;
	int m_Radius;
	Color m_Color;

public:
	void Move(const CRect &windowRect, int elapse_time );
	Color GetColor() { return m_Color; }
	CRect GetRect() 
	{ 
		return CRect((int)m_Pos.x-m_Radius, (int)m_Pos.y-m_Radius, 
			(int)m_Pos.x+m_Radius, (int)m_Pos.y+m_Radius);
	};

};

#endif // __BALL_H__
