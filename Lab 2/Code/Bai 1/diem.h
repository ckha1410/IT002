#include<iostream>
using namespace std;
// Build a class Diem
class Diem {
 private:
    // Attributes for the x and y coordinates
    double iHoanh;
    double iTung;
 public:
    Diem(); // Default constructor
    Diem(double Hoanh, double Tung); // Constructor with parameters
    Diem(const Diem &x); // Constructor copy
    void Xuat(); // Input coordinates from the user
    double GetHoanhDo(); // Constructor with parameters
    double GetTungDo(); // Get the y-coordinate
    void SetHoanhDo(double Hoanh); // Set the x-coordinate
    void SetTungDo(double Tung); // Set the y-coordinate
    void TinhTien(double dX, double dY); // Translate the point by dx, dy
};


