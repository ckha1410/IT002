#include<iostream>
#include<cmath>
using namespace std;
// Build a class Diem
class Diem {
 public:
    double iHoanh;
    double iTung;
    Diem(double Hoanh = 0, double Tung = 0) {
        iHoanh = Hoanh; iTung = Tung;
    }
};
// Build a class Dagiac
class Dagiac {
 private:
    int n; // Number of vertices (points)
    Diem *Dinh; // Array of vertices (points)
 public:
    Dagiac(int sodinh); // Constructor
    ~Dagiac(); // Destructor
    void Nhap(); // Input method for polygon vertices
    void Xuat(); // Output method for polygon vertices
    void TinhTien(double dX, double dY); // Translation (move polygon)
    void PhongTo(double k); // Scale up the polygon
    void ThuNho(double k); // Scale down the polygon
    void Quay(double goc); // Rotate the polygon by a given angle
};




