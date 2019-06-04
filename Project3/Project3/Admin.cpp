#include "Admin.h"



string Admin::getUser()
{
	return sUser;
}
string Admin::getPass()
{
	return sPasss;
}
void Admin::setUser(string sUser)
{
	this->sUser = sUser;
}
void Admin::setPass(string sPass)
{
	this->sPasss = sPass;
}
void Admin::readAdmin(ifstream &fin)
{
	rewind(stdin); getline(fin, sUser, ',');
	rewind(stdin); getline(fin, sPasss);
}
void Admin::writeAdmin(ostream &fout)
{
	fout << sUser << "," << sPasss << endl;
}
void Admin::outputAdmin()
{
	cout << sUser << "," << sPasss << endl;
}
