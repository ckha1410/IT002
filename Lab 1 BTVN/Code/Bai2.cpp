#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// Build a class PhanSo
class PhanSo {
    int tu, mau;
 public:
    // Default constructor
    PhanSo () {
        tu = 0; mau = 1;
    }
    // Constructor with parameters
    PhanSo(int tuso, int mauso) {
        tu = tuso;
        if (mauso != 0) mau = mauso;
        else mau = 1;
    }
    /* Function to input a fraction
       Input: User enters numerator and denominator.
         Denominator cannot be zero, if zero prompt again. */
    void nhap() {
        cout << "Nhap tu so: "; cin >> tu;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mau;
            if (mau == 0)
                cout << "Mau so phai khac 0! Vui long nhap lai!\n";
        } while (mau == 0);
    }
    /* Function to output a fraction
       Output: Displays the fraction in proper format
        (adjusting for negative denominator) */
    void xuat() const {
        int tuso = tu, mauso = mau;
        if (mauso < 0) {
            tuso = -tuso; mauso = -mauso;
        }
        if (tuso == 0 ) cout << 0 << "\n";
        else if (mauso == 1) cout << tuso << "\n";
             else cout << tuso << "/" << mauso << "\n";
    }
    // Function to calculate the value of the fraction
    // Output: Returns the floating-point value of the fraction (numerator/denominator)
    double giatri() const {
        return (double)tu/mau;
    }
};

/** Function to compare two fractions
    Input: Two fractions
    Output: Returns true if the first fraction is smaller than the second */
bool sosanh(const PhanSo& ps1, const PhanSo& ps2) {
    return ps1.giatri() < ps2.giatri();
}

int main() {
    int n, k;
    // Input number of fractions and value of k
    cout << "Nhap so luong phan so: "; cin >> n;
    cout << "Nhap gia tri k: "; cin >> k;
    vector<PhanSo> ds;
    // Input the fractions
    // Input: User enters 'n' fractions
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << (i + 1) << ":\n";
        PhanSo ps(0, 1);
        ps.nhap();
        ds.push_back(ps);
    }
    /** Sort the fractions by value
        Solution: Sort the list of fractions using the custom comparison function */
    sort(ds.begin(), ds.end(), sosanh);
    // Output the k-th largest and k-th smallest fractions if k is valid
    if (k <= ds.size()) {
        cout << "Phan so lon thu " << k << " la: ";
        ds[ds.size() - k].xuat();
        cout << "Phan so nho thu " << k << " la: ";
        ds[k - 1].xuat();
    }
    return 0;
}


