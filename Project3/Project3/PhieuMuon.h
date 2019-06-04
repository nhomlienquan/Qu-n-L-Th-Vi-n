#ifndef PhieuMuon_h
#define PhieuMuon_h


#include "BanDoc.h"
#include "Sach.h"
class Date;
class Sach;
class BanDoc;
class PhieuMuon
{
private:
	BanDoc xBanDoc;
	Sach xSach;
	Date xNgayMuon, xNgayTra;
	static int nTongPM;
	int nMaPM;
	int nTrangThai;
public:
	friend Date;
	friend BanDoc;
	friend Sach;
	PhieuMuon()
	{
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = 1;
		this->xNgayTra = tinhNgayTra();
	}
	PhieuMuon(string sMaBD, string sMaSach)
		:xBanDoc(sMaBD), xSach(sMaSach)
	{
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = 1;
		this->xNgayTra = tinhNgayTra();
	}
	PhieuMuon(int nMaPM, string sMaBD, string sMaSach, int nNgay1, int nThang1, int nNam1, int nNgay2, int nThang2, int nNam2, int nTrangThai)
		:xBanDoc(sMaBD),xSach(sMaSach), xNgayMuon(nNgay1, nThang1, nNam1), xNgayTra(nNgay2, nThang2, nNam2)
	{
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = 1;
		this->xNgayTra = tinhNgayTra();	
	}
	int getMaPM();
	int getTrangThai();
	void outputPM();
	string getMaSach();
	string getMaBanDoc();
	Date getNgayMuon();
	Date getNgayTra();
	void setTrangThai(int a);
	Date & tinhNgayTra();
	void writePM(ofstream &file);
	void readPM(ifstream &file);
	static int getTongPM()
	{
		return nTongPM;
	}
	~PhieuMuon(void) {};
};
#endif // !PhieuMuon_h
