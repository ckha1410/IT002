#include<iostream>
#include<cmath>
using namespace std;
const float PI = 3.14;
// Build a class Tamgiac
class Tamgiac {
 private:
    float x1, y1, x2, y2, x3, y3;
 public:
    // Constructor to initialize the triangle's points
    Tamgiac(float X1 = 0, float Y1 = 0,
            float X2 = 0, float Y2 = 0,
            float X3 = 0, float Y3 = 0);
    // Function to translate the triangle
    void Xuat();
    // Function to display the coordinates of the triangle
    void TinhTien(float huong, float d);
};




