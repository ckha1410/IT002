#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/** Function to find GCD (Greatest Common Divisor)
    Input: Two integers 'a' and 'b'.
    Output: Returns the greatest common divisor of 'a' and 'b'. */
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
// Build a class PhanSo
class PhanSo {
public:
    int tu, mau;
    // Constructor
    PhanSo(int t = 1, int m = 1) {
        tu = t; mau = m;
    }
    /** Function to input a fraction
        Input: Prompts user for numerator and denominator.
         Denominator must be non-zero. */
    void nhap() {
        cout << "Nhap tu so: "; cin >> tu;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mau;
            if (mau == 0)
                cout << "Mau so phai khac 0! Vui long nhap lai!\n";
        } while (mau == 0);
        rutgon();
    }
    /** Function to simplify a fraction using GCD
        Solution: Finds GCD of numerator and denominator,
         then divides both by GCD. */
    void rutgon() {
        int ucln = gcd(abs(tu), abs(mau));
        tu /= ucln;
        mau /= ucln;
    }
    /** Function to calculate the multiplication of two fractions
        Input: Two fractions
        Output: Returns the product of the two fractions in simplified form. */
    PhanSo operator*(const PhanSo& ps) const {
        PhanSo ans(tu * ps.tu, mau * ps.mau);
        ans.rutgon();
        return ans;
    }
    /** Function to compare two equivalent fractions
        Input: Two fractions
        Output: Returns true if the two fractions are equal. */
    bool bangnhau(const PhanSo& ps) const {
        return tu == ps.tu && mau == ps.mau;
    }
    /** Function to compare two fractions
        Input: Two fractions
        Output: Returns true if the first fraction is smaller than the second. */
    bool operator<(const PhanSo& ps) const {
        return tu * ps.mau < ps.tu * mau;
    }
    /** Function to print a fraction
        Output: Displays the fraction in its simplest form. */
    void xuat() const {
        int tuso = tu, mauso = mau;
        if (mauso < 0) {
            tuso = -tuso; mauso = -mauso;
        }
        if (tuso == 0 ) cout << 0 << " ";
        else if (mauso == 1) cout << tuso << " ";
             else cout << tuso << "/" << mauso << " ";
    }
};

/** Function to find subsets that multiply to a target fraction
    Input: A vector of fractions and a target fraction.
    Output: Displays the subset that multiplies to the target fraction, if any. */
void timtapcon(const vector<PhanSo>& ds, const PhanSo& dich) {
    int n = ds.size();
    vector<PhanSo> ans;
    for (int i = 1; i < (1 << n); i++) {
        PhanSo tich(1, 1);
        vector<PhanSo> cur;
        for (int j = 0; j < n; j++)
            if (i & (1 << j)) {
                tich = tich * ds[j];
                cur.push_back(ds[j]);
            }
        // Check if the product equals the target fraction
        if (tich.bangnhau(dich))
            if (ans.empty() || cur.size() < ans.size())
                ans = cur;
    }
    // Output the result
    if (!ans.empty()) {
        sort(ans.begin(), ans.end());
        cout << "Day con tim duoc la: ";
        for (const auto& ps : ans)
            ps.xuat();
        cout << "\n";
    } else cout << "Khong tim thay ket qua!\n";
}

int main() {
    int n;
    // Input number of fractions
    cout << "Nhap so luong phan so: ";
    cin >> n;
    vector<PhanSo> ds;
    // Input the fractions
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << (i + 1) << ":\n";
        PhanSo ps(0, 1);
        ps.nhap();
        ds.push_back(ps);
    }
    // Input the target fraction
    cout << "Nhap phan so dich:\n";
    PhanSo dich(0, 1);
    dich.nhap();
     // Find the subsets that multiply to the target fraction
    timtapcon(ds, dich);
    return 0;
}
