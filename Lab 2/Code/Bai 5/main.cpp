#include "diem.h"
using namespace std;

int main() {
    // Input the initial coordinates
    double x, y;
    cout << "Nhap toa do diem x, y: ";
    cin >> x >> y;
    // Create the Point object
    Diem d(x, y);
    // Input the number of instructions
    int n;
    cout << "Nhap so chi thi: "; cin >> n;
    // Process each instruction
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Nhap chi thi thu " << i+1 << ": "; cin >> x;
        if (x == 1) {
            d.NhanDoi(); // Double the coordinates
        }
        else if (x == 2) {
            d.GanVeGoc(); // Reset the point to the origin
        }
        else if (x == 3) {
            // Translate the point
            int k; double D;
            cout << "Nhap huong tinh tien k: "; cin >> k;
            cout << "Nhap do tinh tien d: "; cin >> D;
            d.TinhTien(k, D);
        }
        // Do nothing for other instructions
    }
    // Output the final coordinates
    cout << "Toa do diem sau khi thuc hien het chi thi: ";
    d.Xuat();
    return 0;
}
