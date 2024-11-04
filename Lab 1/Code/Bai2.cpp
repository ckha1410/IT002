#include<iostream>
#include<algorithm>
using namespace std;

// Define a structure to represent a fraction
struct Phanso
{
    int tu;
    int mau;
};

// Function to reduce a fraction to its simplest form
// Input: A reference to a fraction (Phanso) ps
// Output: The fraction ps is simplified in place
void RutgonPS(Phanso &ps)
{
    // Find the greatest common divisor (GCD) of the numerator and denominator
    int ucln = __gcd(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
    // Ensure the denominator is positive
    if (ps.mau < 0)
    {
        ps.tu = -ps.tu; ps.mau = -ps.mau;
    }
}

// Function to input a fraction from the user
// Input: A reference to a fraction (Phanso) ps
// Output: The fraction ps is assigned values entered by the user
void Nhap(Phanso &ps)
{
    cout << "Nhap tu so: "; cin >> ps.tu;
    cout << "Nhap mau so: "; cin >> ps.mau;
    // Check for invalid denominator
    if (ps.mau == 0) {
        cout << "Loi! Mau so khong the bang 0\n";
        exit(0);
    }
}

// Function to compare two fractions
// Input: References to two fractions (Phanso) ps1 and ps2
// Output: Returns 1 if ps1 > ps2, -1 if ps1 < ps2, and 0 if they are equal
int Sosanh(Phanso &ps1, Phanso &ps2)
{
    int tu1 = ps1.tu*ps2.mau;
    int tu2 = ps2.tu*ps1.mau;

    if (tu1 > tu2) return 1;
    if (tu1 < tu2) return -1;
    return 0;
}

// Function to output a fraction
// Input: A reference to a fraction (Phanso) ps
// Output: Displays the fraction in its simplest form
void Xuat(Phanso &ps)
{
    // Ensure the denominator is positive
    if (ps.mau < 0)
    {
        ps.tu = -ps.tu; ps.mau = -ps.mau;
    }
    // Display the fraction in the appropriate format
    if (ps.mau==1) cout << ps.tu << "\n";
    else cout << ps.tu << "/" << ps.mau << "\n";
}

// Main function
int main()
{
    Phanso ps1, ps2;

    cout << "Nhap phan so thu nhat: \n";
    Nhap(ps1);
    cout << "Nhap phan so thu hai: \n";
    Nhap(ps2);

    RutgonPS(ps1);
    RutgonPS(ps2);

    // Compare the two fractions
    int sosanh = Sosanh(ps1, ps2);
    if (sosanh == 1)
    {
        cout << "Phan so lon hon la: ";
        Xuat(ps1);
    }
    else if (sosanh == -1)
    {
        cout << "Phan so lon hon la: ";
        Xuat(ps2);
    } else cout << "Hai phan so bang nhau!\n";

    return 0;
}
