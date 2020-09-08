//!! 15 b
#include "stdafx.h"
#include "DavidStar.h"
#include "EllipseF.h"

//!! 22 b
IMPLEMENT_SERIAL(DavidStar, CObject, 1)
//!! 22 e

DavidStar::DavidStar(CPoint p1, CPoint p2)
	:Figure(p1, p2)
{
}
void DavidStar::Draw(CDC* dc) const
{
	CPoint center = P1 + P2;
	CPen pen1, *oldPen;
	pen1.CreatePen(PS_SOLID, GetPenSize(), GetPenColor());
	oldPen = dc->SelectObject(&pen1);
	CBrush myBrush, *oldBrush;
	myBrush.CreateSolidBrush(GetBgColor());
	oldBrush = dc->SelectObject(&myBrush);
	center.x /= 2.0; center.y /= 2.0;
	double radius = abs(P1.x - P2.x) < abs(P1.y - P2.y) ? abs(P1.x - P2.x) / 2.0 : abs(P1.y - P2.y) / 2.0;
	CPoint vertices[12];
	double two_pi = atan(1) * 8;
	for (int i = 0; i < 12; i++)
	{
		if (i % 2 == 0)
		{
			vertices[i].x = center.x + radius / sqrt(3) * cos(two_pi / 12 * i);
			vertices[i].y = center.y + radius / sqrt(3) * sin(two_pi / 12 * i);
		}
		else
		{
			vertices[i].x = center.x + radius * cos(two_pi / 12 * i);
			vertices[i].y = center.y + radius * sin(two_pi / 12 * i);
		}
	}
	dc->Polygon(vertices, 12);
	dc->SelectObject(oldBrush);
	dc->SelectObject(oldPen);
	DeleteObject(pen1);
	DeleteObject(myBrush);
}
//!! 15 e
