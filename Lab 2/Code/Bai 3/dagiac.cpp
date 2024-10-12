#include "dagiac.h"
// Constructor
Dagiac::Dagiac(int sodinh) {
    n = sodinh;
    Dinh = new Diem[n];
}
// Destructor to free dynamically allocated memory
Dagiac::~Dagiac() {
    delete[] Dinh;
}
// Input: Read vertices from user input
void Dagiac::Nhap() {
    cout << "Nhap toa do cac dinh: \n";
    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do dinh thu " << i+1 << " (x, y): ";
        cin >> Dinh[i].iHoanh >> Dinh[i].iTung;
    }
}
// Output: Display the vertices of the polygon
void Dagiac::Xuat() {
    for (int i = 0; i < n; i++) {
        cout << "Dinh " << i+1 << ": ("
             << Dinh[i].iHoanh << ", " << Dinh[i].iTung << ")\n";
    }
}
/** Function to translation (moving polygon by dx, dy)
    Input: dx, dy - translation vector
    Output: Updated vertex coordinates */
void Dagiac::TinhTien(double dX, double dY) {
    for (int i = 0; i < n; i++) {
        Dinh[i].iHoanh += dX;
        Dinh[i].iTung += dY;
    }
}
/** Function to scale up the polygon by multiplying each coordinate by the scale factor
    Input: scale - the factor by which to scale the polygon
    Output: Updated vertex coordinates */
void Dagiac::PhongTo(double k) {
    for (int i = 0; i < n; i++) {
        Dinh[i].iHoanh *= k;
        Dinh[i].iTung *= k;
    }
}
/** Function to scale down the polygon by dividing each coordinate by the scale factor
    Input: scale - the factor by which to shrink the polygon
    Output: Updated vertex coordinates */
void Dagiac::ThuNho(double k) {
    PhongTo(1/k);
}
/** Function to rotate the polygon by a given angle (in degrees) around the origin
    Input: angle - rotation angle in degrees
    Output: Updated vertex coordinates after rotation */
void Dagiac::Quay(double goc) {
    double rad = goc*M_PI/180;
    for (int i = 0; i < n; i++) {
        double x = Dinh[i].iHoanh;
        double y = Dinh[i].iTung;
        Dinh[i].iHoanh = x*cos(rad) - y*sin(rad);
        Dinh[i].iTung = x*sin(rad) + y*cos(rad);
    }
}
