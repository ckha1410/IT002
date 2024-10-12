#include "tamgiac.h"
/** Default constructor
    Input: None
    Output: Initializes A, B, and C as points at the origin */
Tamgiac::Tamgiac() : A(), B(), C() {}
/** Constructor with parameters
    Input: Points A, B, and C
    Output: Initializes the triangle's vertices with the given points */
Tamgiac::Tamgiac(Diem a, Diem b, Diem c) {
    Diem A = a; Diem B = b; Diem C = c;
}
/** Function to input the coordinates of the triangle
    Input: User provides the coordinates for points A, B, and C
    Output: Sets the coordinates of the triangle's vertices */
void Tamgiac::Nhap() {
    double x, y;
    cout << "Nhap toa do dinh A: "; cin >> x >> y;
    A.SetHoanhDo(x); A.SetTungDo(y);
    //Diem A(x, y);
    cout << "Nhap toa do dinh B: "; cin >> x >> y;
    B.SetHoanhDo(x); B.SetTungDo(y);

    cout << "Nhap toa do dinh C: "; cin >> x >> y;
    C.SetHoanhDo(x); C.SetTungDo(y);
}
/** Function to output the coordinates of the triangle
    Input: None
    Output: Displays the coordinates of points A, B, and C */
void Tamgiac::Xuat() {
    cout << "Dinh A: "; A.Xuat();
    cout << "Dinh B: "; B.Xuat();
    cout << "Dinh C: "; C.Xuat();
}
/** Function to translate the triangle
    Input: dX (change in x-coordinate), dY (change in y-coordinate)
    Output: Translates all three vertices by (dX, dY) */
void Tamgiac::TinhTien(double dX, double dY) {
    A.TinhTien(dX, dY);
    B.TinhTien(dX, dY);
    C.TinhTien(dX, dY);
}
/** Function to scale the triangle up
    Input: factor (the scaling factor)
    Output: Scales the triangle's vertices away from point A */
void Tamgiac::PhongTo(double k) {
    Diem tam((A.GetHoanhDo() + B.GetHoanhDo() + C.GetHoanhDo()) / 3,
             (A.GetTungDo() + B.GetTungDo() + C.GetTungDo()) / 3);
    A.SetHoanhDo(tam.GetHoanhDo() + k*(A.GetHoanhDo() - tam.GetHoanhDo()));
    A.SetTungDo(tam.GetTungDo() + k*(A.GetTungDo() - tam.GetTungDo()));

    B.SetHoanhDo(tam.GetHoanhDo() + k*(B.GetHoanhDo() - tam.GetHoanhDo()));
    B.SetTungDo(tam.GetTungDo() + k*(B.GetTungDo() - tam.GetTungDo()));

    C.SetHoanhDo(tam.GetHoanhDo() + k*(C.GetHoanhDo() - tam.GetHoanhDo()));
    C.SetTungDo(tam.GetTungDo() + k*(C.GetTungDo() - tam.GetTungDo()));
}
/** Function to scale the triangle down
    Input: factor (the scaling factor)
    Output: Shrinks the triangle's vertices towards point A */
void Tamgiac::ThuNho(double k) {
    PhongTo(1/k);
}
/** Function to rotate the triangle
    Input: angle (rotation angle in degrees)
    Output: Rotates points B and C around point A */
void Tamgiac::Quay(double goc) {
    A.Quay(goc);
    B.Quay(goc);
    C.Quay(goc);
}
