#include "khachsan.h"

/** Ham khoi tao co tham so lop KhachSan
    Input: sd (so dem), pdv (phi dich vu), ppv (phi phuc vu)
    Output: Khoi tao gia tri cho cac thuoc tinh sodem, phiphucvu, phidichvu */
KhachSan::KhachSan(double sd, double pdv, double ppv) :
    sodem(sd), phidichvu(pdv), phiphucvu(ppv) {}

/** Ham khoi tao co tham so lop Deluxe
    Input: sd (so dem), pdv (phi dich vu), ppv (phi phuc vu)
    Output: Khoi tao gia tri cho cac thuoc tinh sodem, phiphucvu, phidichvu */
Deluxe::Deluxe(double sd, double pdv, double ppv) :
    KhachSan(sd, pdv, ppv) {}

/** Tinh doanh thu cua phong Deluxe
    Input: So dem khach o, phi dich vu, phi phuc vu
    Output: Doanh thu cua phong Deluxe
    Solution: Cong tong doanh thu bang: so dem*750,000 + phi dich vu + phi phuc vu */
double Deluxe::Doanhthu() {
    if (sodem == 0) return 0;
    return sodem * 750000 + phidichvu + phiphucvu;
}

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
