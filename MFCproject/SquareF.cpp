#include "stdafx.h"
#include "SquareF.h"

//!! 22 b
IMPLEMENT_SERIAL(SquareF, CObject, 1)
//!! 22 e

SquareF::SquareF(CPoint P1, CPoint P2) :RectangleF(P1, P2) {

}

void SquareF::Draw(CDC* dc) const {
	double length = abs(P1.x -P2.x)>abs(P1.y-P2.y)? abs(P1.x - P2.x): abs(P1.y - P2.y);
	CPen pen1, *oldPen;
	pen1.CreatePen(PS_SOLID, GetPenSize(), GetPenColor());
	oldPen = dc->SelectObject(&pen1);
	CBrush myBrush, *oldBrush;
	myBrush.CreateSolidBrush(GetBgColor());
	oldBrush = dc->SelectObject(&myBrush);
	dc->Rectangle(P1.x, P1.y, length + P1.x, length + P1.y);
}