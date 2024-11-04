#include<iostream>
#include<algorithm>
using namespace std;

// Dinh nghia lop PhanSo
class PhanSo {
 private:
    int iTu, iMau; // Thuoc tinh tu so va mau so
 public:
    // Ham khoi tao mac dinh
    PhanSo();
    // Ham khoi tao co tham so, khoi tao tu va mau
    PhanSo(int Tu, int Mau);
    // Ham rut gon phan so
    void Rutgon();
    // Dinh nghia toan tu cong cho hai phan so
    PhanSo operator+(PhanSo ps) const;
    // Dinh nghia toan tu tru cho hai phan so
    PhanSo operator-(PhanSo ps) const;
    // Dinh nghia toan tu nhan cho hai phan so
    PhanSo operator*(PhanSo ps) const;
    // Dinh nghia toan tu chia cho hai phan so
    PhanSo operator/(PhanSo ps) const;
    // Toan tu so sanh bang
    bool operator==(PhanSo ps);
    // Toan tu so sanh khac
    bool operator!=(PhanSo ps);
    // Toan tu so sanh lon hon hoac bang
    bool operator>=(PhanSo ps);
    // Toan tu so sanh nho hon hoac bang
    bool operator<=(PhanSo ps);
    // Toan tu so sanh lon hon
    bool operator>(PhanSo ps);
    // Toan tu so sanh nho hon
    bool operator<(PhanSo ps);
    // Toan tu nhap >> de nhap du lieu cho phan so
    friend istream& operator>>(istream& is, PhanSo& ps);
    // Toan tu nhap << de xuat du lieu cua phan so
    friend ostream& operator<<(ostream& os, PhanSo ps);
};
