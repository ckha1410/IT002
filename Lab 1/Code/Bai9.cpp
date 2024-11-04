#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <regex>
#define long long long
using namespace std;

// Structure to store information about a savings book
struct SoTietkiem {
    string Maso;        // Code (maximum 5 characters, cannot contain whitespace or special characters)
    string LoaiTietkiem; // Type of savings (maximum 10 characters)
    string Hoten;      // Full name (maximum 30 characters, cannot contain numbers or special characters)
    string CMND;       // ID number (must have exactly 9 or 12 digits)
    time_t NgayMoso;   // Date of opening the savings book
    double SoTiengui;  // Amount deposited (must be a positive number)
    double Laisuat;    // Interest rate (% per year)
};

// Function to validate the savings book code
// Input: string Maso - The savings book code
// Output: bool - Returns true if valid, otherwise false
bool HopleMaso(const string &Maso)
{
    if (Maso.length() > 5) return false;
    return regex_match(Maso, regex("^[a-zA-Z0-9]+$"));
}

// Function to validate the ID number
// Input: string &CMND - The ID number
// Output: bool - Returns true if valid, otherwise false
bool HopleCMND(string &CMND)
{
    //string s = to_string(CMND);
    return (CMND.length() == 9 || CMND.length() == 12);
}

// Function to validate the full name
// Input: string Hoten - The full name
// Output: bool - Returns true if valid, otherwise false
bool HopleHoten(const string &Hoten)
{
    if (Hoten.length() > 30) return false;
    return regex_match(Hoten, regex("^[a-zA-Z\\s]+$"));
}

// Function to validate the date
// Input: int ngay, int thang, int nam - The day, month, and year
// Output: bool - Returns true if valid, otherwise false
bool HopleNgay(int ngay, int thang, int nam)
{
    if (thang < 1 || thang > 12) return false;
    if (ngay < 1 || ngay > 31) return false;
    if (thang == 2) {
        bool nhuan = (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
        if (nhuan && ngay > 29) return false;
        if (!nhuan && ngay > 28) return false;
    }
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        if (ngay > 30) return false;
    }
    return true;
}

// Function to input data for a savings book
// Input: None (user input)
// Output: SoTietkiem - Returns a filled savings book structure
SoTietkiem Nhap()
{
    SoTietkiem stk;
    cout << "Nhap ma so (toi da 5 ky tu, khong chua ky tu dac biet): ";
    while (true)
    {
        cin >> stk.Maso;
        if (HopleMaso(stk.Maso)) break;
        else cout << "Ma so khong hop le! Hay nhap lai: ";
    }

    cout << "Nhap loai tiet kiem (toi da 10 ky tu): ";
    cin.ignore();
    getline(cin, stk.LoaiTietkiem);

    cout << "Nhap ho ten (toi da 30 ky tu, khong chua so hoac ky tu dac biet): ";
    while (true)
    {
        getline(cin, stk.Hoten);
        if (HopleHoten(stk.Hoten)) break;
        else cout << "Ho ten khong hop le! Hay nhap lai: ";
    }

    cout << "Nhap CMND (9 hoac 12 chu so): ";
    while (true)
    {
        cin >> stk.CMND;
        if (HopleCMND(stk.CMND)) break;
        else cout << "CMND khong hop le! Hay nhap lai: ";
    }

    cout << "Nhap ngay mo so (dd mm yyyy): ";
    int ngay, thang, nam;
    while (true)
    {
        cin >> ngay >> thang >> nam;
        if (HopleNgay(ngay, thang, nam)) break;
        else cout << "Ngay khong hop le! Hay nhap lai: ";
    }

    tm timeStruct = {};
    timeStruct.tm_mday = ngay;
    timeStruct.tm_mon = thang - 1;
    timeStruct.tm_year = nam - 1900;
    stk.NgayMoso = mktime(&timeStruct);

    cout << "Nhap so tien gui (so duong): ";
    while (true)
    {
        cin >> stk.SoTiengui;
        if (stk.SoTiengui > 0) break;
        else cout << "So tien gui khong hop le! Hay nhap lai: ";
    }

    cout << "Nhap lai suat (%/nam): ";
    cin >> stk.Laisuat;

    return stk;
}

