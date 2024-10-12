#include "tamgiac.h"

int main() {
    // Input the initial coordinates of the triangle
    float X1, Y1, X2, Y2, X3, Y3;
    cout << "Nhap toa do ba diem cua tam giac: \n";
    cout << "Diem thu nhat (x1, y1): "; cin >> X1 >> Y1;
    cout << "Diem thu hai (x2, y2): "; cin >> X2 >> Y2;
    cout << "Diem thu ba (x3, y3): "; cin >> X3 >> Y3;
    // Create the Triangle object
    Tamgiac tg(X1, Y1, X2, Y2, X3, Y3);
    float goc, d;
     // Translate the triangle
    cout << "Nhap huong tinh tien: "; cin >> goc;
    cout << "Nhap do dai tinh tien: "; cin >> d;
    tg.TinhTien(goc, d);
    // Output the translated triangle coordinates
    tg.Xuat();
    return 0;
}
