#include "deluxe.h"

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
