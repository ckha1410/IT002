#include "thisinh.h"
// Input: Read candidate details from user input
void ThiSinh::Nhap() {
    cin.ignore();
    cout << "Nhap ten: "; getline(cin, Ten);
    cout << "Nhap MSSV: "; getline(cin, MSSV);
    cout << "Nhap ngay, thang, nam sinh: ";
    cin >> iNgay >> iThang >> iNam;
    cout << "Nhap diem Toan, Van, Anh: ";
    cin >> fToan >> fVan >> fAnh;
}
// Output: Display candidate details
void ThiSinh::Xuat() {
    cout << "Ten: " << Ten << "\t";
    cout << "MSSV: " << MSSV << "\n";
    cout << "Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam << "\n";
    cout << "Diem Toan: " << fToan << "\t";
    cout << "Diem Van: " << fVan << "\t";
    cout << "Diem Anh: " << fAnh << "\n";
}
/** Function to calculate the total score of the candidate
    Input: None (calculates based on the internal scores)
    Output: Total score (sum of Toan. Van, and Anh) */
double ThiSinh::Tong() {
    return fToan + fVan + fAnh;
}
