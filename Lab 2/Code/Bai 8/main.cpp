#include "list.h"

int main() {
   List ds; // Create an instance of the List class
   int n, idx;
   double x, y;
   while (true) {
        cout << "Nhap chi thi: "; cin >> n;
        if (n == -1) {
            // Print the current list and exit the loop.
            ds.Xuat();
            break;
        }
        else if (n == 0) {
            // Add an element to the list
            cout << "Nhap vao phan tu de them vao list: ";
            cin >> x;
            ds.Them(x);
        }
        else if (n == 1) {
            // Remove the first occurrence of the value
            cout << "Nhap vao phan tu can xoa (xoa dau tien): ";
            cin >> x;
            ds.Xoa(x);
        }
        else if (n == 2) {
            // Remove all occurrences of the value
            cout << "Nhap vao phan tu can xoa (xoa het): ";
            cin >> x;
            ds.Xoahet(x);
        }
        else if (n == 3) {
            // Replace an element at a specific index
            cout << "Nhap vi tri can thay the: "; cin >> idx;
            cout << "Nhap gia tri thay the: "; cin >> y;
            ds.Thaythe(idx, y);
        }
   }
   return 0;
}
