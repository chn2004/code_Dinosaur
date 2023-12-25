#include "pch.h"
#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

Game::Game()
{
	thietlap();
}

void Game::vehinh(CClientDC* pdc)
{
	
	nl.vehinh(pdc);
	dc.vehinh(pdc);
	rb.vehinh(pdc);
}

int Game::bamnut(CClientDC* pdc, CPoint p)
{
	if (nl.bamnutlenh(p) == 1 && nl.giatri == 0)
	{
		thietlap();
		nl.giatri = 1;
		nl.nd.Format(_T("Stop"));
		nl.vehinh(pdc);
		dk = 1;
		return 1;
	}
	else
	    if (nl.bamnutlenh(p) == 1 && nl.giatri == 1)
	    {
		   nl.giatri = 0;
		   nl.nd.Format(_T("Start"));
		   nl.vehinh(pdc);
		   dk = 0;
		   return 0;
	    }
}

void Game::vatcanchay(CClientDC* pdc)
{
	while (dk == 1)
	{
	
		dc.chay();
		Sleep(50);
	}
	
}

void Game::capnhathinh(CClientDC* pdc)
{
	while (dk == 1)
	{
		CString strdiem;
		strdiem.Format(_T("Diem:%d      "), diem);
		pdc->TextOutW(100, 20, strdiem);
		diem++;
		dc.vehinh(pdc);
		rb.vehinh(pdc);
		if (dc.chamrobot(rb) == 1)
		{
			PlaySound(TEXT("C:\\Users\\MSI-M\\Downloads\\1111"), NULL, SND_FILENAME);
			dk = 0;
			thang = -1;
			//bien nut thanh start
			nl.giatri = 0;
			nl.nd.Format(_T("Start"));
			nl.vehinh(pdc);
			CString strdung;
			strdung.Format(_T("GAME OVER! VUI LONG BAM START DE BAT DAU!"));
			pdc->TextOutW(700, 250, strdung);
		}
		Sleep(20);
	}
}

void Game::robotnhay()
{
	rb.nhaylen();

}

void Game::thietlap()
{
	CString str;
	str.Format(_T("Start"));
	nl = Nutlenh(30, 20, str);
	dc = Duongchay();
	rb = Robot(200, dc.duongvien.y2 - 30);
	dk = 0;
	thang = 0;
	diem = 0;
}
