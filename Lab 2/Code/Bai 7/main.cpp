#include "polygon.h"

int main() {
    Polygon dagiac; // Initialize a Polygon object
    // Get user input for the polygon
    dagiac.Nhap();
    // Calculates the area of the polygon
    float dientich = dagiac.Dientich();
    cout << "Dien tich cua da giac: " << dientich << "\n";
    return 0;
}
