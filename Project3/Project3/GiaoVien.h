#pragma once
#include "BanDoc.h"

using namespace std;
class GiaoVien  :public BanDoc
{
private:
	string sDiaChi, sSoDT;
	int nLoaiBD;
public:
	GiaoVien()
	{
		sDiaChi = sSoDT = "";
		nLoaiBD = 0;
	}

	GiaoVien(string sMaBD, string sHoTen, string sKhoa, string sDiaChi, string sSoDT)
		:BanDoc(sMaBD, sHoTen, sKhoa)
	{
		this->nLoaiBD = 1;
		this->sDiaChi = sDiaChi;
		this->sSoDT = sSoDT;
	}
	GiaoVien(int nLoaiBD,string sMaBD, string sHoTen, string sKhoa, int nNgay, int nThang, int nNam, string sDiaChi, string sSoDT)
		:BanDoc(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam)
	{
		this->nLoaiBD = 1;
		this->sDiaChi = sDiaChi;
		this->sSoDT = sSoDT;
	}
	void outputBanDoc();
	void readBanDoc(ifstream &fin);
	void writeBanDoc(ofstream &fout);
	~GiaoVien(void) {};
};

