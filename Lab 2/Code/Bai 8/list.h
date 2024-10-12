#include<iostream>
#include<vector>
using namespace std;
// Define a class List
class List {
 private:
    unsigned size;
    vector<double> arr; // Dynamic array to store elements
 public:
    List(); // Constructor
    // Function to print the list in the required format
    void Xuat();
    // Function to add an element to the list
    void Them(double x);
    // Function to remove the first occurrence of an element
    void Xoa(double x);
    // Function to remove all occurrences of an element
    void Xoahet(double x);
    // Function to replace element at index with value
    void Thaythe(int idx, double y);
};



