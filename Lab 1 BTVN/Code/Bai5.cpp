#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Class to handle the binary matrix and find rectangles
class BinaryMatrix {
private:
    vector<vector<int>> mt; // Matrix representation
    int m, n; // Dimensions of the matrix (m = rows, n = columns)

public:
    /** Constructor
        Input: number of rows 'r', number of columns 'c', and matrix 'matrix'
        Output: Initializes the matrix and its dimensions
        Solution: Copies the input matrix and sets the dimensions (m, n) */
    BinaryMatrix(int r, int c, const vector<vector<int>>& matrix) {
        m = r;
        n = c;
        mt = matrix;
    }
    /** Function to find all rectangles in the binary matrix
        Input: None (uses the internal matrix)
        Output: A vector of vectors representing rectangles (each vector contains 4 integers: top-left corner row, top-left corner column, width, height)
        Solution: The function traverses the matrix and, for each element that starts a rectangle, it finds the largest possible rectangle, records it,
         and marks the elements as processed */
    vector<vector<int>> TimHCN() {
        vector<vector<int>> HCN;
        vector<vector<bool>> mark(m, vector<bool>(n, false));
        // Traverse each element of the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If the element is 1 and hasn't been part of any rectangle
                if (mt[i][j] == 1 && !mark[i][j])
                {
                    int W = 0, H = 0;
                    // Find the maximum possible width starting from the current position
                    for (int w = j; w < n && mt[i][w] == 1; ++w)
                        W++;
                    // Find the maximum possible height, considering the current width
                    for (int h = i; h < m && mt[h][j] == 1; ++h) {
                        bool check = true;
                        for (int w = j; w < j + W; ++w)
                            if (mt[h][w] != 1)
                            {
                                check = false;
                                break;
                            }
                        if (!check) break;
                        H++;
                    }
                    // If the found rectangle is at least 2x2 in size
                    if (W >= 2 && H >= 2)
                    {
                        HCN.push_back({i, j, W, H});
                        // Mark all elements in this rectangle as processed
                        for (int h = i; h < i + H; ++h)
                            for (int w = j; w < j + W; ++w)
                                mark[h][w] = true;
                    }
                }
            }
        }
        // Sort the list of rectangles by their starting positions (row, then column)
        sort(HCN.begin(), HCN.end(),
        [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        return HCN;
    }
    /** Function to print the list of found rectangles
        Input: A vector of rectangles (each rectangle represented by a vector of 4 integers: top-left corner row, top-left corner column, width, height)
        Output: Prints each rectangle to the console
        Solution: Iterates through the list of rectangles and prints them in a readable format */
    void xuatHCN(const vector<vector<int>>& HCN) {
        cout << "Danh sach cac hinh chu nhat: \n";
        if (HCN.size() != 0)
        {
            for (auto& hcn : HCN)
            cout << "[" << hcn[0] << ", " << hcn[1] << ", " << hcn[2] << ", " << hcn[3] << "]\n";
        } else cout << "[]\n";
    }
};

int main() {
    // Input the dimensions of the matrix
    int m, n;
    cout << "Nhap so hang va so cot cua ma tran: ";
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    // Input the binary matrix
    cout << "Nhap cac phan tu trong ma tran:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    // Create an instance of BinaryMatrix with the input matrix
    BinaryMatrix bm(m, n, matrix);
    vector<vector<int>> HCN = bm.TimHCN();
    // Output the result
    bm.xuatHCN(HCN);
    return 0;
}
