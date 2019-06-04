#include "Sach.h"


string Sach::getMaSach()
{
	return sMaSach;
}
string Sach::getTuaDe()
{
	return sTuaDe;
}
string Sach::getTacGia()
{
	return sTacGia;
}
string Sach::getNXB()
{
	return sNXB;
}
float Sach::getTriGia()
{
	return fTriGia;
}
int Sach::getNgayNK()
{
	return xNgayNhapKho.nNgay;
}
int Sach::getThangNK()
{
	return xNgayNhapKho.nThang;
}
int Sach::getNamNK()
{
	return xNgayNhapKho.nNam;
}
int Sach::getNamPhatHanh()
{
	return nNamPhatHanh;
}
int Sach::getSoTrang()
{
	return nSoTrang;
}
int Sach::getTinhTrang()
{
	return nTinhTrang;
}
// set
void Sach::setMaSach(string sMaSach)
{
	this->sMaSach = sMaSach;
}
void Sach::setTuaDe(string sTuaDe)
{
	this->sTuaDe = sTuaDe;
}
void Sach::setTacGia(string sTacGia)
{
	this->sTacGia = sTacGia;
}
void Sach::setNXB(string sNXB)
{
	this->sNXB = sNXB;
}
void Sach::setTriGia(float fTriGia)
{
	this->fTriGia = fTriGia;
}
void Sach::setNgayNK(int nNgay)
{
	this->xNgayNhapKho.nNgay = nNgay;
}
void Sach::setThangNK(int nThang)
{
	this->xNgayNhapKho.nThang = nThang;
}
void Sach::setNamNK(int nNam)
{
	this->xNgayNhapKho.nNam = nNam;
}
void Sach::setNamPhatHanh(int nNamPhatHanh)
{
	this->nNamPhatHanh = nNamPhatHanh;
}
void Sach::setSoTrang(int nSoTrang)
{
	this->nSoTrang = nSoTrang;
}
void Sach::setTinhTrang(int nTrinhTrang)
{
	this->nTinhTrang = nTinhTrang;
}
void Sach::outputSach()
{
	cout << sMaSach << "," << sTuaDe << "," << sTacGia << "," << sNXB << "," << fTriGia << "," << nNamPhatHanh << "," << nSoTrang <<
		"," << xNgayNhapKho.nNgay << "," << xNgayNhapKho.nThang << "," << xNgayNhapKho.nNam << endl;
} 

void Sach::readSach(ifstream &fin)
{
	rewind(stdin); getline(fin, sMaSach, ',');
	rewind(stdin); getline(fin, sTuaDe, ',');
	rewind(stdin); getline(fin, sTacGia, ',');
	rewind(stdin); getline(fin, sNXB, ',');
	fin >> fTriGia; fin.ignore(1);
	fin >> nNamPhatHanh; fin.ignore(1);
	fin >> nSoTrang; fin.ignore(1);
	fin >> xNgayNhapKho.nNgay; fin.ignore(1);
	fin >> xNgayNhapKho.nThang; fin.ignore(1);
	fin >> xNgayNhapKho.nNam; fin.ignore(1);
	fin >> nTinhTrang; fin.ignore(1);
}
void Sach::writeSach(ofstream &fout)
{
	fout << sMaSach << "," << sTuaDe << "," << sTacGia << "," << sNXB << "," << fTriGia << "," << nNamPhatHanh << "," << nSoTrang <<
		"," << xNgayNhapKho.nNgay << "," << xNgayNhapKho.nThang << "," << xNgayNhapKho.nNam << "," << nTinhTrang << endl;
}