#include "thisinh.h"
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong thi sinh: "; cin >> n;
    // Create an array of candidates
    ThiSinh* TS = new ThiSinh[n];
    // Input: Enter information for n candidates
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin thi sinh thu " << i+1 << ":\n";
        TS[i].Nhap();
    }
    cout << "---------------------------\n";
    cout << "Danh sach thi sinh:\n";
    for (int i = 0; i < n; i++) {
        TS[i].Xuat();
    }
    // Find the candidate with the highest total score
    int idx = 0;
    cout << "---------------------------\n";
    cout << "Danh sach thi sinh co tong diem lon hon 15:\n";
    bool check = false;
    for (int i = 0; i < n; i++) {
        if (TS[i].Tong() > 15) {
            check = true;
            TS[i].Xuat();
            cout << "Tong diem: " << TS[i].Tong() << "\n";
            cout << "--------------\n";
        }
        if (TS[i].Tong() > TS[idx].Tong()) idx = i;
    }
    // Output: Display the candidate with the highest score
    if (!check) cout << "Khong co hoc sinh nao co tong diem lon hon 15!\n";
    cout << "---------------------------\n";
    cout << "Thi sinh co tong diem cao nhat:\n";
    TS[idx].Xuat();
    cout << "Tong diem: " << TS[idx].Tong() << "\n";
    // Free the dynamically allocated memory
    delete[] TS;
    return 0;
}
