//!! 15 b
#include "stdafx.h"
#include "EllipseF.h"

//!! 22 b
IMPLEMENT_SERIAL(EllipseF, CObject, 1)
//!! 22 e

EllipseF::EllipseF(CPoint p1, CPoint p2)
	:Figure(p1, p2)
{
}
void EllipseF::Draw(CDC* dc) const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPen pen1, *oldPen;
	pen1.CreatePen(PS_SOLID, GetPenSize(), GetPenColor());
	oldPen = dc->SelectObject(&pen1);
	CBrush myBrush, *oldBrush;
	myBrush.CreateSolidBrush(GetBgColor());
	oldBrush = dc->SelectObject(&myBrush);
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
	dc->SelectObject(oldBrush);
	dc->SelectObject(oldPen);
	DeleteObject(pen1);
	DeleteObject(myBrush);
}
//!! 15 e
