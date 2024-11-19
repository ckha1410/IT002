#include "nhanvien.h"

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
