#include "sophuc.h"

/** Ham khoi tao mac dinh, khoi tao so phuc voi phan thuc va phan ao bang 0.
    Output: So phuc voi dThuc = 0, dAo = 0 */
SoPhuc::SoPhuc() : dThuc(0), dAo(0) {}

/** Ham khoi tao co tham so, khoi tao so phuc voi gia tri phan thuc va phan ao duoc chi dinh.
    Input: int thuc, int ao - gia tri phan thuc va phan ao.
    Output: So phuc voi dThuc = thuc, dAo = ao */
SoPhuc::SoPhuc(int thuc, int ao) {
    dThuc = thuc; dAo = ao;
}

/** Toan tu cong, tra ve tong cua hai so phuc.
    Input: So phuc sp.
    Output: So phuc moi la tong cua hai so phuc.
    Solution: Tinh tong phan thuc va phan ao cua hai so phuc, tra ve ket qua duoi dang so phuc moi */
SoPhuc SoPhuc::operator+(const SoPhuc sp) const {
    int thuc = dThuc + sp.dThuc;
    int ao = dAo + sp.dAo;
    return SoPhuc(thuc, ao);
}

/** Toan tu tru, tra ve hieu cua hai so phuc.
    Input: So phuc sp.
    Output: So phuc moi la hieu cua hai so phuc.
    Solution: Tinh hieu phan thuc va phan ao cua hai so phuc, tra ve ket qua duoi dang so phuc moi. */
SoPhuc SoPhuc::operator-(const SoPhuc sp) const {
    int thuc = dThuc - sp.dThuc;
    int ao = dAo - sp.dAo;
    return SoPhuc(thuc, ao);
}

/** Toan tu nhan, tra ve tich cua hai so phuc.
    Input: So phuc sp.
    Output: So phuc moi la tich cua hai so phuc.
    Solution: Ap dung cong thuc nhan so phuc: (a + bi)(c + di) = (ac - bd) + (ad + bc)i. */
SoPhuc SoPhuc::operator*(const SoPhuc sp) const {
    int thuc = dThuc*sp.dThuc - dAo*sp.dAo;
    int ao = dThuc*sp.dAo + dAo*sp.dThuc;
    return SoPhuc(thuc, ao);
}

/** Toan tu chia, tra ve thuong cua hai so phuc.
    Input: So phuc sp.
    Output: So phuc moi la thuong cua hai so phuc.
    Solution: Ap dung cong thuc chia so phuc */
SoPhuc SoPhuc::operator/(const SoPhuc sp) const {
    int mau = sp.dThuc*sp.dThuc + sp.dAo*sp.dAo;
    int thuc = (dThuc*sp.dThuc + dAo*sp.dAo)/mau;
    int ao = (dAo*sp.dThuc - dThuc*sp.dAo)/mau;
    return SoPhuc(thuc, ao);
}

/** Toan tu so sanh bang, tra ve true neu hai so phuc bang nhau.
    Input: So phuc sp.
    Output: true neu dThuc va dAo cua hai so phuc bang nhau, false neu khong.
    Solution: So sanh gia tri dThuc va dAo giua hai so phuc. */
bool SoPhuc::operator==(SoPhuc sp) {
    return (dThuc == sp.dThuc && dAo == sp.dAo);
}

/** Toan tu so sanh khac, tra ve true neu hai so phuc khac nhau.
    Input: So phuc sp.
    Output: true neu hai so phuc khac nhau, false neu chung bang nhau.
    Solution: Dung toan tu == de kiem tra khac nhau, neu khong bang nhau thi tra ve true */
bool SoPhuc::operator!=(SoPhuc sp) {
    return !(dThuc == sp.dThuc && dAo == sp.dAo);
}

/** Ham nhap so phuc tu luong nhap.
    Input: Luong nhap is, so phuc sp.
    Output: Cap nhat gia tri cua dThuc va dAo tu nguoi dung.
    Solution: Yeu cau nguoi dung nhap phan thuc va phan ao va gan cho dThuc, dAo. */
istream& operator>>(istream &is, SoPhuc &sp) {
    cout << "Nhap phan thuc va phan ao: ";
    is >> sp.dThuc >> sp.dAo;
    return is;
}

/** Ham xuat so phuc ra luong xuat.
    Input: Luong xuat os, so phuc sp.
    Output: Xuat so phuc duoi dang "a + bi" hoac "a - bi".
    Solution: Kiem tra dau cua phan ao de xuat dung dinh dang. */
ostream& operator<<(ostream &os, SoPhuc sp) {
    os << sp.dThuc;
    if (sp.dAo >= 0) os << " + " << sp.dAo << "i";
    else os << " - " << abs(sp.dAo) << "i";
    return os;
}
