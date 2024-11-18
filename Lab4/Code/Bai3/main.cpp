#include "giasuc.h"

int main() {
    srand(time(0)); // Khoi tao bo sinh ngau nhien

    // Nhap so luong bo, cuu, de tu nguoi dung
    int slbo, slcuu, slde;
    cout << "Nhap so luong bo: "; cin >> slbo;
    cout << "Nhap so luong cuu: "; cin >> slcuu;
    cout << "Nhap so luong de: "; cin >> slde;
    // Khoi tao doi tuong Bo, Cuu, De voi so luong tuong ung
    Bo bo(slbo);
    Cuu cuu(slcuu);
    De de(slde);
    // In ra tieng keu cua cac loai gia suc khi doi
    cout << "\nTieng keu cac con vat khi doi:\n";
    if (slbo > 0) bo.tiengkeu();
    if (slcuu > 0) cuu.tiengkeu();
    if (slde > 0) de.tiengkeu();
    // Tinh tong so con sinh ra cua tung loai gia suc
    int tongbo = bo.tongsinhcon();
    int tongcuu = cuu.tongsinhcon();
    int tongde = de.tongsinhcon();
    // Tinh tong sua cua tung loai gia suc
    int suabo = bo.tongsua();
    int suacuu = cuu.tongsua();
    int suade = de.tongsua();
    // Thong ke ket qua
    cout << "\nThong ke nong trai:\n";
    cout << "So luong bo: " << slbo + tongbo << " con, co "
         << tongbo << " con duoc sinh ra, tong sua: " << suabo << " lit\n";
    cout << "So luong cuu: " << slcuu + tongcuu << " con, co "
         << tongcuu << " con duoc sinh ra, tong sua: " << suacuu << " lit\n";
    cout << "So luong de: " << slde + tongde << " con, co "
        << tongde << " con duoc sinh ra, tong sua: " << suade << " lit\n";
    // Tinh tong sua cua tat ca gia suc trong nong trai
    cout << "Tong so sua: " << suabo + suacuu + suade << " lit\n";

    return 0;
}
