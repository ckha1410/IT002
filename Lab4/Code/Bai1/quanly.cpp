#include "quanly.h"

/** ham khoi tao mac dinh cua lop QuanLy
    Output: Khoi tao gia tri mac dinh cho lop NhanVien va tylethuong */
QuanLy::QuanLy() : NhanVien(), tylethuong(0) {}

/** Ham khoi tao co tham so cua lop QuanLy
    Input: MSNV (ma so nhan vien), ten (ho ten), lcb (luong co ban),
           tlt (ty le thuong)
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
    cout << "Tien thuong: "<< fixed << setprecision(2) << TienThuong() << "\n";
}

/** Ham tinh tien thuong cua quan ly
    Output: Gia tri tien thuong
    Solution: Tinh tien thuong = luongcb * tylethuong */
double QuanLy::TienThuong() {
    return luongcb * tylethuong;
}
