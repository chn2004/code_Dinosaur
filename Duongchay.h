#pragma once
#include "Hcn.h"
#include "Robot.h"
#define XDAU 0
#define YDAU 100
class Duongchay
{
public:
	Hcn duongvien;
	Hcn vatcan[5];
	Duongchay();
	void vehinh(CClientDC* pdc);
	void chay();
	int chamrobot(Robot rb);
};

