#include "giasuc.h"

/** Ham khoi tao co tham so lop GiaSuc
    Input: sl (so luong gia suc)
    Output: Khoi tao gia tri cho thuoc tinh soluong */
GiaSuc::GiaSuc(int sl) : soluong(sl) {}

/** Tinh tong so con sinh ra trong moi loai gia suc
    Input: so luong gia suc
    Output: tong so con sinh ra cua moi loai gia suc
    Solution: Thuc hien vong lap, sinh ngau nhien so con
             (1 hoac 2) va cong vao tong */
int GiaSuc::tongsinhcon() {
    int tong = 0;
    for (int i = 0; i < soluong; i++)
            tong += rand() % 2 + 1;
    return tong;
}
