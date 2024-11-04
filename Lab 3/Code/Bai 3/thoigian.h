#include<bits/stdc++.h>
using namespace std;

class ThoiGian {
 private:
    int iGio, iPhut, iGiay; // Thuoc tinh gio, phut va giay
 public:
    // Ham tao mac dinh
    ThoiGian();
    // Ham tao co tham so
    ThoiGian(int Gio, int Phut, int Giay);
    // Phuong thuc tinh tong so giay tu gio, phut va giay hien tai
    int TinhGiay();
    // Phuong thuc chuyen doi mot so giay tong thanh gio, phut va giay
    void TinhLaiGio(int Giay);
    // Toan tu cong them mot so giay vao thoi gian hien tai
    ThoiGian operator+(int Giay);
    // Toan tu tru di mot so giay vao thoi gian hien tai
    ThoiGian operator-(int Giay);
    // Toan tu cong hai thoi gian
    ThoiGian operator+(ThoiGian a);
    // Toan tu tru hai thoi gian
    ThoiGian operator-(ThoiGian a);
    // Toan tu tang them 1 giay vao thoi gian hien tai
    ThoiGian operator++();
    // Toan tu tang giam 1 giay vao thoi gian hien tai
    ThoiGian operator--();
    // Toan tu so sanh hai thoi gian bang nhau
    bool operator==(ThoiGian a);
    // Toan tu so sanh hai thoi gian khac nhau
    bool operator!=(ThoiGian a);
    // Toan tu so sanh lon hon hoac bang
    bool operator>=(ThoiGian a);
    // Toan tu so sanh nho hon hoac bang
    bool operator<=(ThoiGian a);
    // Toan tu so sanh lon hon
    bool operator>(ThoiGian a);
    // Toan tu so sanh nho hon
    bool operator<(ThoiGian a);
    // Toan tu nhap >> de nhap du lieu cho thoi gian
    friend istream& operator>>(istream &is, ThoiGian &a);
    // Toan tu nhap << de xuat du lieu cho thoi gian
    friend ostream& operator<<(ostream &os, ThoiGian a);
};
