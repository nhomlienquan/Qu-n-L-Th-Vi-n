#include "Sach.h"
#include "Date.h"
#include "Admin.h"
#include <vector>
#include "BanDoc.h"
#include "GiaoVien.h"
#include "SinhVien.h"
#include "PhieuMuon.h"
// khai bao nguyen mau ham con
void Color(int nX);
void vienThongBao(string sTenVien);
void inputData_Sach(vector <Sach> &S);
void outputData_Sach(vector <Sach> &S);
void timTheoMaSach(vector <Sach> S,string sKey);
void outputData_BanDoc(vector <BanDoc*> BD);
void inputData_BanDoc(vector <BanDoc*> &BD);
void timTheoMaBanDoc(vector <BanDoc*> BD, string sKey);
string passwordInput(unsigned maxLength);
void inputData_Admin(vector <Admin> &AD);
int login_Admin(vector <Admin> AD);
bool kiemTraPassWord(vector <Admin> AD, string sUser, string sPassWord);
int demSachCon(vector <Sach> S);
int demSachMuon(vector <Sach> S);
int timKiemSach(vector <Sach> S, string sKey);
void ghiDS(vector <Sach> S);
void themSach(vector <Sach> &S);
void xoaDanhSach(vector <Sach> &S);
void themBanDoc(vector <BanDoc*> &BD);
void xoaBanDoc(vector <BanDoc*> &BD);
void ghiDSBD(vector <BanDoc*> BD);
void ghiDSPM(vector <PhieuMuon> PM);
void inputData_PhieuMuon(vector <PhieuMuon> &PM);
void outputData_PhieuMuon(vector <PhieuMuon> &PM);
int soLuongBanDocSinhVien(vector <BanDoc*> BD);
//
bool kiemTraPM(vector <PhieuMuon> PM, int nMaPM);
bool kiemTraBD(vector <BanDoc*> BD, string sMaBD);
int soLuongBanDocGiaoVien(vector <BanDoc*> BD);
//
void CN_TimKiem();
void CN_QuanLySach();
void CN_QuanLyBanDoc();
void CN_QuanLyPhieuMuon();
void CN_ThongKe();
//
//
void outputData_ADmin(vector <Admin> AD);
//
vector <Sach> S;
vector <BanDoc*> BD;
vector <Admin> AD;
vector <PhieuMuon> PM;
int PhieuMuon::nTongPM = 0;

int main()
{
	inputData_Sach(S); 
	inputData_BanDoc(BD);
	inputData_Admin(AD);
	inputData_PhieuMuon(PM);
	string sKey = "";
	int nChon = 0,nChonQL = 0;
	do {
		system("cls");
		vienThongBao("MENUCHINH");
		cout << "\nBAN CHON CHUC NANG: ";
		cin >> nChon;
		switch (nChon)
		{
		case 1:
			Color(9);
			outputData_Sach(S);
			break;
		case 2:
			Color(4);
			outputData_BanDoc(BD);
			break;
		case 3:
			system("cls");
			CN_TimKiem();
			break;
		case 4:
			if (login_Admin(AD) == true)
			{
				do
				{
					system("cls");
					vienThongBao("QUANLY");
					cout << "\nBAN CHON CHUC NANG: ";
					cin >> nChon;
					switch (nChon)
					{
					case 1:
						CN_QuanLyPhieuMuon();
						break;
					case 2:
						CN_QuanLySach();
						break;
					case 3:
						CN_QuanLyBanDoc();
						break;
					case 4:
						CN_ThongKe();
						break;
					default:
						Color(9);
						cout << "BAN DA QUAY LAI TRANG CHU ! \n";
						break;
					}
					system("pause");
				} while (nChonQL >= 1 && nChonQL <= 4);
			}
			else
			{
				Color(4); cout << "\n\t\tBAN DANG NHAP THAT BAI !";
			}
			break;
		default:
			Color(9);
			cout << "BAN DA THOAT CHUONG TRINH ! \n";
			break;
		}
		system("pause");
	} while (nChon >= 1 && nChon <= 4);
	
	return 0;
}
// phieu muon
void inputData_PhieuMuon(vector <PhieuMuon> &PM)
{
	ifstream fin;
	int nN = 0;
	fin.open("PhieuMuon.txt");
	if (fin.is_open() == true)
	{
		cout << "MO FILE THANH CONG !";
	}
	else
	{
		cout << "MO FILE THAT BAI !";
	}
	PhieuMuon pm;
	fin >> nN; fin.ignore(1);
	for (int i = 0; i < nN; i++)
	{

		pm.readPM(fin);
		PM.push_back(pm);
	}
	fin.close();
}
void ghiDSPM(vector <PhieuMuon> PM)
{
	ofstream File;
	File.open("PhieuMuon.txt");
	File << PM.size() << endl;
	for (int i = 0; i < PM.size(); i++)
	{
		BD[i]->writeBanDoc(File);
	}
	File.close();
}
void outputData_PhieuMuon(vector <PhieuMuon> &PM)
{
	cout << "\n*********************THONG TIN SACH*********************\n";
	for (int i = 0; i < PM.size(); i++)
	{
		PM[i].outputPM();
	}
}
bool kiemTraPM(vector <PhieuMuon> PM, int nMaPM)
{
	for (int i = 0; i < PM.size(); i++)
	{
		if (PM[i].getMaPM() == nMaPM)
		{
			return true;
		}
	}
	return false;
}

