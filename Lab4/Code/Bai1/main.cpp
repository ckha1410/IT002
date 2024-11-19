#include "nhanvien.h"
#include "quanly.h"
#include "kysu.h"

int main() {
    // Khai bao hai doi tuong QuanLy va KySu
    QuanLy nvql;
    KySu nvks;

     // Nhap thong tin cho hai doi tuong
    cout << "Nhap thong tin quan ly:\n";
    nvql.Nhap();
    cout << "Nhap thong tin ky su:\n";
    nvks.Nhap();
    cout << "\n";

    // Xuat thong tin cua hai doi tuong
    cout << "Thong tin quan ly:\n";
    nvql.Xuat();
    cout << "Thong tin ky su:\n";
    nvks.Xuat();

    return 0;
}
