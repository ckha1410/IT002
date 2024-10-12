#include<iostream>
#include<cmath>
using namespace std;
// Build a class Diem
class Diem {
 public:
    double iHoanh, iTung;
    Diem(double Hoanh = 0, double Tung = 0) {
        iHoanh = Hoanh; iTung = Tung;
    }
    void Xuat() {
        cout << "(" << iHoanh << ", " << iTung << ")\n";
    }
    void SetHoanhDo(double Hoanh) { iHoanh = Hoanh; }
    void SetTungDo(double Tung) { iTung = Tung; }
    double GetHoanhDo() { return iHoanh; }
    double GetTungDo() { return iTung; }
    void TinhTien(double dX, double dY) {
        iHoanh += dX; iTung += dY;
    }
    void Quay(double goc) {
        double rad = goc*M_PI/180;
        double x = iHoanh; double y = iTung;
        iHoanh = x*cos(rad) - y*sin(rad);
        iTung = x*sin(rad) + y*cos(rad);
    }
};
// Build a class Tamgiac
class Tamgiac {
 private:
    Diem A, B, C;
 public:
    Tamgiac(); // Default constructor
    Tamgiac(Diem a, Diem b, Diem c); // Constructor with parameters
    void Nhap(); // Input the coordinates of the triangle's vertices
    void Xuat(); // Output the coordinates of the triangle's vertices
    void TinhTien(double dX, double dY); // Translate the triangle by dx, dy
    void PhongTo(double k); // Scale the triangle up by a factor
    void ThuNho(double k); // Scale the triangle down by a factor
    void Quay(double goc); // Rotate the triangle by a given angle
};



