#include "dagiac.h"
using namespace std;

int main() {
    int sodinh;
    cout << "Nhap so dinh: "; cin >> sodinh;
    Dagiac dg(sodinh);
    // Input: User enters polygon vertices
    dg.Nhap();
    // Display the vertices of the polygon
    cout << "Toa do cac dinh trong da giac la: \n";
    dg.Xuat();
    // Translate the polygon
    cout << "Nhap do tinh tien x va y: ";
    double dX, dY; cin >> dX >> dY;
    dg.TinhTien(dX, dY);
    cout << "Toa do cac dinh cua tam giac sau khi tinh tien la: \n";
    dg.Xuat();
    // Scale up the polygon
    cout << "Nhap muc do phong to: ";
    int k; cin >> k;
    dg.PhongTo(k);
    cout << "Toa do cac dinh cua tam giac sau khi phong to la: \n";
    dg.Xuat();
    // Scale down the polygon
    cout << "Nhap muc do thu nho: "; cin >> k;
    dg.ThuNho(k);
    cout << "Toa do cac dinh cua tam giac sau khi thu nho la: \n";
    dg.Xuat();
    // Rotate the polygon
    cout << "Nhap so goc xoay tam giac: ";
    int goc; cin >> goc;
    dg.Quay(goc);
    cout << "Toa do 3 dinh cua tam giac sau khi xoay la: \n";
    dg.Xuat();
    return 0;
}
