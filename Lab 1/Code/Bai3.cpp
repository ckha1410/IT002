#include<iostream>
#include<algorithm>
using namespace std;

// Define a structure to represent a fraction
struct Phanso
{
    int tu;     // Numerator
    int mau;    // Denominator
};

// Function to reduce a fraction to its simplest form
// Input: A reference to a fraction (Phanso) ps
// Output: Returns the fraction ps in its simplified form
Phanso RutgonPS(Phanso &ps) {
    int ucln = __gcd(abs(ps.tu), abs(ps.mau));
    ps.tu /= ucln;
    ps.mau /= ucln;
    // Ensure the denominator is positive
    if (ps.mau < 0) {
        ps.tu = -ps.tu; ps.mau = -ps.mau;
    }
    return ps;
}

// Function to input a fraction from the user
// Input: A reference to a fraction (Phanso) ps
// Output: The fraction ps is assigned values entered by the user
void Nhap(Phanso &ps){
    cout << "Nhap tu so: "; cin >> ps.tu;
    cout << "Nhap mau so: "; cin >> ps.mau;
    // Check if the denominator is 0
    if (ps.mau == 0) {
        cout << "Loi! Mau so khong the bang 0\n";
        exit(0);       // Exit the program
    }
}

// Function to calculate the sum of two fractions
// Input: Two references to fractions (Phanso) ps1 and ps2
// Output: Returns the sum of the two fractions in simplified form
Phanso TongPS(Phanso &ps1, Phanso &ps2)
{
    Phanso kq;
    kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    return RutgonPS(kq);
}

// Function to calculate the difference between two fractions
// Input: Two references to fractions (Phanso) ps1 and ps2
// Output: Returns the difference of the two fractions in simplified form
Phanso HieuPS(Phanso &ps1, Phanso &ps2)
{
    Phanso kq;
    kq.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    return RutgonPS(kq);
}

// Function to calculate the product of two fractions
// Input: Two references to fractions (Phanso) ps1 and ps2
// Output: Returns the product of the two fractions in simplified form
Phanso TichPS(Phanso &ps1, Phanso &ps2)
{
    Phanso kq;
    kq.tu = ps1.tu * ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    return RutgonPS(kq);
}

// Function to calculate the quotient of two fractions
// Input: Two references to fractions (Phanso) ps1 and ps2
// Output: Returns the quotient of the two fractions in simplified form
Phanso ThuongPS(Phanso &ps1, Phanso &ps2)
{
    Phanso kq;
    kq.tu = ps1.tu * ps2.mau;
    kq.mau = ps1.mau * ps2.tu;
    // Check if dividing by 0
    if (ps2.tu == 0)
    {
        cout << "Khong the chia cho 0!\n";
        exit(0);    // Exit the program
    }
    return RutgonPS(kq);
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
    // Input
    cout << "Nhap phan so thu nhat:\n";
    Nhap(ps1);
    cout << "Nhap phan so thu hai:\n";
    Nhap(ps2);

    // Calculate and display the sum
    Phanso tong = TongPS(ps1, ps2);
    cout << "Tong la: "; Xuat(tong);
    // Calculate and display the difference
    Phanso hieu = HieuPS(ps1, ps2);
    cout << "Hieu la: "; Xuat(hieu);
    // Calculate and display the product
    Phanso tich = TichPS(ps1, ps2);
    cout << "Tich la: "; Xuat(tich);
    // Calculate and display the quotient
    Phanso thuong = ThuongPS(ps1, ps2);
    cout << "Thuong la: "; Xuat(thuong);

    return 0;
}
