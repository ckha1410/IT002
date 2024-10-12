#include<iostream>
#include<cmath>
using namespace std;
// Build a class Diem
class Diem {
 private:
    double iHoanh;
    double iTung;
 public:
    Diem(double Hoanh = 0, double Tung = 0) {
        iHoanh = Hoanh; iTung = Tung;
    }
    void Nhap() {
        cin >> iHoanh; cin >> iTung;
    }
    void Xuat() {
        cout << "(" << iHoanh << ", " << iTung << ")\n";
    }
    void TinhTien(double dX, double dY) {
        iHoanh += dX; iTung += dY;
    }
    void PhongTo(double k) {
        iHoanh *= k; iTung *= k;
    }
    void Quay(double goc) {
        double rad = goc*M_PI/180;
        double x = iHoanh; double y = iTung;
        iHoanh = x*cos(rad) - y*sin(rad);
        iTung = x*sin(rad) + y*cos(rad);
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