// Function to output information of a savings book
// Input: const SoTietkiem &stk - The savings book structure
// Output: None (prints the information)
void Xuat(const SoTietkiem &stk)
{
    cout << fixed << setprecision(2);
    cout << "Ma so: " << stk.Maso << "\n";
    cout << "Loai tiet kiem: " << stk.LoaiTietkiem << "\n";
    cout << "Ho ten: " << stk.Hoten << "\n";
    cout << "CMND: " << stk.CMND << "\n";

    tm *timeStruct = localtime(&stk.NgayMoso);
    cout << "Ngay mo so: " << timeStruct->tm_mday << "/" << timeStruct->tm_mon + 1 << "/" << timeStruct->tm_year + 1900 << endl;

    cout << "So tien gui: " << stk.SoTiengui << "\n";
    cout << "Lai suat: " << stk.Laisuat << "%/nam" << "\n";
}

// Function to calculate interest based on savings type and duration
// Input: const SoTietkiem &stk, time_t Ngayht - The savings book and current date
// Output: double - Returns the calculated interest
double TinhLaisuat(const SoTietkiem &stk, time_t Ngayht)
{
    double Laisuat = 0;

    int Sothang = difftime(Ngayht, stk.NgayMoso)/(60*60*24*30);

    if (stk.LoaiTietkiem == "ngan han")
    {
        if (Sothang <= 6)
            Laisuat = stk.SoTiengui*(stk.Laisuat/100)*(Sothang/12);
    }
    else if (stk.LoaiTietkiem == "dai han")
    {
        if (Sothang > 6)
            Laisuat = stk.SoTiengui*(stk.Laisuat/100)*(Sothang/12);
    }
    return Laisuat;
}

// Function to withdraw money from the savings book
// Input: SoTietkiem &stk, double SoTienrut, time_t Ngayht - The savings book, withdrawal amount, and current date
// Output: None (prints the result of the withdrawal)
void Ruttien(SoTietkiem &stk, double SoTienrut, time_t Ngayht)
{
    if (SoTienrut > stk.SoTiengui)
    {
        cout << "So tien rut vuot qua so tien hien co trong so!\n";
        return;
    }

    if (Ngayht < stk.NgayMoso + 6*30*24*60*60)
    {
        cout << "Rut truoc han, lai suat duoc tinh voi lai suat thap hon (0.5%/nam)" << endl;
        stk.SoTiengui -= SoTienrut;
        double Tienlai = stk.SoTiengui * (0.5/100) * (difftime(Ngayht, stk.NgayMoso)/(60*60*24*30)/12);
        cout << "So tien lai nhan duoc: " << Tienlai << "\n";
    }
    else
    {
        stk.SoTiengui -= SoTienrut;
        double Tienlai = TinhLaisuat(stk, Ngayht);
        cout << "So tien lai nhan duoc: " << Tienlai << "\n";
    }
}

// Function to search for a savings book by ID number or code
// Input: vector<SoTietkiem> &STK, string &Maso, string &CMND - List of savings books, code, and ID number
// Output: None (prints the found savings book information)
void TimkiemSTK(vector<SoTietkiem> &STK, string &Maso, string &CMND)
{
    for (auto &stk : STK)
    {
        if (stk.Maso == Maso || stk.CMND == CMND)
        {
            Xuat(stk);
            return;
        }
    }
    cout << "Khong tim thay so tiet kiem theo yeu cau!\n";
}

// Function to list savings books opened within a specific time frame
// Input: vector<SoTietkiem> &STK, time_t Ngay1, time_t Ngay2 - List of savings books, start date, end date
// Output: None (prints the savings books opened within the specified time frame)
void LietkeSTK(vector<SoTietkiem> &STK, time_t Ngay1, time_t Ngay2)
{
    bool had = false;
    for (auto &stk : STK)
        if (stk.NgayMoso >= Ngay1 && stk.NgayMoso <= Ngay2)
            {
                had = true;
                Xuat(stk);
            }
    if (!had) cout << "Khong co so tiet kiem nao mo trong khoang thoi gian nay!\n";
}

// Function to compare two savings books by deposit amount in descending order
// Input: SoTietkiem &a - First savings book, SoTietkiem &b - Second savings book
// Output: bool - Returns true if the first book has a greater deposit than the second
bool SosanhTienguiGiamdan(SoTietkiem &a, SoTietkiem &b)
{
    return a.SoTiengui > b.SoTiengui;
}

