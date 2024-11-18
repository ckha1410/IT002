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
    cout << "Long co ban: " << fixed << setprecision(2) << luongcb << "\n";
}

/** ham khoi tao mac dinh cua lop QuanLy
    Output: Khoi tao gia tri mac dinh cho lop NhanVien va tylethuong */
QuanLy::QuanLy() : NhanVien(), tylethuong(0) {}

/** Ham khoi tao co tham so cua lop QuanLy
    Input: MSNV (ma so nhan vien), ten (ho ten), lcb (luong co ban), tlt (ty le thuong)
    Output: Khoi tao gia tri cho lop NhanVien va tylethuong */
QuanLy::QuanLy(string MSNV, string ten, double lcb, double tlt) :
    NhanVien(MSNV, ten, lcb), tylethuong(tlt) {}

/** Ham nhap thong tin cua quan ly
    Input: Nhap tu nguoi dung: msnv, hoten, luongcb, tylethuong
    Output: Cap nhat gia tri cho cac thuoc tinh cua doi tuong QuanLy */
void QuanLy::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap ty le thuong: "; cin >> tylethuong;
}

/** Ham xuat thong tin cua quan ly
    Output: Hien thi msnv, hoten, luongcb, va tien thuong */
void QuanLy::Xuat() {
    NhanVien::Xuat();
    cout << "Tien thuong: " << fixed << setprecision(2) << TienThuong() << "\n";
}

/** Ham tinh tien thuong cua quan ly
    Output: Gia tri tien thuong
    Solution: Tinh tien thuong = luongcb * tylethuong */
double QuanLy::TienThuong() {
    return luongcb * tylethuong;
}

/** Ham khoi tao mac dinh cua lop KySu
    Output: Khoi tao gia tri mac dinh cho lop NhanVien va giolamthem */
KySu::KySu() : NhanVien(), giolamthem(0) {}

/** Ham khoi tao co tham so cua lop KySu
    Input: MSNV (ma so nhan vien), ten (ho ten), lcb (luong co ban), glt (gio lam them)
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
    cout << "Tien thuong: " << fixed << setprecision(2) << TienThuong() << "\n";
}

/** Ham tinh tien thuong cua ky su
    Output: Gia tri tien thuong
    Solution: Tinh tien thuong  = giolamthem * 100000 */
double KySu::TienThuong() {
    return giolamthem * 100000;
}



