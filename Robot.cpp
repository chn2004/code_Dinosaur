#include "pch.h"
#include "Robot.h"

Robot::Robot()
{
	int mx = 0, my = 0;
	dau = Hcn(mx - 25, my - 20, mx + 10, my + 5);
	mat = Hcn(mx - 7, my - 10, mx, my);
	than = Hcn(dau.x1 - 5, dau.y2 - 2, dau.x2 - 2, dau.y1 + 40);
	chanTruoc = Hcn(than.x1 + 35, than.y2, than.x2 - 6, than.y2 + 10);
	chanSau = Hcn(than.x1 + 35, than.y2, than.x2 - 15, than.y2 + 10);
}

Robot::Robot(int mx, int my)
{
	dau = Hcn(mx - 25, my - 20, mx + 10, my + 5);
	mat = Hcn(mx - 7, my - 10, mx, my);
	than = Hcn(dau.x1 - 5, dau.y2 - 2, dau.x2 - 2, dau.y1 + 40);
	chanTruoc = Hcn(than.x1 + 35, than.y2, than.x2 - 6, than.y2 + 10);
	chanSau = Hcn(than.x1 + 35, than.y2, than.x2 - 15, than.y2 + 10);
}

void Robot::vehinh(CClientDC* pdc)
{
	pdc->SelectObject(GetStockObject(WHITE_BRUSH));
	dau.vehinh(pdc);
	pdc->SelectObject(GetStockObject(WHITE_BRUSH));
	mat.vehinh(pdc);
	pdc->SelectObject(GetStockObject(WHITE_BRUSH));
	than.vehinh(pdc);
	pdc->SelectObject(GetStockObject(WHITE_BRUSH));
	chanTruoc.vehinh(pdc);
	pdc->SelectObject(GetStockObject(WHITE_BRUSH));
	chanSau.vehinh(pdc);
}

void Robot::nhaylen()
{
	int i = 0;
	for (i = 0; i < 18; i++)
	{
		than.dichlen();
		mat.dichlen();
		dau.dichlen();
		chanTruoc.dichlen();
		chanSau.dichlen();

		Sleep(30);
	}
	for (i = 0; i < 18; i++)
	{
		than.dichxuong();
		mat.dichxuong();
		dau.dichxuong();
		chanTruoc.dichxuong();
		chanSau.dichxuong();

		Sleep(30);
	}
}