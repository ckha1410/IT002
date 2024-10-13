#include <iostream>
#include <vector>
using namespace std;
// Build a class PhanSo
class PhanSo {
    int tu, mau;
 public:
    // Constructor default
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
        Input: User inputs the numerator and denominator,
        ensures the denominator is not zero */
    void nhap() {
        cout << "Nhap tu so: "; cin >> tu;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mau;
        } while (mau == 0);
    }
    /* Function to output a fraction
       Output: Displays the fraction in proper format, handles special
       cases like negative denominator and simplified cases like denominator of 1 */
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

int main() {
    // Input the number of fractions
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    vector<PhanSo> ds; // Vector to store fractions
    // Input the fractions
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << (i + 1) << ":\n";
        PhanSo ps(0, 1);
        ps.nhap();
        ds.push_back(ps);
    }
    // Find the smallest and largest fractions
    // Solution: Iterate over the list of fractions, comparing their values
    PhanSo psMin = ds[0];
    PhanSo psMax = ds[0];
    for (const auto& ps : ds) {
        if (ps.giatri() < psMin.giatri())
            psMin = ps;
        if (ps.giatri() > psMax.giatri())
            psMax = ps;
    }
     // Output the smallest and largest fractions
    cout << "Phan so nho nhat la: ";
    psMin.xuat();
    cout << "Phan so lon nhat la: ";
    psMax.xuat();
    return 0;
}


