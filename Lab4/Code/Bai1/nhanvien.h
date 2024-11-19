#include<iostream>
#include <iomanip>
#pragma once
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
