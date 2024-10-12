#include<iostream>
#include <cstdlib>
#include<ctime>
#include<limits>
#include<algorithm>
using namespace std;

class cArray {
    int *arr;
    int n;
 public:
    // Constructor khởi tạo mảng
    cArray(int size) {
        n = size;
        arr = new int[n];
    }
    // Destructor giải phóng bộ nhớ
    ~cArray() {
        delete[] arr;
    }
    // Nhập
    void nhap() {
        cout << "Nhap day gom " << n << " so nguyen: ";
        for (int i = 0; i < n; i++) cin >> arr[i];
    }
    // Xuất
    void xuat() {
        cout << "Mang la: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";
    }
    // Tạo dãy gồm n số nguyên ngẫu nhiên
    void random() {
        srand(time(0));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 100;
    }
    // Đếm số lần xuất hiện của x trong dãy
    int demX(int x) const {
        int count = 0;
        for (int i = 0; i < n; i++)
            if (arr[i] == x)
                count++;
        return count;
    }
    // Kiểm tra dãy tăng dần
    bool isTangdan() const {
        for (int i = 1; i < n; i++)
            if (arr[i] < arr[i - 1])
                return false;
        return true;
    }
    // Tìm phần tử lẻ nhỏ nhất
    int PTleMin() const {
        int min = numeric_limits<int>::max();
        for (int i = 0; i < n; i++)
            if (arr[i] % 2 != 0 && arr[i] < min)
                min = arr[i];
        if (min == numeric_limits<int>::max())
            return 0;
        return min;
    }
    // Sắp xếp dãy tăng dần
    void sapxep() {
        sort(arr, arr + n);
    }
};

int main()
{
    int size;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> size;
    cArray arr(size);
    arr.nhap();
    arr.xuat();
    arr.random();
    cout << "Mang sau khi tao ngau nhien: ";
    arr.xuat();
    int x;
    cout << "Nhap gia tri can dem: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << ": " << arr.demX(x) << "\n";
    if (arr.isTangdan()) cout << "Mang tang dan!\n";
    else cout << "Mang khong tang dan!\n";
    int min = arr.PTleMin();
    if (min != 0) cout << "Phan tu le nho nhat: " << min << "\n";
    else cout << "Khong co phan tu le trong mang!\n";
    arr.sapxep();
    cout << "Mang sau khi sap xep tang dan: ";
    arr.xuat();

    return 0;
}
