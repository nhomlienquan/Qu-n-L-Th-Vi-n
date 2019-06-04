#include "GiaoVien.h"


void GiaoVien::outputBanDoc()
{
	cout << nLoaiBD << "," << sMaBD << "," << sHoTen << "," << sKhoa <<  "," <<
		"," << xDate.nNgay << "," << xDate.nThang << "," << xDate.nNam  <<","<< sDiaChi <<"," << sSoDT << endl;
}
void GiaoVien::readBanDoc(ifstream &fin)
{
	fin >> nLoaiBD; fin.ignore(1);
	rewind(stdin); getline(fin, sMaBD, ',');
	rewind(stdin); getline(fin, sHoTen, ',');
	rewind(stdin); getline(fin, sKhoa, ',');
	fin >> xDate.nNgay; fin.ignore(1);
	fin >> xDate.nThang; fin.ignore(1);
	fin >> xDate.nNam; fin.ignore(1);
	rewind(stdin); getline(fin, sDiaChi, ',');
	rewind(stdin); getline(fin, sSoDT, ',');
	
}
void GiaoVien::writeBanDoc(ofstream &fout)
{
	fout << nLoaiBD << ","<< sMaBD << "," << sHoTen << "," << sKhoa <<"," << xDate.nNgay << "," << xDate.nThang << "," << xDate.nNam << "," << sDiaChi << "," << sSoDT << endl;
}
