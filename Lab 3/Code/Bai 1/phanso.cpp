#include "phanso.h"

// Ham khoi tao mac dinh
PhanSo::PhanSo() : iTu(0), iMau(1) {}

// Ham khoi tao co tham so, kkhoi tao phan so voi tu va mau cu the
PhanSo::PhanSo(int Tu, int Mau) : iTu(Tu), iMau(Mau) {}

/** Ham rut gon phan so
    Input: phan so hien tai
    Output: phan so khi da rut gon
    Solution: tim uoc chung lon nhat cua tu so va mau so
              sau do thuc hien chia ca tu va mau cho UCLN*/
void PhanSo::Rutgon() {
    int gcd = __gcd(abs(iTu), abs(iMau));
    iTu /= gcd; iMau /= gcd;
}

/** Phep cong hai phan so
    Input: mot phan so ps
    Output: mot phan so moi la ket qua phep cong giua phan so hien tai va ps
    Solution: Thuc hien phep tinh theo cong thuc toan hoc */
PhanSo PhanSo::operator+(PhanSo ps) const {
    int tu = iTu*ps.iMau + ps.iTu*iMau;
    int mau = iMau*ps.iMau;
    return PhanSo(tu, mau);
}

/** Phep tru hai phan so
    Input: mot phan so ps
    Output: mot phan so moi la ket qua phep tru giua phan so hien tai va ps */
PhanSo PhanSo::operator-(PhanSo ps) const {
    int tu = iTu*ps.iMau - ps.iTu*iMau;
    int mau = iMau*ps.iMau;
    return PhanSo(tu, mau);
}

/** Phep nhan hai phan so
    Input: mot phan so ps
    Output: mot phan so moi la ket qua phep nhan giua phan so hien tai va ps */
PhanSo PhanSo::operator*(PhanSo ps) const {
    int tu = iTu*ps.iTu;
    int mau = iMau*ps.iMau;
    return PhanSo(tu, mau);
}

/** Phep chia hai phan so
    Input: mot phan so ps
    Output: mot phan so moi la ket qua phep chia giua phan so hien tai va ps */
PhanSo PhanSo::operator/(PhanSo ps) const {
    int tu = iTu*ps.iMau;
    int mau = iMau*ps.iTu;
    return PhanSo(tu, mau);
}

/** Toan tu so sanh bang
    Input: mot phan so ps
    Output: true neu hai phan so bang nhau, nguoc lai la false
    Solution: so sanh dua tren tich cheo cua tu so va mau so */
bool PhanSo::operator==(PhanSo ps) {
    return iTu*ps.iMau == iMau*ps.iTu;
}

/** Toan tu so sanh khac nhau
    Input: mot phan so ps
    Output: true neu hai phan so khac nhau, nguoc lai la false */
bool PhanSo::operator!=(PhanSo ps) {
    return iTu*ps.iMau != iMau*ps.iTu;
}

/** Toan tu so sanh lon hon hoac bang
    Input: mot phan so ps
    Output: true neu phan so hien tai lon hon hoac bang ps, nguoc lai la false */
bool PhanSo::operator>=(PhanSo ps) {
    return iTu*ps.iMau >= iMau*ps.iTu;
}

/** Toan tu so sanh nho hon hoac bang
    Input: mot phan so ps
    Output: true neu phan so hien tai nho hon hoac bang ps, nguoc lai la false */
bool PhanSo::operator<=(PhanSo ps) {
    return iTu*ps.iMau <= iMau*ps.iTu;
}

/** Toan tu so sanh lon hon
    Input: mot phan so ps
    Output: true neu phan so hien tai lon hon ps, nguoc lai la false */
bool PhanSo::operator>(PhanSo ps) {
    return iTu*ps.iMau != iMau*ps.iTu;
}

/** Toan tu so sanh nho hon
    Input: mot phan so ps
    Output: true neu phan so hien tai nho hon ps, nguoc lai la false */
bool PhanSo::operator<(PhanSo ps) {
    return iTu*ps.iMau != iMau*ps.iTu;
}

/** Toan tu nhap >> de nhap du lieu cho phan so tu nguoi dung
    Input: luong nhap is va phan so ps
    Output: phan so ps voi du lieu nhap tu nguoi dung */
istream& operator>>(istream& is, PhanSo& ps) {
    cout << "Nhap tu so va mau so: ";
    is >> ps.iTu >> ps.iMau;
    // Kiem tra mau so phai khac 0
    while (ps.iMau == 0) {
        cout << "Mau so phai khac 0! Nhap lai mau so: ";
        is >> ps.iMau;
    }
    return is;
}

/** Toan tu xuat << de xuat du lieu cua phan so ra man hinh
    Input: luong xuat os va phan so ps
    Output: xuat phan so duoi dang "tu/mau" ra man hinh */
ostream& operator<<(ostream& os, PhanSo ps) {
    ps.Rutgon();
    // Neu mau am, chuyen mau va tu sang dau duong
    if (ps.iMau < 0) {
        ps.iTu = -ps.iTu; ps.iMau = -ps.iMau;
    }
    os << ps.iTu;
    // Neu phan so khac 0 va mau khong bang 1 thi xuat mau so
    if (ps.iTu != 0 && ps.iMau != 1)
        os << "/" << ps.iMau;
    return os;
}

