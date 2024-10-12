#include "diem.h"
// Constructor to initialize the point
Diem::Diem(double Hoanh, double Tung) {
    iHoanh = Hoanh; iTung = Tung;
}
// Function to display the point coordinates
void Diem::Xuat() {
    cout << "(" << iHoanh << ", " << iTung << ")\n";
}
/** Function to doubles the x and y coordinates of the point
    Input: None
    Output: Updated x and y after doubling */
void Diem::NhanDoi() {
    iHoanh *= 2; iTung *= 2;
}
/** Function to reset the point to the origin (0, 0)
    Input: None
    Output: Updated coordinates set to (0, 0) */
void Diem::GanVeGoc() {
    iHoanh = 0; iTung = 0;
}
/** Function to translate the point by distance d in the direction k
    Input: k (0 for translation along x-axis, non-zero for y-axis), d (distance to translate)
    Output: Updated x or y after translation */
void Diem::TinhTien(int k, double D) {
    if (k == 0) iHoanh += D;
    else iTung += D;
}

