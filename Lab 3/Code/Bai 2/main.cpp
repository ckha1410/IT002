#include "sophuc.h"
using namespace std;

int main()
{
    SoPhuc sp1, sp2, kq;
    // Nhap vao hai so phuc tu nguoi dung.
    cout << "Nhap so phuc thu nhat:\n";
    cin >> sp1;
    cout << "Nhap so phuc thu hai:\n";
    cin >> sp2;
    // Tinh tong cua hai so phuc va in ket qua
    kq = sp1 + sp2;
    cout << "Tong hai so phuc la: " << kq << "\n";
    // Tinh hieu cua hai so phuc va in ket qua
    kq = sp1 - sp2;
    cout << "Hieu hai so phuc la: " << kq << "\n";
    // Tinh tich cua hai so phuc va in ket qua
    kq = sp1*sp2;
    cout << "Tich hai so phuc la: " << kq << "\n";
    // Tinh thuong cua hai so phuc va in ket qua
    kq = sp1/sp2;
    cout << "Thuong hai so phuc la: " << kq << "\n";
    // So sanh cua hai so phuc va in ket qua
    if (sp1 == sp2) cout << "Hai so phuc bang nhau!\n";
    if (sp1 != sp2) cout << "Hai so phuc khac nhau!\n";
    return 0;
}
