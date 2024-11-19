#include <iostream>
#include <iomanip>
#pragma once
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