// ham chuc nang
void CN_TimKiem()
{
	int nChon = 0;
	string sKey;
	vector <Sach> S;
	vector <BanDoc*> BD;
	do
	{
		system("cls");
		vienThongBao("TIMKIEM");
		cin >> nChon;
		switch (nChon)
		{
		case 1:
			inputData_Sach(S);
			cout << "NHAP MA SACH CAN TIM : "; rewind(stdin); getline(cin, sKey);
			timTheoMaSach(S, sKey);
			break;
		case 2:
			inputData_BanDoc(BD);
			cout << "NHAP MA BAN DOC CAN TIM : "; rewind(stdin); getline(cin, sKey);
			timTheoMaBanDoc(BD, sKey);
			break;
		default:
			Color(9);
			cout << "BAN DA VE TRANG CHU! \n";
			break;
		}
		system("pause");
	} while (nChon >= 1 && nChon <= 2);
	
}
void CN_QuanLySach()
{
	int nChon = 0;
	vector <Sach> S;
	do {
		system("cls");
		vienThongBao("QLSACH");
		cout << "\n\t\tBAN CHON CHUC NANG  : "; cin >> nChon;
		switch (nChon)
		{
		case 1:
		inputData_Sach(S);
		themSach(S);
		ghiDS(S);
		break;
		case 2:
		inputData_Sach(S);
		xoaDanhSach(S);
		break;
		default:
		cout << "CHUC NANG BAN TIM KHONG CO !";
		break;
		}
		system("pause");
	} while (nChon >= 1 && nChon <= 2);
}
void CN_QuanLyBanDoc()
{
	int nChon = 0;
	vector <BanDoc*> BD;
	do {
		system("cls");
		vienThongBao("QLBANDOC1");
		cout << "\n\t\tBAN CHON CHUC NANG  : "; cin >> nChon;
		switch (nChon)
		{
		case 1:
			inputData_BanDoc(BD);
			themBanDoc(BD);
			break;
		case 2:
			inputData_BanDoc(BD);
			xoaBanDoc(BD);
			break;
		default:
			cout << "CHUC NANG BAN TIM KHONG CO !";
			break;
		}
		system("pause");
	} while (nChon >= 1 && nChon <= 2);
}
void CN_QuanLyPhieuMuon()
{
	int nChon = 0;
	vector <PhieuMuon> PM;
	vector <Sach> S;
	vector <BanDoc*> BD;
	inputData_PhieuMuon(PM);
	inputData_Sach(S);
	inputData_BanDoc(BD);
	do {
//		system("cls");
		vienThongBao("PHIEUMUON");
		cout << "\n\t\tBAN CHON CHUC NANG  : "; cin >> nChon;
		switch (nChon)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			outputData_PhieuMuon(PM);
			break;
		default:
			cout << "CHUC NANG BAN TIM KHONG CO !";
			break;
		}
		system("pause");
	} while (nChon >= 1 && nChon <= 3);
}
void CN_ThongKe()
{
	int nChon = 0;
	vector <PhieuMuon> PM;
	vector <Sach> S;
	vector <BanDoc*> BD;
	inputData_PhieuMuon(PM);
	inputData_Sach(S);
	inputData_BanDoc(BD);
	do {
		vienThongBao("THONGKE");
		cout << "\n\t\tBAN CHON CHUC NANG  : "; cin >> nChon;
		switch (nChon)
		{
		case 1:
			Color(3);
			cout << "\n\t\tTONG SO SACH CON LAI TRONG THU VIEN : " << demSachCon(S) << endl;
			break;
		case 2:
			cout << "\n\t\tTONG SO SACH DA MUON : " << demSachMuon(S) << endl;
			break;
		case 3:
			cout << "\n\t\tTONG SO BAN DOC LA GIAO VIEN : " << soLuongBanDocGiaoVien(BD) << endl;
			break;
		case 4:
			cout << "\n\t\tTONG SO BAN DOC LA SINH VIEN : " << soLuongBanDocSinhVien(BD) << endl;
			break;
		default:
			cout << "CHUC NANG BAN TIM KHONG CO !";
			break;
		}
		system("pause");
	} while (nChon >= 1 && nChon <= 4);
}
//dang nhap
int login_Admin(vector <Admin> AD)
{
	int nChon = 0;
	string sUser = "";
	string sPass = "";
	vienThongBao("LOGIN");
	cout << "\n\tNHAP USER : "; rewind(stdin); getline(cin, sUser);
	cout << "\n\tNHAP PASSWORD : ";
	sPass = passwordInput(6);
	if (kiemTraPassWord(AD, sUser, sPass) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool kiemTraPassWord(vector <Admin> AD, string sUser, string sPassWord)
{
	for (int i = 0; i < AD.size(); i++)
	{
		if (sUser == AD[i].getUser() && sPassWord == AD[i].getPass())
		{
			return true;
		}
	}
	return false;
}
void outputData_ADmin(vector <Admin> AD)
{
	cout << "\n*********************THONG TIN ADMIN*********************\n";
	for (int i = 0; i < AD.size(); i++)
	{
		AD[i].outputAdmin();
	}
}
void inputData_Admin(vector <Admin> &AD)
{
	ifstream fin;
	int nN = 0;
	fin.open("Admin.txt");
	if (fin.is_open() == true)
	{
		cout << "MO FILE THANH CONG !";
	}
	else
	{
		cout << "MO FILE THAT BAI !";
	}
	Admin ad;
	fin >> nN; fin.ignore(1);
	for (int i = 0; i < nN; i++)
	{
		ad.readAdmin(fin);
		AD.push_back(ad);
	}
	fin.close();
}
string passwordInput(unsigned maxLength)
{
	string pw = "";
	for (char c; (c = getch()); )
	{
		if (c == '\n' || c == '\r') { // \n là phím phím enter + \r là Nhảy về đầu hàng, không xuống hàng
			cout << "\n";
			break;
		}
		else if (c == '\b') { //phím backspace
			cout << "\b \b";
			if (!pw.empty()) pw.erase(pw.size() - 1);
		}
		else if (c == -32) { //phím mũi tên
			_getch(); //bỏ qua kí tự tiếp theo (hướng mũi tên)
		}
		else if (isprint(c) && pw.size() < maxLength) { //isprint tức là chỉ nhận những ký tự in ra được (có tính khoảng trắng)
			cout << '*';
			pw += c;
		}
	}
	return pw;
};
// ban doc
void timTheoMaBanDoc(vector <BanDoc*> BD, string sKey)
{
	int nFlag = 0;
	for (int i = 0; i < BD.size(); i++)
	{
		if (BD[i]->getMaBD() == sKey)
		{
			cout << "\nTHONG TIN SACH TIM DUOC : \n";
			BD[i]->outputBanDoc();
			nFlag = 1;
		}
	}
	if (nFlag == 0)
	{
		Color(4);
		cout << "\t\tMA SACH KHONG TON TAI !\n";
	}
}
void outputData_BanDoc(vector <BanDoc*> BD)
{
	cout << "\n*********************THONG TIN BAN DOC*********************\n";
	for (int i = 0; i < BD.size(); i++)
	{
		BD[i]->outputBanDoc();
	}
}
void ghiDSBD(vector <BanDoc*> BD)
{
	ofstream File;
	File.open("BanDoc.txt");
	File << BD.size() << endl;
	for (int i = 0; i < BD.size(); i++)
	{
		BD[i]->writeBanDoc(File);
	}
	File.close();
}
void inputData_BanDoc(vector <BanDoc*> &BD)
{
	int nN = 0;
	int nLoai = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	ifstream File;
	File.open("BanDoc.txt");
	File >> nN; File.ignore(1);
	for (int i = 0; i < nN; i++)
	{
		File >> nLoai;
		File.ignore(1, ',');
		if (nLoai == 1)
		{
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			getline(File, sDC, ',');
			getline(File, sSDT, '\n');
			BanDoc * gv = new GiaoVien(nLoai,sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDC, sSDT);
			BD.push_back(gv);
		}
		else if (nLoai == 2)
		{
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			File >> nKhoaHoc;
			File.ignore(1, '\n');
			BanDoc * sv = new SinhVien(nLoai,sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
			BD.push_back(sv);
		}
	}
	File.close();
}
void themBanDoc(vector <BanDoc*> &BD)
{
	time_t t = time(0);
	struct tm *Now = localtime(&t);
	int nLoaiBD = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nMa = 0;
	int nNgay = Now->tm_mday;         //
	int nThang = Now->tm_mon + 1;    // Ngày làm thẻ được lấy tự động
	int nNam = Now->tm_year + 1900;  //
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	while (true)
	{
		system("cls");
		cout << "\t\t\t*************************************\n";
		cout << "\t\t\t  1. THEM BAN DOC GIAO VIEN          \n";
		cout << "\t\t\t  2. THEM BAN DOC HOC SINH         \n";
		cout << "\t\t\t  0. Thoat!                          \n";
		cout << "\t\t\t*************************************\n";
		cout << "\t\t\t BAN CHON CHUC NANG: ";
		cin >> nLoaiBD;
		if (nLoaiBD == 1)
		{
			nLoaiBD = 1;
			cout << "\t\tNHAP MA GV : "; rewind(stdin); getline(cin, sMaBD);
			cout << "\t\tNHAP HO VA TEN: "; rewind(stdin); getline(cin, sHoTen);
			cout << "\t\tNHAP KHOA : "; rewind(stdin); getline(cin, sKhoa);
			cout << "\t\tNHAP DIA CHI: "; rewind(stdin); getline(cin, sDC);
			cout << "\t\tNHAP SO DIEN THOAI : "; rewind(stdin); getline(cin, sSDT);
			BanDoc * gv = new GiaoVien(nLoaiBD,sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDC, sSDT);
			BD.push_back(gv);
			ghiDSBD(BD);
			cout << "\t\tThem ban doc thanh cong!\n ";
			system("pause");
			break;
		}
		else if (nLoaiBD == 2)
		{
			nLoaiBD = 2;
			cout << "\t\tNHAP MA SV : "; rewind(stdin); getline(cin, sMaBD);
			cout << "\t\tNHAP HO TEN : "; fflush(stdin); getline(cin, sHoTen);
			cout << "\t\tNHAP KHOA : "; fflush(stdin); getline(cin, sKhoa);
			cout << "\t\tNHAP KHOA HOC : "; cin >> nKhoaHoc;
			BanDoc *  sv = new SinhVien(nLoaiBD,sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
			BD.push_back(sv);
			ghiDSBD(BD);
			cout << "\t\tTHEM BAN DOC THANH CONG\n ";
			system("pause");
			break;
		}
		else if (nLoaiBD == 0)
		{
			break;
		}
		else
		{
			cout << "NHAP SAI NHAP LAI. \n";
		}
	}
}
void xoaBanDoc(vector <BanDoc*> &BD)
{
	int flag = 0;
	string sA = "";
	cout << "NHAP MA BAN DOC CAN XOA : "; rewind(stdin); getline(cin, sA);
	for (int i = 0; i < BD.size(); i++)
	{
		if (BD[i]->getMaBD() == sA)
		{
			BD.erase(BD.begin() + i, BD.begin() + i + 1);
			cout << "XOA SACH THANH CONG !";
			flag = 1;
			ghiDSBD(BD);
		}
	}
	if (flag == 0)
	{
		cout << "\n\t\tMA BAN DOC CAN TIM KHONG CO !";
	}
}
bool kiemTraBD(vector <BanDoc*> BD, string sMaBD)
{
	for (int i = 0; i < PM.size(); i++)
	{
		if (BD[i]->getMaBD() == sMaBD)
		{
			return true;
		}
	}
	return false;
}
int soLuongBanDocGiaoVien(vector <BanDoc*> BD)
{
	int nDem = 0;
	int nLoai = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	ifstream File;
	File.open("BanDoc.txt");
	while (!File.eof())
	{
		File >> nLoai;
		File.ignore(1, ',');
		if (nLoai == 1)
		{
			nDem++;
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			getline(File, sDC, ',');
			getline(File, sSDT, '\n');
		}
		else if (nLoai == 2)
		{
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			File >> nKhoaHoc;
			File.ignore(1, '\n');
		}
	}
	File.close();
	return nDem;
}
int soLuongBanDocSinhVien(vector <BanDoc*> BD)
{
	int nDem = 0;
	int nLoai = 0;
	string sMaBD = "";
	ifstream File;
	File.open("BanDoc.txt");
	while (!File.eof())
	{
		File >> nLoai;
		File.ignore(1, ',');
		if (nLoai == 1)
		{
			getline(File, sMaBD, '\n');
		}
		else if (nLoai == 2)
		{
			nDem++;
			getline(File, sMaBD, '\n');
		}
	}
	return nDem;
}
// sach
void timTheoMaSach(vector <Sach> S,string sKey)
{
	int nFlag = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMaSach() == sKey)
		{
			cout << "\nTHONG TIN SACH TIM DUOC : \n";
			S[i].outputSach();
			nFlag = 1;
		}
	}
	if (nFlag == 0)
	{
		Color(4);
		cout << "\t\tMA SACH KHONG TON TAI !\n";
	}
}
void inputData_Sach(vector <Sach> &S)
{
	ifstream fin;
	int nN = 0;
	fin.open("Sach.txt");
	if (fin.is_open() == true)
	{
		cout << "MO FILE THANH CONG !";
	}
	else
	{
		cout << "MO FILE THAT BAI !";
	}
	Sach s;
	fin >> nN; fin.ignore(1);
	for (int i = 0; i < nN; i++)
	{
		s.readSach(fin);
		S.push_back(s);
	}
	fin.close();
}
void outputData_Sach(vector <Sach> &S)
{
	cout << "\n*********************THONG TIN SACH*********************\n";	
	for (int i = 0; i < S.size(); i++)
	{
		S[i].outputSach();
	}
}
int demSachCon(vector <Sach> S)
{
	int nDem = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 0)
		{
			nDem++;
		}
	}
	return nDem;
}
int demSachMuon(vector <Sach> S)
{
	int nDem = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 1)
		{
			nDem++;
		}
	}
	return nDem;
}
int timKiemSach(vector <Sach> S, string sKey)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMaSach() == sKey)
		{
			return i;
		}
	}
	return -1;
}
void themSach(vector <Sach> &S)
{
	time_t rawtime;
	struct tm *info;
	time(&rawtime);
	info = localtime(&rawtime);
	string sMaSach ="", sTuaDe = "", sTacGia = "", sNXB = "";
	float fTriGia = 0.0;
	int nNamPhatHanh = 0, nSoTrang = 0;
	int nNgay =0, nThang =0, nNam=0;
	int nTinhTrang;
	quaylai:
	cout << "\n\t\tNHAP MA SACH : "; rewind(stdin); getline(cin, sMaSach);
	if (timKiemSach(S, sMaSach) != -1)
	{
		cout << "\n\t\tSACH DA TON LAI NHAP LAI ! ";
		goto quaylai;
	}
	cout << "\t\tNHAP TUA DE : "; rewind(stdin); getline(cin, sTuaDe);
	cout << "\t\tNHAP TAC GIA : "; rewind(stdin); getline(cin, sTacGia);
	cout << "\t\tNHAP NXB : "; rewind(stdin); getline(cin, sNXB);
	cout << "\t\tNHAP TRI GIA"; cin >> fTriGia; cin.ignore(1);
	cout << "\t\tNHAP NAM PHAT HANH  : "; cin >> nNamPhatHanh; cin.ignore(1);
	nNgay = (info->tm_mday);
	nThang = (info->tm_mon + 1);
	nNam = (info->tm_year + 1900);
	cout << "\t\tNHAP SO TRANG  : "; cin >> nSoTrang; cin.ignore(1);
	nTinhTrang = 0;
	cout << "\nTHEM SACH THANH CONG !";
	Sach a (sMaSach, sTuaDe, sTacGia, sNXB, fTriGia, nNamPhatHanh, nSoTrang,nNgay,nThang,nNam, nTinhTrang);
	S.push_back(a);
	// muon tghenm
}
void ghiDS(vector <Sach> S)
{
	ofstream File;
	File.open("Sach.txt");
	File << S.size() << endl;
	for (int i = 0; i < S.size(); i++)
	{
		S[i].writeSach(File);
	}
	File.close();
}
void xoaDanhSach(vector <Sach> &S)
{
	int flag = 0;
	string sA = "";
	cout << "NHAP MA SACH CAN XOA : "; rewind(stdin); getline(cin, sA);
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMaSach() == sA)
		{
			S.erase(S.begin() + i, S.begin() + i+1);
			cout << "XOA SACH THANH CONG !";
			flag = 1;
			ghiDS(S);
		}
	}
	if (flag == 0)
	{
		cout << "\n\t\tMA SACH CAN TIM KHONG CO !";
	}
}
//vien thong bao
void vienThongBao(string sTenVien)
{
	if (sTenVien == "TIMKIEM")
	{
		Color(10);
		cout << "\t\t*******************TIM THONG TIN************************\n";
		cout << "\t\t  1. TIM SACH THEO MA SACH.                \n";
		cout << "\t\t  2. TIM SACH THEO BAN DOC.          \n";
		cout << "\t\t  0. THOAT!                                \n";
		cout << "\t\t********************************************************\n";
		cout << "\t\t  BAN CHON CHUC NANG: ";
	}
	else if (sTenVien == "MENUCHINH")
	{
		Color(10);
		cout << "\n*****************************MENU****************************\n";
		cout << "" << endl;
		cout << "\t\t 1. HIEN THI THONG TIN SACH . \n";
		cout << "\t\t 2. HIEN THI THONG TIN BAN DOC. \n";
		cout << "\t\t 3. TIM KIEM THONG TIN. \n";
		cout << "\t\t 4. QUAN LY. \n";
		cout << "\t\t 0. THOAT. \n";
		cout << "\n***********************************************************\n";
	}
	else if (sTenVien == "LOGIN")
	{
		system("cls");
		cout << "\t\t************************************\n";
		Color(10);
		cout << "\t\t*              LOGIN               *\n";
		cout << "\t\t************************************\n";
	}
	else if (sTenVien == "QUANLY")
	{
		system("cls");
		cout << "\t\t*******************************************\n";
		cout << "\t\t  1. QUAN LY PHIEU MUON.                   \n";
		cout << "\t\t  2. QUAN LY SACH.                         \n";
		cout << "\t\t  3. QUAN LY BAN DOC                      \n";
		cout << "\t\t  4. THONG KE.                             \n";
		cout << "\t\t  0. Thoat!                                \n";
		cout << "\t\t*******************************************\n";
	}
	else if (sTenVien == "QLSACH")
	{
		system("cls");
		cout << "\t\t********QUAN LY SACH********\n";
		cout << "\t\t      1. THEM SACH MOI.     \n";
		cout << "\t\t      2. XOA SACH.          \n";
		cout << "\t\t      0. Thoat!             \n";
		cout << "\t\t****************************\n";
	}
	else if (sTenVien == "QLBANDOC1")
	{
		system("cls");
		cout << "\t\t********QUAN LY SACH********\n";
		cout << "\t\t      1. THEM BAN DOC.     \n";
		cout << "\t\t      2. XOA BAN DOC.       \n";
		cout << "\t\t      0. THOATt!             \n";
		cout << "\t\t****************************\n";
	}
	else if (sTenVien == "QLBANDOC2")
	{
		system("cls");
		cout << "\t\t\t*************************************\n";
		cout << "\t\t\t  1. THEM BAN DOC GIAO VIEN         \n";
		cout << "\t\t\t  2. THEM BAN DOC SINH VIEN        \n";
		cout << "\t\t\t  0. THOAT!                          \n";
		cout << "\t\t\t*************************************\n";
	}
	else if (sTenVien == "PHIEUMUON")
	{
		system("cls");
		cout << "\t\t******************************************\n";
		cout << "\t\t  1. MUON SACH.  (Chua HT)                   \n";
		cout << "\t\t  2. TRA SACH.       (Chua HT)               \n";
		cout << "\t\t  3. XUAT DS PHIEU MUON            \n";
		cout << "\t\t  0. Thoat!                               \n";
		cout << "\t\t******************************************\n";
	}
	else if (sTenVien == "THONGKE")
	{
		system("cls");
		cout << "\t\t*************************Thong ke*************************\n";
		cout << "\t\t  1. TONG SO SACH CON LAI TRONG THU VIEN .                \n";
		cout << "\t\t  2. TONG SO SACH DA MUON  .                               \n";
		cout << "\t\t  3. TONG SO BAN DOC LA GIAO VIEN                          \n";
		cout << "\t\t  4. TONG SO BAN DOC LA SINH VIEN                         \n";
		cout << "\t\t  0. Thoat!                                               \n";
		cout << "\t\t**********************************************************\n";
	}
}

void Color(int nX)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, nX);
}
