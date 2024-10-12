#include<iostream>
using namespace std;
// Build a class Diem
class Diem {
 private:
    // Coordinates of the point
    double iHoanh;
    double iTung;
 public:
    // Constructor to initialize the point
    Diem(double Hoanh = 0, double Tung = 0);
    void Xuat(); // Function to display the point coordinates
    void NhanDoi(); // Function to double the coordinates
    void GanVeGoc(); // Function to reset the point to the origin
    void TinhTien(int k, double D); // Function to translate the point
};



