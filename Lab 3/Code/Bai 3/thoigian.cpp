#include "thoigian.h"

/** Ham tao mac dinh
    Output: Khoi tao thoi gian voi gio, phut, giay bang 0 */
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

/** Ham tao co tham so
    Input: Gio (int Gio), Phut (int Phut), Giay (int Giay)
    Output: Khoi tao thoi gian voi gio, phut, giay cu the */
ThoiGian::ThoiGian(int Gio, int Phut, int Giay) {
    iGio = Gio; iPhut = Phut; iGiay = Giay;
}

/** Tinh tong so giay tu gio, phut, giay hien tai
    Output: Tong so giay (int) tu gio, phut, giay hien tai */
int ThoiGian::TinhGiay() {
    return iGio*3600 + iPhut*60 + iGiay;
}

/** Chuyen doi mot so giay tong thanh gio, phut va giay
    Input: So giay (int Giay)
    Output: Cap nhat thuoc tinh gio, phut, giay tuong ung
    Solution: Chia so giay cho 3600 de lay gio, phan du tiep tuc
              chia cho 60 de lay phut, phan con lai la giay */
void ThoiGian::TinhLaiGio(int Giay) {
    iGio = Giay/3600;
    Giay %= 3600;
    iPhut = Giay/60;
    iGiay = Giay%60;
}

/** Toan tu cong them so giay vao thoi gian hien tai
    Input: So giay can them (int Giay)
    Output: Thoi gian moi (ThoiGian) sau khi them so giay
    Solution: Tinh tong giay hien tai voi so giay them vao,
              sau do chuyen doi lai thanh gio, phut, giay */
ThoiGian ThoiGian::operator+(int Giay) {
    ThoiGian kq = *this;
    int tong = TinhGiay() + Giay;
    kq.TinhLaiGio(tong);
    return kq;
}

/** Toan tu tru so giay tu thoi gian hien tai
    Input: So giay can tru (int Giay)
    Output: Thoi gian moi (ThoiGian) sau khi tru so giay
    Solution: Tinh tong giay hien tai tru di so giay,
              sau do chuyen doi lai thanh gio, phut, giay */
ThoiGian ThoiGian::operator-(int Giay) {
    ThoiGian kq = *this;
    int tong = TinhGiay() - Giay;
    kq.TinhLaiGio(tong);
    return kq;
}

/** Toan tu cong thoi gian hien tai voi mot thoi gian khac
    Input: Thoi gian can cong (ThoiGian a)
    Output: Thoi gian moi (ThoiGian) sau khi cong hai thoi gian
    Solution: Tinh tong so giay cua hai doi tuong, sau do chuyen doi thanh gio, phut, giay */
ThoiGian ThoiGian::operator+(ThoiGian a) {
    ThoiGian kq;
    int tong = TinhGiay() + a.TinhGiay();
    kq.TinhLaiGio(tong);
    return kq;
}

/** Toan tu tru thoi gian hien tai voi mot thoi gian khac
    Input: Thoi gian can tru (ThoiGian a)
    Output: Thoi gian moi (ThoiGian) sau khi tru hai thoi gian
    Solution: Tinh hieu so giay cua hai doi tuong, sau do chuyen doi thanh gio, phut, giay */
ThoiGian ThoiGian::operator-(ThoiGian a) {
    ThoiGian kq;
    int tong = abs(TinhGiay() - a.TinhGiay());
    kq.TinhLaiGio(tong);
    return kq;
}

/** Toan tu tang thoi gian hien tai len 1 giay
    Output: Thoi gian moi (ThoiGian) sau khi tang them 1 giay */
ThoiGian ThoiGian::operator++() {
    return *this + 1;
}

/** Toan tu giam thoi gian hien tai xuong 1 giay
    Output: Thoi gian moi (ThoiGian) sau khi giam di 1 giay */
ThoiGian ThoiGian::operator--() {
    return *this - 1;
}

/** Toan tu kiem tra neu hai thoi gian bang nhau
    Input: Thoi gian can so sanh (ThoiGian a)
    Output: True neu hai thoi gian bang nhau, nguoc lai la False */
bool ThoiGian::operator==(ThoiGian a) {
    return (iGio == a.iGio && iPhut == a.iPhut && iGiay == a.iGiay);
}

/** Toan tu kiem tra neu hai thoi gian khac nhau
    Input: Thoi gian can so sanh (ThoiGian a)
    Output: True neu hai thoi gian khac nhau, nguoc lai la False */
bool ThoiGian::operator!=(ThoiGian a) {
    return !(iGio == a.iGio && iPhut == a.iPhut && iGiay == a.iGiay);
}

/** Toan tu kiem tra neu thoi gian hien tai lon hon hoac bang thoi gian khac
    Input: Thoi gian can so sanh (ThoiGian a)
    Output: True neu thoi gian hien tai lon hon hoac bang, nguoc lai la False */
bool ThoiGian::operator>=(ThoiGian a) {
    return TinhGiay() >= a.TinhGiay();
}

/** Toan tu kiem tra neu thoi gian hien tai nho hon hoac bang thoi gian khac
    Input: Thoi gian can so sanh (ThoiGian a)
    Output: True neu thoi gian hien tai nho hon hoac bang, nguoc lai la False */
bool ThoiGian::operator<=(ThoiGian a) {
    return TinhGiay() <= a.TinhGiay();
}

/** Toan tu kiem tra neu thoi gian hien tai lon hon thoi gian khac
    Input: ThoiGian a
    Output: True neu thoi gian hien tai lon hon thoi gian khac, nguoc lai la False */
bool ThoiGian::operator>(ThoiGian a) {
    return TinhGiay() > a.TinhGiay();
}

/** Toan tu < (nap trong): Kiem tra neu thoi gian hien tai nho hon thoi gian khac
    Input: Thoi gian can so sanh (ThoiGian a)
    Output: True neu thoi gian hien tai nho hon, nguoc lai la False */
bool ThoiGian::operator<(ThoiGian a) {
    return TinhGiay() < a.TinhGiay();
}

/** Toan tu nhap du lieu cho doi tuong thoi gian
    Input: Doi tuong thoi gian (ThoiGian a) qua tham chieu
    Output: Nhap gia tri gio, phut va giay tu nguoi dung */
istream& operator>>(istream &is, ThoiGian &a) {
    cout << "Nhap gio, phut, giay: ";
    is >> a.iGio >> a.iPhut >> a.iGiay;
    return is;
}

/** Toan tu xuat thoi gian theo dinh dang gio, phut va giay
    Input: Doi tuong thoi gian (ThoiGian a)
    Output: Xuat gia tri gio, phut va giay cua doi tuong */
ostream& operator<<(ostream &os, ThoiGian a) {
    os << a.iGio << " gio " << a.iPhut << " phut " << a.iGiay << " giay";
    return os;
}

