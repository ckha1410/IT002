#include "business.h"

/** Ham khoi tao co tham so lop Business
    Input: sd (so dem)
    Output: Khoi tao gia tri cho thuoc tinh sodem */
Business::Business(double sd) :
    KhachSan(sd, 0, 0) {}

/** Tinh doanh thu cua phong Business
    Input: So dem khach o
    Output: Doanh thu cua phong Business
    Solution:
      - Cong tong doanh thu bang: so dem*300,000
      - Phi dich vu va phi phuc vu bang 0 vi khong ap dung cho phong Business */
double Business::Doanhthu() {
    if (sodem == 0) return 0;
    return sodem * 300000;
}
