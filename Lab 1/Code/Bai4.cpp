#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define ll long long
using namespace std;
// Define a constant for the value of π (pi)
const double PI = 3.141592653589793;

int main()
{
    double X;
    // Input the angle in radians
    cout << "Nhap gia tri goc x (tinh bang radian): "; cin >> X;

    // Normalize the input angle X to the range [-π, π]
    double x = fmod(X, 2*PI);
    if (x > PI) x -= 2*PI;
    if (x < -PI) x += 2*PI;

    double sinx = 0;    // Variable to store the calculated value of sin(x)
    double t = x;       // Start with the first term of the Taylor series
    int n = 0;          // Counter for the number of terms

    /* Calculate sin(x) using the Taylor series expansion until
        the absolute value of the term is less than 0.00001 */
    while (abs(t) >= 0.00001)
    {
        sinx += t;
        n++;
        t *= -1*x*x/((2*n)*(2*n + 1));  // Calculate the next term in the Taylor series
    }
    // Display the result with a precision of 5 decimal places
    cout << "Gia tri sin(" << X << ") voi do chinh xac 0.00001 theo cong thuc Taylor la: " << setprecision(5) << sinx << "\n";
    return 0;
}
