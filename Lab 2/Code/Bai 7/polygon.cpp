#include "polygon.h"
#define fi first
#define se second
// Constructor to initialize the polygon
Polygon::Polygon() {
    n = 0;
}
/** Function to input
    Input:
    - Number of points (n), must be greater than 2.
    - n pairs of coordinates (x, y), each on a separate line.
    Solution:
    - Check if n > 2; if not, print an error message.
    - Resize the vector to store n points.
    - Iterate through and read the coordinates of each vertex. */
void Polygon::Nhap() {
    cout << "Nhap so dinh: "; cin >> n;
    if (n <= 2) {
        cout << "So dinh phai lon hon 2!\n";
        return;
    }
    ds.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do dinh thu " << i+1 << " (x, y): ";
        cin >> ds[i].fi >> ds[i].se;
    }
}
/** Function to calculate the area of polygon
    Input:
    - No direct input; uses the stored points in the 'points' vector.
    Output:
    - Returns the area of the polygon as a float.
    Solution:
    - Applies the Shoelace (Gauss) formula to calculate the area.
    - The area is computed by summing the cross-products of consecutive points
      and subtracting the reverse cross-products.
   - Takes the absolute value and divides by 2 to get the final area. */
float Polygon::Dientich() {
    float S = 0;
    for (int i = 0; i < n; ++i) {
        int dnext = (i + 1) % n;
        S += ds[i].fi*ds[dnext].se;
        S -= ds[i].se*ds[dnext].fi;
    }
    S = fabs(S)/2;
    return S;
}
