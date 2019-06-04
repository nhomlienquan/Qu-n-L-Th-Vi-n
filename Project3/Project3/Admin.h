#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Admin
{
private:
	string sUser, sPasss;
public:
	Admin()
	{
		sUser = sPasss = "";
	}
	Admin(string sUser, string sPasss)
	{
		this->sUser = sUser;
		this->sPasss = sPasss;
	}
	string getUser();
	string getPass();
	void setUser(string sUser);
	void setPass(string sPass);
	 void readAdmin(ifstream &fin);
	 void writeAdmin(ostream &fout);
	 void outputAdmin();
	~Admin(void) {};
};

