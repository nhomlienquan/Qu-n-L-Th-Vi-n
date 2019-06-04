#include "SinhVien.h"


void SinhVien::outputBanDoc()
{
	cout << nLoaiBD << "," << sMaBD << "," << sHoTen << "," << sKhoa << "," <<
		"," << xDate.nNgay << "," << xDate.nThang << "," << xDate.nNam  << "," << nKhoaHoc << endl;
}
void SinhVien::readBanDoc(ifstream &fin)
{
	fin >> nLoaiBD; fin.ignore(1);
	rewind(stdin); getline(fin, sMaBD, ',');
	rewind(stdin); getline(fin, sHoTen, ',');
	rewind(stdin); getline(fin, sKhoa, ',');
	fin >> xDate.nNgay; fin.ignore(1);
	fin >> xDate.nThang; fin.ignore(1);
	fin >> xDate.nNam; fin.ignore(1);
	fin >> nKhoaHoc; fin.ignore(1);
}
void SinhVien::writeBanDoc(ofstream &fout)
{
	fout <<nLoaiBD<<","<< sMaBD << "," << sHoTen << "," << sKhoa << "," << xDate.nNgay << "," << xDate.nThang << "," << xDate.nNam << "," << nKhoaHoc << endl;
}