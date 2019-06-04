#pragma once
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;
class PhieuMuon;
class Sach
{
private:
	string sMaSach, sTuaDe, sTacGia, sNXB;
	float fTriGia;
	int nNamPhatHanh, nSoTrang;
	Date xNgayNhapKho;
	string sMaPhieuMuon;
	int nTinhTrang;
public:
	friend PhieuMuon;
	Sach()
	{
		sMaSach, sTuaDe, sTacGia, sNXB = "";
		fTriGia = 0.0;
		nNamPhatHanh, nSoTrang = 0;
		nTinhTrang = 1;
	}
	Sach(string sMaSach)
	{
		this->sMaSach = sMaSach;
		nTinhTrang = 1;
	}
	Sach(string sMaSach, string sTuaDe, string sTacGia, string sNXB, float fTriGia, int nNamPhatHanh, int nSoTrang, int nTinhTrang)
	{
		this->sMaSach = sMaSach;
		this->sTuaDe = sTuaDe;
		this->sTacGia = sTacGia;
		this->sNXB = sNXB;
		this->fTriGia = fTriGia;
		this->nNamPhatHanh = nNamPhatHanh;
		this->nSoTrang = nSoTrang;
		this->nTinhTrang = 0;
	}
	Sach(string sMaSach, string sTuaDe, string sTacGia, string sNXB, float fTriGia, int nNamPhatHanh, int nSoTrang,int nNgay, int nThang, int nNam, int nTinhTrang)
		:xNgayNhapKho(nNgay, nThang, nNam)
	{
		this->sMaSach = sMaSach;
		this->sTuaDe = sTuaDe;
		this->sTacGia = sTacGia;
		this->sNXB = sNXB;
		this->fTriGia = fTriGia;
		this->nNamPhatHanh = nNamPhatHanh;
		this->nSoTrang = nSoTrang;
		this->nTinhTrang = 0;
	}
	// get
	string getMaSach();
	string getTuaDe();
	string getTacGia();
	string getNXB();
	float getTriGia();
	int getNgayNK();
	int getThangNK();
	int getNamNK();
	int getNamPhatHanh();
	int getSoTrang();
	int getTinhTrang();
	// set
	void setMaSach(string sMaSach);
	void setTuaDe(string sTuaDe);
	void setTacGia(string sTacGia);
	void setNXB(string sNXB);
	void setTriGia(float fTriGia);
	void setNgayNK(int nNgay);
	void setThangNK(int nThang);
	void setNamNK(int nNam);
	void setNamPhatHanh(int nNamPhatHanh);
	void setSoTrang(int nSoTrang);
	void setTinhTrang(int nTrinhTrang);
	//
	void outputSach();
	void readSach(ifstream &fin);
	void writeSach(ofstream &fout);

	~Sach(){}
};

