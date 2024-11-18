#include <iostream>
#include <iomanip>
using namespace std;

// Lop co so KhachSan
class KhachSan {
 protected:
    double sodem;       // So dem khach o tai khach san
    double phidichvu;   // Phi dich vu cua khach san
    double phiphucvu;   // Phi phuc vu cua khach san
 public:
    // Khoi tao co tham so
    KhachSan(double sd, double pdv, double ppv);
};

// Lop Deluxe: ke thua tu lop KhachSan
class Deluxe : public KhachSan {
 public:
    // Khoi tao co tham so
    Deluxe(double sd, double pdv, double ppv);
    double Doanhthu();  // Tinh doanh thu cua phong Deluxe
};

// Lop Premium: ke thua tu lop KhachSan
class Premium : public KhachSan {
 public:
    // Khoi tao co tham so
    Premium(double sd, double pdv);
    double Doanhthu();  // Tinh doanh thu cua phong Premium
};

// Lop Business: ke thua tu lop KhachSan
class Business : public KhachSan {
 public:
    // Khoi tao co tham so
    Business(double sd);
    double Doanhthu();  // Tinh doanh thu cua phong Business
};
