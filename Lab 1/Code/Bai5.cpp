#include <iostream>
#include <iomanip>
using namespace std;
// Function to check if a year is a leap year
// Input: An integer year
// Output: Returns true if the year is a leap year, false otherwise
bool Namnhuan(int year) {
    return (year%4 == 0 && (year%100 != 0 || year%400 == 0));
}
// Function to determine the number of days in a given month of a given year
// Input: An integer month and an integer year
// Output: Returns the number of days in that month
int SongayTrongThang(int month, int year)
{
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return Namnhuan(year) ? 29 : 28;
        default:
            return 0;   // Invalid month
    }
}

// Function to check if a date is valid
// Input: An integer day, month, and year
// Output: Returns true if the date is valid, false otherwise
bool Hople(int day, int month, int year)
{
    if (year <= 0 || month < 1 || month > 12) return false;
    int songay = SongayTrongThang(month, year);
    if (day < 1 || day > songay)
        return false;
    return true;
}

// Function to calculate the next day
// Input: References to integers day, month, and year
// Output: Modifies the date to be the next day
void NgayKetiep(int &day, int &month, int &year)
{
    // Increment day if it's not the last day of the month
    if (day < SongayTrongThang(month, year)) day++;
    else
    {
        day = 1;
        // Move to the next month if not December
        if (month < 12) month++;
        else
        {
            month = 1;  // Reset to January
            year++;     // Increment the year
        }
    }
}

// Function to calculate the previous day
// Input: References to integers day, month, and year
// Output: Modifies the date to be the previous day
void NgayTruoc(int &day, int &month, int &year)
{
    // Decrement day if it's not the first day of the month
    if (day > 1) day--;
    else
    {
        // Move to the previous month if not January
        if (month > 1) month--;
        else
        {
            month = 12; // Move to December
            year--;     // Decrement the year
        }
        // Set day to the last day of the previous month
        day = SongayTrongThang(month, year);
    }
}

// Function to calculate which day of the year a given date falls on
// Input: An integer day, month, and year
// Output: Returns the day number within the year
int NgaytrongNam(int day, int month, int year)
{
    int cnt = 0;    // Counter for the day number
    // Sum the days of the months preceding the given month
    for (int i = 1; i < month; ++i)
        cnt += SongayTrongThang(i, year);
    cnt += day;     // Add the current day
    return cnt;
}

// Main function
int main()
{
    // Input the date
    int day, month, year;

    // Check if the date is valid
    cout << "Nhap ngay thang nam (dd mm yyyy): ";
    cin >> day >> month >> year;

    if (!Hople(day, month, year))
    {
        cout << "Loi! Ngay thang nam khong hop le.\n";
        return 1;
    }

    // Calculate and display the next day
    int Ngayketiep = day, Thangketiep = month, Namketiep = year;
    NgayKetiep(Ngayketiep, Thangketiep, Namketiep);
    cout << "Ngay ke tiep la: " << Ngayketiep << "/" << Thangketiep << "/" << Namketiep << "\n";

    // Calculate and display the previous day
    int Ngaytruoc = day, Thangtruoc = month, Namtruoc = year;
    NgayTruoc(Ngaytruoc, Thangtruoc, Namtruoc);
    if (Namtruoc == 0) cout << "Khong co ngay truoc do!\n";
    else cout << "Ngay truoc do la: " << Ngaytruoc << "/" << Thangtruoc << "/" << Namtruoc << "\n";

    // Calculate and display which day of the year it is
    int Ngaythu = NgaytrongNam(day, month, year);
    cout << "Ngay " << day << "/" << month << "/" << year << " la ngay thu " << Ngaythu << " trong nam\n";

    return 0;
}
