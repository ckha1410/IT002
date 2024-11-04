#include<bits/stdc++.h>
using namespace std;

class SoPhuc {
 private:
    int dThuc, dAo;
 public:
    // Ham khoi tao mac dinh
    SoPhuc();
    // Ham khoi tao co tham so
    SoPhuc(int thuc, int ao);
    // Toan tu cong hai so phuc
    SoPhuc operator+(const SoPhuc sp) const;
    // Toan tu tru hai so phuc
    SoPhuc operator-(const SoPhuc sp) const;
    // Toan tu nhan hai so phuc
    SoPhuc operator*(const SoPhuc sp) const;
    // Toan tu chia hai so phuc
    SoPhuc operator/(const SoPhuc sp) const;
    // Toan tu so sanh bang
    bool operator==(SoPhuc sp);
    // Toan tu so sanh khac
    bool operator!=(SoPhuc sp);
    // Toan tu nhap >> de nhap du lieu cho so phuc
    friend istream& operator>>(istream &is, SoPhuc &sp);
    // Toan tu xuat << de xuat du lieu cho so phuc
    friend ostream& operator<<(ostream &os, SoPhuc sp);
};
