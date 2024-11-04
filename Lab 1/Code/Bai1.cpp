#include<iostream>
#include<algorithm>
using namespace std;

// Function to simplify the fraction
// Input: Numerator and denominator by reference
// Output: The fraction is modified to its simplest form
void RutgonPS(int &tu, int &mau)
{
    int ucln = __gcd(tu, mau);     // Calculate the GCD of numerator and denominator
    tu /= ucln;
    mau /= ucln;
}

// Main function
// Input: The user enters the numerator and denominator  of a fraction
// Output: Displays the fraction in its simplified form
// Purpose: This function handles user input, calls RutgonPS to simplify the fraction, and displays the result.
int main()
{
    int tu, mau;
    cout << "Nhap tu so: "; cin >> tu;
    cout << "Nhap mau so: "; cin >> mau;
    // Check if the denominator is zero
    if (mau == 0) {
        cout << "Loi! Mau so khong the bang 0.\n"; return 0;
    }
    // Simplify the fraction using the RutgonPS function
    RutgonPS(tu, mau);
    if (mau < 0) {
        tu = -tu; mau = -mau;
    }
    // Display the simplified fraction
    cout << "Phan so da rut gon la: ";
    if (mau==1) cout << tu << "\n";
    else cout << tu << "/" << mau << "\n";
    return 0;
}

