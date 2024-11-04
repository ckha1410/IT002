#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <regex>
#include <sstream>
using namespace std;

// Structure representing a flight
struct Chuyenbay
{
    string maChuyenbay; // Flight code
    string ngaybay;     // Flight date (format: dd/mm/yyyy)
    string giobay;      // Flight time (format: hh:mm, 24-hour format)
    string noidi;       // Departure location
    string noiden;      // Arrival location
};

// Function to validate the flight code
// Function to validate the flight code
bool HopleMaChuyenbay(const string& ma)
{
    // Flight code must be 1 to 5 alphanumeric characters
    return regex_match(ma, regex("^[A-Za-z0-9]{1,5}$"));
}

// Function to validate the flight date
bool HopleNgaybay(const string& ngay)
{
    // Date must be in the format dd/mm/yyyy
    return regex_match(ngay, regex("^([0-2][0-9]|3[0-1])/(0[1-9]|1[0-2])/([0-9]{4})$"));
}

// Function to validate the flight time
bool HopleGiobay(const string& gio)
{
    // Time must be in the format hh:mm (24-hour format)
    return regex_match(gio, regex("^(2[0-3]|[01][0-9]):([0-5][0-9])$"));
}

// Function to validate the departure or arrival location
bool HopleNoididen(const string& noi)
{
    // Location must consist of 1 to 20 alphabetic characters and spaces
    return regex_match(noi, regex("^[A-Za-z\\s]{1,20}$"));
}

// Function to input information for a flight
void Nhap(Chuyenbay& cb)
{
    cout << "Nhap ma chuyen bay: ";
    // Input loop for flight code
    while (true)
    {
        cin >> cb.maChuyenbay;
        if (HopleMaChuyenbay(cb.maChuyenbay)) break; // Validate flight code
        // Prompt for re-entry if invalid
        else cout << "Ma chuyen bay khong hop le! Hay nhap lai: ";
    }

    cout << "Nhap ngay bay (dd/mm/yyyy): ";
    // Input loop for flight date
    while (true)
    {
        cin >> cb.ngaybay;
        if (HopleNgaybay(cb.ngaybay)) break;    // Validate flight date
        // Prompt for re-entry if invalid
        else cout << "Ngay bay khong hop le! Hay nhap lai (dd/mm/yyyy): ";
    }

    cout << "Nhap gio bay (hh:mm): ";
    // Input loop for flight time
    while (true)
    {
        cin >> cb.giobay;
        if (HopleGiobay(cb.giobay)) break;  // Validate flight time
        // Prompt for re-entry if invalid
        else cout << "Gio bay khong hop le! Hay nhap lai (hh:mm): ";
    }

    cin.ignore();
    cout << "Nhap noi di: ";
    // Input loop for departure location
    while (true)
    {
        getline(cin, cb.noidi);
        if (HopleNoididen(cb.noidi)) break; // Validate departure location
        // Prompt for re-entry if invalid
        else cout << "Noi di khong hop le! Hay nhap lai: ";
    }

    cout << "Nhap noi den: ";
    // Input loop for arrival location
    while (true)
    {
        getline(cin, cb.noiden);
        if (HopleNoididen(cb.noiden)) break;    // Validate arrival location
        // Input loop for arrival location
        else cout << "Noi den khong hop le! Hay nhap lai: ";
    }
}

// Function to output information for a flight
void Xuat(const Chuyenbay& cb)
{
    cout << setw(10) << cb.maChuyenbay << setw(15) << cb.ngaybay
         << setw(10) << cb.giobay << setw(20) << cb.noidi
         << setw(20) << cb.noiden << "\n";
}

// Function to search for flights by code, departure, or arrival
void TimkiemChuyenbay(vector<Chuyenbay>& CB, string& tu)
{
    cout << "Ket qua tim kiem theo tu khoa \"" << tu << "\"la:\n";
    bool found = false; // Flag to check if any flight is found
    // Iterate through the list of flights
    for (auto& cb : CB)
        // Check if the flight code, departure, or arrival matches the keyword
        if (cb.maChuyenbay == tu || cb.noidi == tu || cb.noiden == tu)
        {
            Xuat(cb);       // Output the flight details
            found = true;
        }
    if (!found) // If no flights are found
        cout << "Khong tim thay chuyen bay nao voi tu khoa \"" << tu << "\".\n";
}

