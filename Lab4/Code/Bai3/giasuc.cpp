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
