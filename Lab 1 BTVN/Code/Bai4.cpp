#include <iostream>
#include <vector>
using namespace std;
// Build a class ArnoladsCatMap
class ArnoldsCatMap {
 private:
    int m; // Size of the matrix
    vector<vector<int>> matrix; // The input matrix
    vector<vector<int>> mtgoc; // The original matrix for comparison
    /** Function to perform Arnold's Cat Map transformation
        Input: matrix 'mt' which will be transformed
        Output: transformed matrix stored in 'mt'
        Solution: Applies Arnold's Cat Map transformation rules to update the matrix */
    void biendoi(vector<vector<int>>& mt) {
        vector<vector<int>> newmt(m, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                int newX = (2 * i + j) % m;
                int newY = (i + j) % m;
                newmt[newX][newY] = mt[i][j];
            }
        }
        // Update the original matrix with the transformed one
        mt = newmt;
    }
public:
    /** Constructor to initialize the matrix and size
        Input: size 'size', matrix 'Matrix'
        Output: Initializes object with 'm' and 'matrix'
        Solution: Set size 'm' and matrix 'matrix' with the input parameters */
    ArnoldsCatMap(int size, const vector<vector<int>>& Matrix) {
        m = size;
        matrix = Matrix;
        mtgoc = Matrix;
    }
    /** Function to calculate the cycle length of the transformation
        Input: No parameters required (uses internal 'matrix')
        Output: Returns the number of transformations required to return to the original matrix (cycle length)
        Solution: Repeatedly transform the matrix and count the number of iterations until it matches the original matrix */
    int tinhChuky() {
        int k = 0;
        do {
            // Apply Arnold's Cat Map transformation
            biendoi(matrix);
            k++;
        } while (matrix != mtgoc);
        return k;
    }
};

int main() {
    int m;
    cout << "Nhap kich thuoc ma tran: ";
    cin >> m;
    // Initialize the matrix
    vector<vector<int>> matrix(m, vector<int>(m));
    cout << "Nhap cac phan tu trong ma tran:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];
    // Create an instance of Arnold's Cat Map
    ArnoldsCatMap Map(m, matrix);
    // Calculate and output the cycle length
    int k = Map.tinhChuky();
    cout << "Chu ky cua phep bien doi Arnold's Cat Map la: " << k << "\n";
    return 0;
}
