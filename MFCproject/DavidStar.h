#pragma once
//!! 15 b
#include "Figure.h"
class DavidStar :public Figure {
	//!! 21 b
	DECLARE_SERIAL(DavidStar)   //!!! NO ";"  
	//!! 21 e
public:
	//!! 22 b
	// must 4 serialization
	DavidStar() {}
	//!! 22 b
	DavidStar(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
};
//!! 15 e