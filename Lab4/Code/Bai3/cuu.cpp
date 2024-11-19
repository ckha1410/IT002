#include "cuu.h"

/** Ham khoi tao co tham so lop Cuu
    Input: sl (so luong gia suc)
    Output: Khoi tao gia tri cho thuoc tinh soluong */
Cuu::Cuu(int sl) : GiaSuc(sl) {}

/** Tinh tong sua cuu cho
    Solution: Tuong tu lop Bo */
int Cuu::tongsua() {
    int tong = 0;
    for (int i = 0; i < soluong; i++)
            tong += rand() % 6;
    return tong;
}

/** In ra tieng keu cua cuu
    Output: Chuoi "Cuu keu: bee.. bee.. eee ...!"
    Solution: In tieng keu cua cuu ra man hinh */
void Cuu::tiengkeu() {
    cout << "Cuu keu: bee.. bee.. eeee ...!\n";
}
