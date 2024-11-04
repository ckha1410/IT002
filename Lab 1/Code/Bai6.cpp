#include <iostream>
#include <vector>
using namespace std;
// Function to construct the prefix table for the array A
// Input: A - the array to build a prefix table for, prefix - the array where the prefix values will be stored
// Output: The prefix array is updated in place
void PrefixTable(const vector<int>& A, vector<int>& prefix)
{
    int m = A.size();
    prefix[0] = 0;  // Initialize the first value to 0
    int j = 0;

    // Build the prefix table
    for (int i = 1; i < m; i++)
    {
        // Backtrack j when there's no match
        while (j > 0 && A[i] != A[j]) j = prefix[j - 1];
        // If there's a match, increment j
        if (A[i] == A[j]) j++;
        prefix[i] = j;   // Update the prefix table
    }
}

// KMP algorithm to find occurrences of array A in array B
// Input: A - the pattern array to search for, B - the text array where A is searched
// Output: Prints the number of occurrences and starting indices of occurrences
void KMP(const vector<int>& A, const vector<int>& B) {
    int n = B.size();
    int m = A.size();
    vector<int> prefix(m);  // Initialize the prefix array
    PrefixTable(A, prefix); // Build the prefix array using the PrefixTable function

    vector<int> pos;    // List to store starting positions of occurrences
    int j = 0;

    // Traverse the text array B
    for (int i = 0; i < n; i++)
    {
        // Backtrack j when there's no match
        while (j > 0 && B[i] != A[j]) j = prefix[j - 1];
        // If there's a match, increment j
        if (B[i] == A[j]) j++;
        // If a full match of A is found in B
        if (j == m)
        {
            pos.push_back(i - m + 1);   // Store the start position of the match
            j = prefix[j - 1];  // Continue searching for other occurrences
        }
    }

    // Output the results
    cout << "So lan xuat hien cua mang A trong mang B la: ";
    cout << pos.size() << "\n";         // Print the number of occurrences
    if (pos.size() != 0) {
        cout << "Cac vi tri xuat hien: ";
        for (int p : pos) cout << p << " "; // Print the starting positions
        cout << "\n";
    }
}

// Main function
int main()
{
    // Input
    int n, m;
    cout << "Nhap so phan tu cua mang A va mang B: ";
    cin >> n >> m;

    vector<int>A(n), B(m);
    if (n != 0) cout << "Nhap cac phan tu cua mang A: ";
    for (int i = 0; i < n; i++) cin >> A[i];
    if (m != 0) cout << "Nhap cac phan tu cua mang B: ";
    for (int i = 0; i < m; i++) cin >> B[i];
    // Use the KMP algorithm to search for A in B
    if (n == 0) cout << "Mang A rong!\n";
    else KMP(A, B);

    return 0;
}
