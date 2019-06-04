#ifndef BanDoc_h
#define BanDoc_h

#include "Date.h"

class PhieuMuon;
class BanDoc
{
protected:
	string sMaBD, sHoTen, sKhoa;
	Date xDate; 
public:
	friend PhieuMuon;
	BanDoc()
	{
		sMaBD = sHoTen = sKhoa = "";
	}
	BanDoc(string sMaBD)
	{
		this->sMaBD = sMaBD;
	}
	BanDoc(string sMaBD, string sHoTen, string sKhoa)
		:xDate()
	{
		this->sMaBD = sMaBD;
		this->sHoTen = sHoTen;
		this->sKhoa = sKhoa;
	}
	BanDoc(string sMaBD, string sHoTen, string sKhoa, int nNgay, int nThang, int nNam)
		:xDate(nNgay, nThang, nNam)
	{
		this->sMaBD = sMaBD;
		this->sHoTen = sHoTen;
		this->sKhoa = sKhoa;
	}

	string getMaBD();
	string getHoTen();
	string getKhoa();
	void setMaBD(string sMaBD);
	void setHoTen(string sHoTen);
	void setKhoa(string sKhoa);
	void setBanDoc(string sMaBD, string sHoTen, string sKhoa);
	virtual void outputBanDoc() {};
	virtual void readBanDoc(ifstream &fin) {};
	virtual void writeBanDoc(ofstream &fout) {};
	virtual~BanDoc(void) {};
};
#endif // !BanDoc_h
