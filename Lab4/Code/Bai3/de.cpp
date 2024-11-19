#include "de.h"

/** Ham khoi tao co tham so lop De
    Input: sl (so luong gia suc)
    Output: Khoi tao gia tri cho thuoc tinh soluong */
De::De(int sl) : GiaSuc(sl) {}

/** Tinh tong sua de cho
    Solution: Tuong tu lop Bo */
int De::tongsua() {
    int tong = 0;
    for (int i = 0; i < soluong; i++)
        tong += rand() % 11;
    return tong;
}

/** In ra tieng keu cua de
    Output: Chuoi "De keu: be.. be.. eee ...!"
    Solution: In tieng keu cua de ra man hinh */
void De::tiengkeu() {
    cout << "De keu: be.. be.. eeeee ...!\n";
}
