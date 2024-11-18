#include "khachsan.h"
using namespace std;

int main() {
    // Khoi tao cac doi tuong phong
    Deluxe a(4, 450000, 150000);
    Deluxe b(2, 400000, 100000);
    Premium c(6, 300000);
    Premium d(3, 200000);
    Business e(9);

    // Tinh tong doanh thu cua cac loai phong
    double dtDeluxe = a.Doanhthu() + b.Doanhthu();
    double dtPremium = c.Doanhthu() + d.Doanhthu();
    double dtBusiness = e.Doanhthu();

    // Xuat doanh thu cua tung loai phong
    cout << "Doanh thu cua loai phong Deluxe: "
         << fixed << setprecision(2) << dtDeluxe << "\n";
    cout << "Doanh thu cua loai phong Premium: "
         << fixed << setprecision(2) << dtPremium << "\n";
    cout << "Doanh thu cua loai phong Business: "
         << fixed << setprecision(2) << dtBusiness << "\n";

    // So sanh doanh thu giua cac loai phong
    if (dtDeluxe == dtPremium && dtDeluxe == dtBusiness
        && dtPremium == dtBusiness)
        cout << "Ba phong co doanh thu bang nhau!\n";
    else if (dtDeluxe > dtPremium && dtDeluxe > dtBusiness)
        cout << "Loai phong Deluxe co doanh thu cao nhat: "
             << fixed << setprecision(2) << dtDeluxe << "\n";
    else if (dtPremium > dtDeluxe && dtPremium > dtBusiness)
        cout << "Loai phong Premium co doanh thu cao nhat: "
             << fixed << setprecision(2) << dtPremium << "\n";
    else cout << "Loai phong Business co doanh thu cao nhat: "
              << fixed << setprecision(2) << dtBusiness << "\n";

    return 0;
}
