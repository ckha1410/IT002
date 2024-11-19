#include "khachsan.h"

// Lop Premium: ke thua tu lop KhachSan
class Premium : public KhachSan {
 public:
    // Khoi tao co tham so
    Premium(double sd, double pdv);
    double Doanhthu();  // Tinh doanh thu cua phong Premium
};
