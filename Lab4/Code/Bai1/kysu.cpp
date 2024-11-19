#include "kysu.h"

/** Ham khoi tao mac dinh cua lop KySu
    Output: Khoi tao gia tri mac dinh cho lop NhanVien va giolamthem */
KySu::KySu() : NhanVien(), giolamthem(0) {}

/** Ham khoi tao co tham so cua lop KySu
    Input: MSNV (ma so nhan vien), ten (ho ten), lcb (luong co ban),
           glt (gio lam them)
    Output: Khoi tao gia tri cho lop NhanVien va giolamthem */
KySu::KySu(string MSNV, string ten, double lcb, double glt) :
    NhanVien(MSNV, ten, lcb), giolamthem(glt) {}

/** Ham nhap thong tin cua ky su
    Input: Nhap tu nguoi dung: msnv, hoten, luongcb, giolamthem
    Output: Cap nhat gia tri cho cac thuoc tinh cua doi tuong KySu */
void KySu::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap so gio lam them: "; cin >> giolamthem;
}

/** Ham xuat thong tin cua ky su
    Output: Hien thi msnv, hoten, luongcb, va tien thuong */
void KySu::Xuat() {
    NhanVien::Xuat();
    cout << "Tien thuong: "<< fixed << setprecision(2) << TienThuong() << "\n";
}

/** Ham tinh tien thuong cua ky su
    Output: Gia tri tien thuong
    Solution: Tinh tien thuong  = giolamthem * 100000 */
double KySu::TienThuong() {
    return giolamthem * 100000;
}