// Function to compare flight dates and times for sorting
bool Sosanh(Chuyenbay& a, Chuyenbay& b)
{
    if (a.ngaybay == b.ngaybay)
        return a.giobay < b.giobay;
    return a.ngaybay < b.ngaybay;
}

// Function to sort the list of flights by date and time
void SapxepChuyenbay(vector<Chuyenbay>& CB)
{
    // Sort flights using the comparison function
    sort(CB.begin(), CB.end(), Sosanh);
    cout << "\nDanh sach chuyen bay sau khi sap xep theo ngay gio la:\n";
    // Output the sorted flight details
    for (const auto& cb : CB)   Xuat(cb);
}

// Function to display flights departing from a specific location on a specified date
void HienthiChuyenbay(vector<Chuyenbay>& CB, string& Noidi, string& Ngay)
{
    cout << "Danh sach chuyen bay khoi hanh tu \"" << Noidi << "\" vao ngay " << Ngay << " la:\n";
    bool found = false;
    // Iterate through the list of flights
    for (auto& cb : CB)
        // Check if the departure location and date match
        if (cb.noidi == Noidi && cb.ngaybay == Ngay)
        {
            Xuat(cb);   // Output the flight details
            found = true;
        }
    if (!found) // If no flights are found
        cout << "Khong co chuyen bay nao khoi hanh tu \"" << Noidi << "\" vao ngay " << Ngay << ".\n";
}

// Function to count flights from a specific departure location to a specific arrival location
void DemChuyenbay(vector<Chuyenbay>& CB, string& Noidi, string& Noiden)
{
    int d = 0;
    // Iterate through the list of flights
    for (auto& cb : CB)
        // Check if the departure and arrival locations match
        if (cb.noidi == Noidi && cb.noiden == Noiden) ++d;
    cout << "So luong chuyen bay khoi hanh tu \"" << Noidi << "\" den \"" << Noiden << "\" la: " << d << "\n";
}

int main()
{
    cout << "=================================\n";
    cout << "   QUAN LY THONG TIN CHUYEN BAY\n";
    cout << "=================================\n";
    vector<Chuyenbay> CB;
    int n;

    cout << "Nhap so luong chuyen bay: ";
    cin >> n;

    if (n == 0) {
        cout << "Khong co chuyen bay nao duoc nhap!\n"; return 1;
    }
    // Input loop for flight information
    for (int i = 0; i < n; ++i)
    {
        Chuyenbay cb;
        cout << "\nNhap thong tin cho chuyen bay thu " << i + 1 << ":\n";
        Nhap(cb);
        CB.push_back(cb);
    }
    cout << "=================================";
    cout << "\nDanh sach chuyen bay:\n";
    cout << setw(10) << "Ma" << setw(15) << "Ngay bay"
         << setw(10) << "Gio" << setw(20) << "Noi di"
         << setw(20) << "Noi den\n";
    // Output the flight details
    for (const auto& cb : CB) Xuat(cb);

    cout << "=================================";
    // Search for flights
    string tu;
    cout << "\nNhap ma chuyen bay, noi di hoac noi den de tim kiem: ";
    cin >> tu;
    TimkiemChuyenbay(CB, tu);

    cout << "=================================";
    // Sort the flight list by date and time
    SapxepChuyenbay(CB);

    cout << "=================================";
    // Display flights based on a specific departure location and date
    cout << "\nHien thi chuyen bay theo noi di va ngay chi dinh: \n";
    string Noidi, Ngay;
    cout << "Nhap noi di: ";
    cin.ignore();
    getline(cin, Noidi);
    cout << "Nhap ngay khoi hanh (dd/mm/yyyy): ";
    cin >> Ngay;
    HienthiChuyenbay(CB, Noidi, Ngay);

    cout << "=================================";
    // Đếm số lượng chuyến bay từ nơi đi đến nơi đến
    cout << "\nDem so luong chuyen bay tu noi di den noi den: \n";
    string Noiden;
    cout << "Nhap noi di: ";
    cin.ignore();
    getline(cin, Noidi);
    cout << "Nhap noi den: ";
    getline(cin, Noiden);
    DemChuyenbay(CB, Noidi, Noiden);

    return 0;
}
