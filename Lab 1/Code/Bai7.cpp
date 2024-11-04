#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;

// Structure to hold student information
struct Hocsinh
{
    string Hoten; // Name of the student
    float Toan;   // Math score
    float Van;    // Literature score
    float Anh;    // English score
    float DTB;    // Average score
    string Phanloai; // Classification based on average score
};

// Function to check if the name is valid (contains no digits)
bool TenHople(const string& ten)
{
    for (char c : ten)
        if (isdigit(c)) return false; // Invalid if there is any digit
    return !ten.empty(); // Name cannot be empty
}

// Function to input scores and validate them
float NhapDiem(const string& mon)
{
    float diem;
    while (true)
    {
        cout << "\tNhap diem " << mon << " (0-10): ";
        cin >> diem; // Read score
        // Check if the input is valid
        if (cin.fail() || diem < 0 || diem > 10)
        {
            cin.clear();
            // Ignore invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Prompt for valid input

            cout << "\tDiem khong hop le! Hay nhap lai.\n";
        }
        else
        {
            // Ignore remaining input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return diem;
        }
    }
}

// Function to classify the student based on average score
string PhanloaiHS(float DTB)
{
    if (DTB >= 9) return "Xuat sac";
    else if (DTB >= 8) return "Gioi";
    else if (DTB >= 6.5) return "Kha";
    else if (DTB >= 5) return "Trung binh";
    else return "Yeu";
}

// Function to calculate the average score
float TinhDTB(float toan, float van, float anh)
{
    return (2 * toan + van + anh) / 4;
}

// Function to convert a string to lowercase for searching
string chuyenThuong(string str)
{
    string thuong = str;
    transform(thuong.begin(), thuong.end(), thuong.begin(), ::tolower); // Transform to lowercase
    return thuong;
}

// Function to search for students by name
void TimkiemHStheoTen(const vector<Hocsinh>& HS, const string& ten)
{
    cout << "\tKet qua tim kiem theo ten: " << ten << "\n";
    bool found = false; // Flag to check if any student is found
    for (const auto& hs : HS)
        if (chuyenThuong(hs.Hoten).find(ten) != string::npos) // Search in lowercase
        {
            found = true;
            cout << "\tHo ten: " << hs.Hoten << "\n\t\tDiem trung binh: " << hs.DTB
                 << "\tPhan loai: " << hs.Phanloai << "\n"; // Display found student info
        }
    if (!found) cout << "\tKhong tim thay hoc sinh nao!\n"; // No student found
}

// Function to find the student with the lowest math score
void TimHSdiemToanThapnhat(const vector<Hocsinh>& HS)
{
    // Initialize to maximum float value
    float minToan = numeric_limits<float>::max();
    // Vector to hold students with lowest score
    vector<Hocsinh> minHS;

    // Find the lowest score
    for (const auto& hs : HS)
        if (hs.Toan < minToan)
            minToan = hs.Toan;

    // Collect all students with the lowest score
    for (const auto& hs : HS)
        if (hs.Toan == minToan)
            minHS.push_back(hs);

    // Display students with lowest math score
    cout << "\nHoc sinh co diem Toan thap nhat (" << minToan << "):\n";
    for (const auto& hs : minHS)
        cout << "\tHo ten: " << hs.Hoten << "\n";
}

int main()
{
    cout << "=================================\n";
    cout << "   QUAN LY THONG TIN HOC SINH\n";
    cout << "=================================\n";
    int n = 3; // Number of students
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore previous input

    // Vector to store student data
    vector<Hocsinh> HS(n);

    // Input student information
    for (int i = 0; i < n; ++i)
    {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":\n";
        while (true)
        {
            cout << "\tHo ten: ";
            getline(cin, HS[i].Hoten); // Input student name
            if (TenHople(HS[i].Hoten)) break; // Validate name
            else cout << "\tTen khong hop le! Hay nhap lai.\n"; // Prompt for valid name
        }

        // Input scores
        HS[i].Toan = NhapDiem("Toan");
        HS[i].Van = NhapDiem("Van");
        HS[i].Anh = NhapDiem("Ngoai ngu");

        // Calculate average score and classification
        HS[i].DTB = TinhDTB(HS[i].Toan, HS[i].Van, HS[i].Anh);
        HS[i].Phanloai = PhanloaiHS(HS[i].DTB);
    }

    // Output student information
    cout << "\n============================\n";
    cout << "Danh sach hoc sinh:\n";
    for (auto& hs : HS)
    {
        // Display all students
        cout << "\tHo ten: " << hs.Hoten
             << "\n\t\tDiem trung binh: " << fixed << setprecision(2) << hs.DTB
             << "\tPhan loai: " << hs.Phanloai << "\n";
    }

    // Find the student with the highest average score
    auto maxDTB = max_element(HS.begin(), HS.end(), [](const Hocsinh& a, const Hocsinh& b)
    {
        return a.DTB < b.DTB;
    });
    // Display student with highest average
    cout << "\nHoc sinh co diem trung binh cao nhat:\n";
    cout << "\tHo ten: " << maxDTB->Hoten
         << "\n\t\tDiem trung binh: " << maxDTB->DTB
         << "\tPhan loai: " << maxDTB->Phanloai << "\n";

    // Search for a student by name
    string ten;
    cout << "\nNhap ten hoc sinh can tim kiem: ";
    getline(cin, ten); // Read name for searching
    // Search by name
    TimkiemHStheoTen(HS, ten);

    // Display the list of students with the lowest math score
    // Find and display students with lowest math score
    TimHSdiemToanThapnhat(HS);

    return 0;
}
