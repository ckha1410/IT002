#include "ngaythangnam.h"

/** Kiem tra nam nhuan
    Input: nam can kiem tra
    Output: true neu la nam nhuan, false neu khong phai
    Solution: Nam nhuan la nam chia het cho 4 nhung khong chia het cho 100, hoac chia het cho 400 */
bool Namnhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

/** Ham tra ve so ngay trong thang cho mot nam cu the
    Input: thang can kiem tra, nam can kiem tra
    Output: So ngay trong thang do
    Solution: Doi voi thang 2 trong nam nhuan, tra ve 29 ngay;
             cac thang khac lay gia tri tu mang ngayTrongThang */
int soNgayTrongThang(int thang, int nam) {
    int ngayTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (thang == 2 && Namnhuan(nam)) return 29;
    return ngayTrongThang[thang - 1];
}

/** Khoi tao mac dinh cho doi tuong NgayThangNam voi gia tri 1/1/1 */
NgayThangNam::NgayThangNam() : iNgay(1), iThang(1), iNam(1) {}

/** Khoi tao doi tuong NgayThangNam voi nam, thang, ngay duoc chi dinh
    Input: Nam, Thang, Ngay
    Output: doi tuong NgayThangNam moi duoc khoi tao */
NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay) {
    iNam = Nam; iThang = Thang; iNgay = Ngay;
}

/** Tinh tong so ngay tu ngay 1/1/1 den ngay hien tai
    Output: Tong so ngay tinh duoc
    Solution: Tinh so ngay bang cach cong so ngay trong nam va thang truoc ngay hien tai */
int NgayThangNam::TinhNgay() {
    int tong = 0;
    for (int i = 1; i < iNam; i++)
        if (Namnhuan(i)) tong += 366;
        else tong += 365;
    for (int i = 1; i < iThang; i++)
        tong += soNgayTrongThang(i, iNam);
    tong += iNgay;
    return tong;
}

/** Toan tu cong so ngay vao ngay hien tai
    Input: so ngay muon cong
    Output: doi tuong NgayThangNam voi ngay moi
    Solution: Cong ngay vao iNgay, dieu chinh iThang va iNam
              neu vuot qua so ngay cua thang */
NgayThangNam NgayThangNam::operator+(int ngay) {
    NgayThangNam kq = *this;
    kq.iNgay += ngay;
    int maxNgay = soNgayTrongThang(kq.iThang, kq.iNam);
    while (kq.iNgay > maxNgay) {
        kq.iNgay -= maxNgay;
        kq.iThang++;
        if (kq.iThang > 12) {
            kq.iThang = 1;
            kq.iNam++;
        }
    }
    return kq;
}

/** Toan tu tru so ngay tu ngay hien tai
    Input: so ngay muon tru
    Output: doi tuong NgayThangNam voi ngay moi
    Solution: Tru ngay tu iNgay, dieu chinh iThang va iNam neu iNgay < 1 */
NgayThangNam NgayThangNam::operator-(int ngay) {
    NgayThangNam kq = *this;
    kq.iNgay -= ngay;
    while (kq.iNgay < 1) {
        kq.iThang--;
        if (kq.iThang < 1) {
            kq.iThang = 12;
            kq.iNam--;
        }
        int maxNgay = soNgayTrongThang(kq.iThang, kq.iNam);
        kq.iNgay += maxNgay;
    }
    return kq;
}

/** Toan tu tru tinh chenh lech so ngay giua hai ngay
    Input: doi tuong NgayThangNam a
    Output: So ngay chenh lech
    Solution: Lay tong so ngay cua hai doi tuong bang TinhNgay,
              tinh hieu va lay gia tri tuyet doi */
int NgayThangNam::operator-(NgayThangNam a) {
    return abs(TinhNgay() - a.TinhNgay());
}

/** Toan tu tang truoc: Tang ngay len 1
    Output: doi tuong NgayThangNam voi ngay moi */
NgayThangNam NgayThangNam::operator++() {
    return *this + 1;
}

/** Toan tu giam truoc: Giam ngay xuong 1
    Output: doi tuong NgayThangNam voi ngay moi */
NgayThangNam NgayThangNam::operator--() {
    return *this - 1;
}

/** Toan tu kiem tra hai ngay bang nhau
    Input: doi tuong NgayThangNam a
    Output: true neu hai ngay bang nhau, false neu khong bang */
bool NgayThangNam::operator==(NgayThangNam a) {
    return TinhNgay() == a.TinhNgay();
}

/** Toan tu kiem tra hai ngay khac nhau
    Input: doi tuong NgayThangNam a
    Output: true neu hai ngay khac nhau, false neu bang */
bool NgayThangNam::operator!=(NgayThangNam a) {
    return TinhNgay() != a.TinhNgay();
}

/** Toan tu kiem tra ngay hien tai lon hon hoac bang ngay a
    Input: doi tuong NgayThangNam a
    Output: true neu ngay hien tai >= ngay a, false neu khong */
bool NgayThangNam::operator>=(NgayThangNam a) {
    return TinhNgay() >= a.TinhNgay();
}

/** Toan tu kiem tra ngay hien tai nho hon hoac bang ngay a
    Input: doi tuong NgayThangNam a
    Output: true neu ngay hien tai <= ngay a, false neu khong */
bool NgayThangNam::operator<=(NgayThangNam a) {
    return TinhNgay() <= a.TinhNgay();
}

/** Toan tu kiem tra ngay hien tai lon hon ngay a
    Input: doi tuong NgayThangNam a
    Output: true neu ngay hien tai > ngay a, false neu khong */
bool NgayThangNam::operator>(NgayThangNam a) {
    return TinhNgay() > a.TinhNgay();
}

/** Toan tu kiem tra ngay hien tai nho hon ngay a
    Input: doi tuong NgayThangNam a
    Output: true neu ngay hien tai < ngay a, false neu khong */
bool NgayThangNam::operator<(NgayThangNam a) {
    return TinhNgay() < a.TinhNgay();
}

/** Toan tu nhap ngay, thang, nam tu nguoi dung
    Input: doi tuong istream &is, doi tuong NgayThangNam &a
    Output: tra ve doi tuong istream */
istream& operator>>(istream &is, NgayThangNam &a) {
    is >> a.iNgay >> a.iThang >> a.iNam;
    return is;
}

/** Toan tu xuat ngay, thang, nam ra man hinh
    Input: doi tuong ostream &os, doi tuong NgayThangNam a
    Output: tra ve doi tuong ostream */
ostream& operator<<(ostream &os, NgayThangNam a) {
    os << a.iNgay << "/" << a.iThang << "/" << a.iNam;
}
