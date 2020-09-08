#pragma once
#include "RectangleF.h"
class SquareF : public RectangleF
{
	//!! 21 b
	DECLARE_SERIAL(SquareF)   //!!! NO ";"  
	//!! 21 e
public:
	//!! 22 b
	// must 4 serialization
	SquareF() {}
	//!! 22 b
	double GetLength() {
		return abs(P1.x - P2.x) > abs(P1.y - P2.y) ? abs(P1.x - P2.x) : abs(P1.y - P2.y);
	}
	SquareF(CPoint p1, CPoint p2);
	
	void Redefine(CPoint p1, CPoint p2)
	{
		P1 = p1;
		double length = abs(p1.x - p2.x) < abs(p1.y - p2.y) ? abs(p1.x - p2.x) : abs(p1.y - p2.y);
		P2.x = p1.x + length;
		P2.y = p1.y + length;
	}
};

