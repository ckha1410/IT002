#include<bits/stdc++.h>
using namespace std;

// Dinh nghia lop NgayThangNam
class NgayThangNam {
 private:
    // Thuoc tinh: ngay, thang, nam cua doi tuong NgayThangNam
    int iNgay, iThang, iNam;
 public:
    // Ham khoi tao mac dinh
    NgayThangNam();
    // Ham khoi tao co tham so
    NgayThangNam(int Nam, int Thang, int Ngay);
    // Tinh tong so ngay tu ngay 1/1/1 den ngay hien tai
    int TinhNgay();
    // Toan tu cong them mot so ngay vao ngay hien tai
    NgayThangNam operator+(int ngay);
    // Toan tu tru di mot so ngay tu ngay hien tai
    NgayThangNam operator-(int ngay);
    // Toan tu tru de tinh so ngay chenh lech giua hai ngay
    int operator-(NgayThangNam a);
    // Toan tu tang ngay len 1 ngay vao ngay hien tai
    NgayThangNam operator++();
    // Toan tu giam ngay xuong 1 ngay vao ngay hien tai
    NgayThangNam operator--();
    // Toan tu so sanh hai ngay bang nhau
    bool operator==(NgayThangNam a);
    // Toan tu so sanh hai ngay khac nhau
    bool operator!=(NgayThangNam a);
    // Toan tu so sanh lon hon hoac bang
    bool operator>=(NgayThangNam a);
    // Toan tu so sanh nho hon hoac bang
    bool operator<=(NgayThangNam a);
    // Toan tu so sanh lon hon
    bool operator>(NgayThangNam a);
    // Toan tu so sanh nho hon
    bool operator<(NgayThangNam a);
    // Toan tu nhap du lieu ngay/thang/nam tu nguoi dung
    friend istream& operator>>(istream &is, NgayThangNam &a);
    // Toan tu xuat du lieu ngay/thang/nam ra man hinh
    friend ostream& operator<<(ostream &os, NgayThangNam a);
};
