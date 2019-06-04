#include "BanDoc.h"

string BanDoc::getMaBD()
{
	return sMaBD;
}
string BanDoc::getHoTen()
{
	return sHoTen;
}
string BanDoc::getKhoa()
{
	return sKhoa;
}
void BanDoc::setMaBD(string sMaBD)
{
	this->sMaBD = sMaBD;
}
void BanDoc::setHoTen(string sHoTen)
{
	this->sHoTen = sHoTen;
}
void BanDoc::setKhoa(string sKhoa)
{
	this->sKhoa = sKhoa;
}
void BanDoc::setBanDoc(string sMaBD, string sHoTen, string sKhoa)
{
	this->sMaBD = sMaBD;
	this->sHoTen = sHoTen;
	this->sKhoa = sKhoa;
}
