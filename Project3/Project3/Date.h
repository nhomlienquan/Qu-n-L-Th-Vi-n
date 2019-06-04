#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>
#include <fstream>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <Windows.h>

using namespace std;
class Sach;
class PhieuMuon;
class BanDoc;
class SinhVien;
class GiaoVien;
class Date
{
private:
	int nNgay, nThang, nNam;
public:
	friend BanDoc;
	friend Sach;
	friend PhieuMuon;
	friend SinhVien;
	friend GiaoVien;
	Date()
	{
		time_t rawtime;
		struct tm *info;
		time(&rawtime);
		info = localtime(&rawtime);
		this->nNgay = (info->tm_mday);
		this->nThang = (info->tm_mon + 1);
		this->nNam = (info->tm_year + 1900);
	}
	Date(int nNgay, int nThang, int nNam)
	{
		this->nNgay = nNgay;
		this->nThang = nThang;
		this->nNam = nNam;
	}
	
	int getNgay();
	int getThang();
	int getNam();
	void setNgay(int nNgay);
	void setThang(int nThang);
	void setNam(int nNam);
	void setTime(int nNgay, int nThang, int nNam);
	void outputDate();
	~Date(void) {};
};

