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
	void Draw(CDC* dc) const;
};

