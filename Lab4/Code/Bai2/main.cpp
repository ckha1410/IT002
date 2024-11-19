#include "khachsan.h"
#include "deluxe.h"
#include "premium.h"
#include "business.h"

int main() {
    // Khoi tao cac doi tuong phong
    Deluxe a(9, 1763000, 842000);
    Deluxe b(1, 352000, 261000);
    Premium c(21, 852100);
    Premium d(5, 999200);
    Business e(31);

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
