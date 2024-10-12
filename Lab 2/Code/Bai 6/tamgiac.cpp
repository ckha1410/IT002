#include "tamgiac.h"
// Constructor to initialize the triangle's points
Tamgiac::Tamgiac(float X1, float Y1, float X2,
                 float Y2, float X3, float Y3) {
    x1 = X1; y1 = Y1; x2 = X2; y2 = Y2; x3 = X3; y3 = Y3;
}
// Function to display the coordinates of the triangle
void Tamgiac::Xuat() {
    cout << "Toa do ba diem cua tam giac sau khi tinh tien:\n";
    cout << "Diem 1: (" << x1 << ", " << y1 << ")\n";
    cout << "Diem 2: (" << x2 << ", " << y2 << ")\n";
    cout << "Diem 3: (" << x3 << ", " << y3 << ")\n";
}
/** Function to translate the triangle based on a direction and distance
    Input: direction (in degrees, where 0 degrees is along the positive x-axis) and distance
    Output: Updated coordinates of the triangle after translation */
void Tamgiac::TinhTien(float goc, float d) {
    float rad = (goc*PI)/180;
    // Calculate the translation along the x and y axes
    float dX = d*cos(rad);
    float dY = d*sin(rad);
    // Translate all three points
    x1 += dX; y1 += dY;
    x2 += dX; y2 += dY;
    x3 += dX; y3 += dY;
}
