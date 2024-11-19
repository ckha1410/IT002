#include "khachsan.h"

// Lop Deluxe: ke thua tu lop KhachSan
class Deluxe : public KhachSan {
 public:
    // Khoi tao co tham so
    Deluxe(double sd, double pdv, double ppv);
    double Doanhthu();  // Tinh doanh thu cua phong Deluxe
};
