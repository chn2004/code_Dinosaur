#pragma once
#include "Hcn.h"
class Robot
{
public:
	Hcn dau, than, chanTruoc , chanSau, mat ;
	Robot();
	Robot(int mx, int my);
	void vehinh(CClientDC* pdc);
	void nhaylen();
};