// Function to compare two savings books by opening date in ascending order
// Input: SoTietkiem &a - First savings book, SoTietkiem &b - Second savings book
// Output: bool - Returns true if the first book was opened before the second
bool SosanhNgaymoTangdan(SoTietkiem &a, SoTietkiem &b)
{
    return a.NgayMoso < b.NgayMoso;
}

// Main function
int main()
{
    cout << "============================\n";
    cout << "   QUAN LY SO TIET KIEM\n";
    cout << "============================\n";
    // Vector to store savings books
    vector<SoTietkiem> STK;
    time_t Ngayht = time(0);

    int chon;
    // User choice
    do
    {
        cout << "------------------------\n";
        cout << "1. Nhap so tiet kiem\n";
        cout << "2. Xuat thong tin so tiet kiem\n";
        cout << "3. Cap nhat lai suat\n";
        cout << "4. Rut tien\n";
        cout << "5. Tim kiem so tiet kiem\n";
        cout << "6. Liet ke so tiet kiem\n";
        cout << "7. Sap xep so tiet kiem\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> chon;
        cout << "------------------------\n";
        switch (chon)
        {
            case 1:
            {
                // Case to input a new savings book
                // Call input function
                SoTietkiem stk = Nhap();
                STK.push_back(stk);
                break;
            }
            case 2:
            {
                // Case to output all savings book information
                for (auto &stk : STK) Xuat(stk);
                break;
            }
            case 3:
            {
                // Case to update interest rates
                cout << "Nhap lai suat moi (%/nam): ";
                double LaisuatMoi;
                cin >> LaisuatMoi;
                for (auto &stk : STK) stk.Laisuat = LaisuatMoi;
                cout << "Da cap nhat lai suat cho tat ca so tiet kiem!\n";
                break;
            }
            case 4:
            {
                // Case to withdraw money from a savings book
                string ma;
                string CMND;
                cout << "Nhap ma so tiet kiem: ";
                cin >> ma ;
                cout << "Nhap CMND: ";
                cin >> CMND;
                for (auto &stk : STK)
                    // Find matching savings book
                    if (stk.Maso == ma || stk.CMND == CMND)
                    {
                        cout << "Nhap so tien can rut: ";
                        double tienrut;
                        cin >> tienrut;
                        // Call withdrawal function
                        Ruttien(stk, tienrut, Ngayht);
                        break;
                    }
                break;
            }
            case 5:
            {
                // Case to search for a savings book
                string ma;
                string CMND;
                cout << "Nhap ma so tiet kiem: ";
                cin >> ma;
                cout << "Nhap so CMND: ";
                cin >> CMND;
                // Call search function
                TimkiemSTK(STK, ma, CMND);
                break;
            }
            case 6:
            {
                // Case to list savings books opened in a date range
                cout << "Nhap khoang thoi gian (dd mm yyyy): \n";
                int ngay1, thang1, nam1, ngay2, thang2, nam2;
                cout << "Tu ngay: ";
                cin >> ngay1 >> thang1 >> nam1;
                cout << "Den ngay: ";
                cin >> ngay2 >> thang2 >> nam2;

                tm timeS1 = {};
                timeS1.tm_mday = ngay1;
                timeS1.tm_mon = thang1 - 1;
                timeS1.tm_year = nam1 - 1900;
                time_t Ngaydau = mktime(&timeS1);

                tm timeS2 = {};
                timeS2.tm_mday = ngay2;
                timeS2.tm_mon = thang2 - 1;
                timeS2.tm_year = nam2 - 1900;
                time_t Ngaycuoi = mktime(&timeS2);
                // Call listing function
                LietkeSTK(STK, Ngaydau, Ngaycuoi);
                break;
            }
            case 7:
            {
                // Case to sort savings books
                cout << "1. Sap xep theo so tien gui giam dan\n";
                cout << "2. Sap xep theo ngay mo so tang dan\n";
                int loai;
                cout << "Lua chon: ";
                // Input sorting choice
                cin >> loai;
                if (loai == 1)
                {
                    // Sort by deposit amount
                    sort(STK.begin(), STK.end(), SosanhTienguiGiamdan);
                    cout << "Da sap xep theo so tien gui giam dan!\n";
                }
                else if (loai == 2)
                {
                    // Sort by opening date
                    sort(STK.begin(), STK.end(), SosanhNgaymoTangdan);
                    cout << "Da sap xep theo ngay mo so tang dan!\n";
                }
                break;
            }
        }
    } while (chon != 0);    // Loop until the user chooses to exit

    return 0;
}
