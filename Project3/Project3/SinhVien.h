#pragma once
#include "BanDoc.h"
class SinhVien :public BanDoc
{
private:
	int nKhoaHoc;
	int nLoaiBD;
	Date xDate;
public:
	SinhVien()
	{
		nKhoaHoc = 0;
	}
	SinhVien(string sMaBD, string sHoTen, string sKhoa, int nKhoaHoc)
		:BanDoc(sMaBD, sHoTen, sKhoa)
	{
		this->nLoaiBD = 2;
		this->nKhoaHoc = nKhoaHoc;
	}
	SinhVien(int nLoaiBD,string sMaBD, string sHoTen, string sKhoa, int nNgay, int nThang, int nNam,int nKhoaHoc)
		:BanDoc(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam)
	{
		this->nLoaiBD = 2;
		this->nKhoaHoc = nKhoaHoc;
	}
	void outputBanDoc();
	void readBanDoc(ifstream &fin);
	void writeBanDoc(ofstream &fout);
	~SinhVien(void) {};
};

