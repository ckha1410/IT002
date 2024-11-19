#include "nhanvien.h"

/** Ham khoi tao mac dinh lop NhanVien
    Output: Khoi tao gia tri mac dinh cho msnv, hoten, luongcb */
NhanVien::NhanVien() : msnv(""), hoten(""), luongcb(0) {}

/** Ham khoi tao co tham so lop NhanVien
    Input: MSNV (ma so nhan vien), ten (ho ten), lcb (luong co ban)
    Output: Khoi tao gia tri cho cac thuoc tinh msnv, hoten, luongcb */
NhanVien::NhanVien(string MSNV, string ten, double lcb) :
    msnv(MSNV), hoten(ten), luongcb(lcb) {}

/** Ham nhap thong tin nhan vien
    Input: Nhap tu nguoi dung: msnv, hoten, luongcb
    Output: Cap nhat gia tri cho cac thuoc tinh cua doi tuong */
void NhanVien::Nhap() {
    cout << "Nhap ma so nhan vien: "; cin >> msnv;
    cin.ignore();
    cout << "Nhap ho ten: "; getline(cin, hoten);
    cout << "Nhap luong co ban: "; cin >> luongcb;
}

/** Ham xuat thong tin nhan vien
    Output: Hien thi msnv, hoten, luongcb */
void NhanVien::Xuat() {
    cout << "Ma so nhan vien: " << msnv << "\n";
    cout << "Ho ten: " << hoten << "\n";
    cout << "Luong co ban: " << fixed << setprecision(2) << luongcb << "\n";
}
