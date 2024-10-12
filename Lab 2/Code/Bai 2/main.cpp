#include "tamgiac.h"
using namespace std;

int main() {
    Tamgiac tg;
    // Input the triangle's vertices
    cout << "Nhap toa do 3 dinh cua tam giac: \n";
    tg.Nhap();
    // Output the triangle's vertices
    cout << "Toa do 3 dinh cua tam giac la: \n";
    tg.Xuat();
    // Translate the triangle
    cout << "Nhap do tinh tien x va y: ";
    double dX, dY;
    cin >> dX >> dY;
    tg.TinhTien(dX, dY);
    cout << "Toa do 3 dinh cua tam giac sau khi tinh tien la: \n";
    tg.Xuat();
    // Scale the triangle up by a factor
    cout << "Nhap muc do phong to: ";
    double k; cin >> k;
    tg.PhongTo(k);
    cout << "Toa do 3 dinh cua tam giac sau khi phong to la: \n";
    tg.Xuat();
    // Scale down the triangle up by a factor
    cout << "Nhap muc do thu nho: ";
    cin >> k;
    tg.ThuNho(k);
    cout << "Toa do 3 dinh cua tam giac sau khi thu nho la: \n";
    tg.Xuat();
    // Input an angle to rotate
    cout << "Nhap so goc xoay tam giac: ";
    int goc; cin >> goc;
    tg.Quay(goc);
    cout << "Toa do 3 dinh cua tam giac sau khi xoay la: \n";
    tg.Xuat();
    return 0;
}
