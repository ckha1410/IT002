#include "diem.h"
/** Default constructor
    Input: None
    Output: Initializes iHoanh and iTung to 0 */
Diem::Diem() {
    iHoanh = 0; iTung = 0;
}
/** Constructor with parameters
    Input: Hoanh (x-coordinate), Tung (y-coordinate)
    Output: Initializes iHoanh and iTung with given values */
Diem::Diem(double Hoanh, double Tung) {
    iHoanh = Hoanh; iTung = Tung;
}
// Constructor copy
Diem::Diem(const Diem &x) {
    iHoanh = x.iHoanh; iTung = x.iTung;
}
/** Function to output coordinates
    Input: None
    Output: Prints the current value of iHoanh and iTung
            to the console */
void Diem::Xuat() {
    cout << "(" << iHoanh << ", " << iTung << ")\n";
}
/** Getter for x-coordinate
    Input: None
    Output: Returns the current x-coordinate (iHoanh) */
double Diem::GetHoanhDo() {
    return iHoanh;
}
/** Getter for y-coordinate
    Input: None
    Output: Returns the current y-coordinate (iTung) */
double Diem::GetTungDo() {
    return iTung;
}
/** Setter for x-coordinate
    Input: hoanh (new x-coordinate)
    Output: Updates iHoanh to the new value */
void Diem::SetHoanhDo(double Hoanh) {
    iHoanh = Hoanh;
}
/** Setter for y-coordinate
    Input: tung (new y-coordinate)
    Output: Updates iTung to the new value */
void Diem::SetTungDo(double Tung) {
    iTung = Tung;
}
/** Function to translate the point
    Input: dx (change in x-coordinate), dy (change in y-coordinate)
    Output: iHoanh and iTung are updated based on the translation */
void Diem::TinhTien(double dX, double dY) {
    iHoanh += dX;
    iTung += dY;
}
