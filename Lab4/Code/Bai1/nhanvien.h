#include<iostream>
#include <iomanip>
using namespace std;

// Lop co so Nhan vien
class NhanVien {
 protected:
     string msnv;    // Ma so nhan vien
     string hoten;   // Ho ten nhan vien
     double luongcb; // Luong co ban
 public:
    // Ham khoi tao mac dinh
    NhanVien();
    // Ham khoi tao co tham so
    NhanVien(string MSNV, string ten, double lcb);
    void Nhap();    // Ham nhap thong tin nhan vien
    void Xuat();    // Ham xuat thong tin nhan vien
};

// Lop QuanLy: ke thua tu lop NhanVien
class QuanLy : public NhanVien {
 private:
     double tylethuong; // Ty le thuong cua quan ly
 public:
    // Ham khoi tao mac dinh
    QuanLy();
    // Ham khoi tao co tham so
    QuanLy(string MSNV, string ten, double lcb, double tlt);
    void Nhap();         // Ham nhap thong tin quan ly
    void Xuat();         // Ham xuat thong tin quan ly
    double TienThuong(); // Ham tinh tien thuong
};

// Lop KySu: ke thua tu lop NhanVien
class KySu : public NhanVien {
 private:
    double giolamthem;  // So gio lam them cua ky su
 public:
    // Ham khoi tao mac dinh
    KySu();
    // Ham khoi tao co tham so
    KySu(string MSNV, string ten, double lcb, double glt);
     void Nhap();        // Ham nhap thong tin quan ly
    void Xuat();         // Ham xuat thong tin quan ly
    double TienThuong(); // Ham tinh tien thuong
};
