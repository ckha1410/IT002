#include "khachsan.h"

/** Ham khoi tao co tham so lop KhachSan
    Input: sd (so dem), pdv (phi dich vu), ppv (phi phuc vu)
    Output: Khoi tao gia tri cho cac thuoc tinh sodem, phiphucvu, phidichvu */
KhachSan::KhachSan(double sd, double pdv, double ppv) :
    sodem(sd), phidichvu(pdv), phiphucvu(ppv) {}
