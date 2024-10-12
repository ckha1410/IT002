#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
// Build a class Polygon
class Polygon {
 private:
    int n;
    vector<pair<float, float>>ds;
 public:
    // Constructor to initialize an polygon
    Polygon();
    // Function to input for polygon's vertices
    void Nhap();
    // Function to calculate the area of the polygon
    float Dientich();
};




