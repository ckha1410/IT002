#include "khachsan.h"

// Lop Business: ke thua tu lop KhachSan
class Business : public KhachSan {
 public:
    // Khoi tao co tham so
    Business(double sd);
    double Doanhthu();  // Tinh doanh thu cua phong Business
};
