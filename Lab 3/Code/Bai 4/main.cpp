#include "ngaythangnam.h"

int main()
{
    NgayThangNam ntn1, ntn2, kq;
    // Nhap vao hai ngay thang nam
    cout << "Nhap ngay, thang, nam thu 1: ";
    cin >> ntn1;
    cout << "Nhap ngay, thang, nam thu 2: ";
    cin >> ntn2;
    // Cong them 15 ngay vao ntn1 va in ket qua
    kq = ntn1 + 15;
    cout << "Ngay 1 cong them 15 ngay: ";
    cout << kq << "\n";
    // Tru di 20 ngay tu ntn2 va in ket qua
    kq = ntn2 - 20;
    cout << "Ngay 2 tru di 20 ngay: ";
    cout << kq << "\n";
    // Tinh do chenh lech ngay giua hai ngay
    cout << "Ngay 1 chenh lech ngay 2: " << ntn1 - ntn2 << " ngay\n";
    // Tang ntn1 len 1 ngay va xuat ra ket qua
    cout << "Ngay 1 sau khi tang 1 ngay: " << ++ntn1 << "\n";
    // Giam ntn2 xuong 1 ngay va xuat ra ket qua
    cout << "Ngay 2 sau khi giam 1 ngay: " << --ntn2 << "\n";
    // So sanh hai ngay thang nam va hien thi ket qua cua tung phep so sanh
    if (ntn1 == ntn2) cout << "Hai ngay bang nhau!\n";
    if (ntn1 != ntn2) cout << "Hai ngay khac nhau!\n";
    if (ntn1 > ntn2) cout << "Ngay 1 lon hon ngay 2!\n";
    if (ntn1 >= ntn2) cout << "Ngay 1 lon hon hoac bang ngay 2!\n";
    if (ntn1 < ntn2) cout << "Ngay 1 nho hon ngay 2!\n";
    if (ntn1 <= ntn2) cout << "Ngay 1 nho hon hoac bang ngay 2!\n";

    return 0;
}
