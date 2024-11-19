#include "premium.h"

/** Ham khoi tao co tham so lop Premium
    Input: sd (so dem), pdv (phi dich vu)
    Output: Khoi tao gia tri cho cac thuoc tinh sodem, phiphucvu */
Premium::Premium(double sd, double pdv) :
    KhachSan(sd, pdv, 0) {}

/** Tinh doanh thu cua phong Premium
    Input: So dem khach o, phi dich vu
    Output: Doanh thu cua phong Premium
    Solution:
      - Cong tong doanh thu bang: so dem * 500,000 + phi dich vu
      - Phi phuc vu bang 0 vi khong ap dung cho phong Premium */
double Premium::Doanhthu() {
    if (sodem == 0) return 0;
    return sodem * 500000 + phidichvu;
}
