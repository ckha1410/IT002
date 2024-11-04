#include "phanso.h"

int main() {
    PhanSo ps1, ps2, kq;
    // Nhap hai phan so tu nguoi dung
    cout << "Nhap phan so thu nhat:\n";
    cin >> ps1;
    cout << "Nhap phan so thu hai:\n";
    cin >> ps2;
    // Tinh tong hai phan so va hien thi ket qua
    kq = ps1 + ps2;
    cout << "Tong hai phan so la: " << kq << "\n";
    // Tinh hieu hai phan so va hien thi ket qua
    kq = ps1 - ps2;
    cout << "Hieu hai phan so la: " << kq << "\n";
    // Tinh tich hai phan so va hien thi ket qua
    kq = ps1*ps2;
    cout << "Tich hai phan so la: " << kq << "\n";
    // Tinh thuong hai phan so va hien thi ket qua
    kq = ps1/ps2;
    cout << "Thuong hai phan so la: " << kq << "\n";
    // So sanh hai phan so va hien thi ket qua
    if (ps1 == ps2)
        cout << "Phan so thu nhat bang phan so thu hai!\n";
    if (ps1 != ps2)
        cout << "Phan so thu nhat khac phan so thu hai!\n";
    if (ps1 < ps2)
        cout << "Phan so thu nhat nho hon phan so thu hai!\n";
    if (ps1 > ps2)
        cout << "Phan so thu nhat lon hon phan so thu hai!\n";
    if (ps1 <= ps2)
        cout << "Phan so thu nhat nho hon hoac bang phan so thu hai!\n";
    if (ps1 >= ps2)
        cout << "Phan so thu nhat lon hon hoac bang phan so thu hai!\n";

    return 0;
}
