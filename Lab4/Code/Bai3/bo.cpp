#include "bo.h"

/** Ham khoi tao co tham so lop Bo
    Input: sl (so luong gia suc)
    Output: Khoi tao gia tri cho thuoc tinh soluong */
Bo::Bo(int sl) : GiaSuc(sl) {}

/** Tinh tong sua bo cho
    Input: so luong bo
    Output: tong luong sua bo cho
    Solution: Lap qua moi con bo, sinh ngau nhien luong sua
             (0–20 lit) va cong vao tong */
int Bo::tongsua() {
    int tong = 0;
    for (int i = 0; i < soluong; i++)
        tong += rand() % 21;
    return tong;
}

/** In ra tieng keu cua bo
    Output: Chuoi "Bo keu: moo.. moo.. ooo ...!"
    Solution: In tieng keu cua bo ra man hinh */
void Bo::tiengkeu() {
    cout << "Bo keu: moo.. moo.. ooo ...!\n";
}
