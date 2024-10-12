#include "diem.h"
using namespace std;

int main() {
    Diem d1; // Default point (0, 0)
    cout << "Toa do diem mac dinh: ";
    d1.Xuat();
    double x, y;
    // Input coordinates for d2
    cout << "Nhap toa do diem (x, y): ";
    cin >> x >> y;
    Diem d2(x, y);
    cout << "Toa do diem d2: ";
    d2.Xuat();
    // Copy d2 by d3
    cout << "Toa do diem d3 sau khi sao chep: ";
    Diem d3(d2);
    d3.Xuat();
    cout << "Nhap hoanh do va tung do can thay doi: ";
    cin >> x >> y;
    d3.SetHoanhDo(x);
    d3.SetTungDo(y);
    cout << "Toa do diem d3 sau khi thay doi: ";
    d3.Xuat();
    // Translate d3
    double dX, dY;
    cout << "Nhap do tinh tien theo x va y: ";
    cin >> dX >> dY;
    d3.TinhTien(dX, dY);
    cout << "Toa do diem d3 sau khi tinh tien: ";
    d3.Xuat();
    return 0;
}
