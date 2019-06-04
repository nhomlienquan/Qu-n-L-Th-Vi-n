#include "Date.h"

int Date::getNgay()
{
	return nNgay;
}
int Date::getThang()
{
	return nThang;
}
int Date::getNam()
{
	return nNam;
}
void Date::setNgay(int nNgay)
{
	this->nNgay = nNgay;
}
void Date::setThang(int nThang)
{
	this->nThang = nThang;
}
void Date::setNam(int nNam)
{
	this->nNam = nNam;
}
void Date::setTime(int nNgay, int nThang, int nNam)
{
	this->nNgay = nNgay;
	this->nThang = nThang;
	this->nNam = nNam;
}
void Date::outputDate()
{
	cout << nNgay << "," << nThang << "," << nNam;
}