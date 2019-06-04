#include "PhieuMuon.h"



int PhieuMuon::getMaPM()
{
	return nMaPM;
}
int PhieuMuon::getTrangThai()
{
	return nTrangThai;
}
string PhieuMuon::getMaBanDoc()
{
	return this->xBanDoc.getMaBD();
}
string PhieuMuon::getMaSach()
{
	return this->xSach.getMaSach();
}
Date PhieuMuon::getNgayMuon()
{
	return this->xNgayMuon;
}
Date PhieuMuon::getNgayTra()
{
	return this->xNgayTra;
}
void PhieuMuon::setTrangThai(int a)
{
	this->nTrangThai = a;
}
void PhieuMuon::outputPM()
{
	cout << setw(20) << "MA PHIEU MUON : " << setw(20) << this->getMaPM() << endl;
	cout << setw(20) << "MA BAN DOC: " << setw(15) << this->getMaBanDoc() << endl;
	cout << setw(20) << "MA SACH : " << setw(15) << this->getMaSach() << endl;
	cout << setw(20) << "NGAY MUON : " << setw(15); this->getNgayMuon().outputDate();
	cout << setw(20) << "NGAY TRA : " << setw(15); this->getNgayTra().outputDate();
	cout << setw(20) << "TRINH TRANG : " << setw(15) << this->nTrangThai << endl;
	cout << "------------------------------------------------------------\n";
}
Date & PhieuMuon::tinhNgayTra()
{
	switch (xNgayMuon.nThang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	{
		xNgayTra.nNgay = xNgayMuon.nNgay + 7;
		if (xNgayTra.nNgay > 31)
		{
			xNgayTra.nNgay = xNgayTra.nNgay - 31;
		}
		if (xNgayTra.nThang > 12)
		{
			xNgayTra.nThang = 1;
			xNgayTra.nNam++;
		}
	}
	case 4: case 6: case 9: case 11:
	{
		xNgayTra.nNgay = xNgayMuon.nNgay + 7;
		if (xNgayTra.nNgay > 30)
		{
			xNgayTra.nNgay = xNgayTra.nNgay - 30;
		}
		if (xNgayTra.nThang > 12)
		{
			xNgayTra.nThang = 1;
			xNgayTra.nNam++;
		}
	}
	default:
		if ((xNgayMuon.nNam % 400 == 0) || (xNgayMuon.nNam % 4 == 0) || (xNgayMuon.nNam % 400 != 0))
		{
			xNgayTra.nNgay = xNgayTra.nNgay + 7;
			if (xNgayTra.nNgay > 28)
			{
				xNgayTra.nNgay == xNgayTra.nNgay - 28;
				xNgayTra.nThang++;
			}
		}
		else
		{
			xNgayTra.nNgay = xNgayTra.nNgay + 7;
			if (xNgayTra.nNgay > 29)
			{
				xNgayTra.nNgay = xNgayTra.nNgay - 29;
				xNgayTra.nThang++;
			}
		}
		break;
	}
	return xNgayTra;
}
void PhieuMuon::writePM(ofstream &file)
{
	file << getMaPM() << "," << getMaBanDoc() << "," << getMaSach()
		<< "," << getNgayMuon().getNgay() << "," << getNgayMuon().getThang() << "," << getNgayMuon().getNam()
		<< "," << getNgayTra().getNgay() << "," << getNgayTra().getThang() << "," << getNgayTra().getNam()
		<< "," << getTrangThai() << endl;

}
void PhieuMuon::readPM(ifstream &file)
{
	file >> nMaPM; file.ignore(1);
	rewind(stdin); getline(file, xBanDoc.sMaBD, ',');
	rewind(stdin); getline(file, xSach.sMaSach, ',');
	file >> xNgayMuon.nNgay; file.ignore(1);
	file >> xNgayMuon.nThang; file.ignore(1);
	file >> xNgayMuon.nNam; file.ignore(1);

	file >> xNgayTra.nNgay; file.ignore(1);
	file >> xNgayTra.nThang; file.ignore(1);
	file >> xNgayTra.nNam; file.ignore(1);
	file >> nTrangThai; file.ignore(1);
}