#include "thoigian.h"

int main()
{
    ThoiGian tg1, tg2, kq;
    // Nhap vao hai thoi gian
    cout << "Nhap thoi gian thu nhat:\n";
    cin >> tg1;
    cout << "Nhap thoi gian thu hai:\n";
    cin >> tg2;
    // Cong them 10 giay vao tg1 va in ket qua
    kq = tg1 + 10;
    cout << "Thoi gian 1 sau khi cong 10 giay: ";
    cout << kq << "\n";
    // Tru di 15 giay tu tg2 va in ket qua
    kq = tg2 - 15;
    cout << "Thoi gian 2 sau khi tru 15 giay: ";
    cout << kq << "\n";
    // Tinh tong hai thoi gian va in ket qua
    kq = tg1 + tg2;
    cout << "Tong hai thoi gian la: " << kq << "\n";
    // Tinh hieu hai thoi gian va in ket qua
    kq = tg1 - tg2;
    cout << "Hieu hai thoi gian la: " << kq << "\n";
    // Tang tg1 len 1 giay va xuat ra ket qua
    cout << "Thoi gian 1 sau khi tang 1 giay: " << ++tg1 << "\n";
    // Giam tg2 xuong 1 giay va xuat ra ket qua
    cout << "Thoi gian 2 sau khi giam 1 giay: " << --tg2 << "\n";
    // So sanh hai thoi gian va hien thi ket qua cua tung phep so sanh
    if (tg1 == tg2) cout << "Hai thoi gian bang nhau!\n";
    if (tg1 != tg2) cout << "Hai thoi gian khac nhau!\n";
    if (tg1 > tg2) cout << "Thoi gian thu nhat lon hon thoi gian thu hai!\n";
    if (tg1 >= tg2) cout << "Thoi gian thu nhat lon hon hoac bang thoi gian thu hai!\n";
    if (tg1 < tg2) cout << "Thoi gian thu nhat nho hon thoi gian thu hai!\n";
    if (tg1 <= tg2) cout << "Thoi gian thu nhat nho hon hoac bang thoi gian thu hai!\n";
    return 0;
}
