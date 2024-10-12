#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
// Build a class ThiSinh
class ThiSinh {
 private:
    string Ten;
    string MSSV;
    int iNgay;
    int iThang;
    int iNam;
    double fToan;
    double fVan;
    double fAnh;
 public:
    void Nhap(); // Input method to enter candidate's details
    void Xuat(); // Output method to display candidate's details
    double Tong(); // Method to calculate the total score
};




