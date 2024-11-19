#include "nhanvien.h"

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
