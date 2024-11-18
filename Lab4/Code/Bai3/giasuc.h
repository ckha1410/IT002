#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

// Lop co so GiaSuc: dai dien cho ba loai gia suc
class GiaSuc {
 protected:
    int soluong; // So luong gia suc
 public:
    GiaSuc(int sl);     // Khoi tao co tham so
    int tongsinhcon();  // Tinh tong so con sinh ra
};

// Lop Bo: ke thua tu lop GiaSuc
class Bo : public GiaSuc {
 public:
    Bo(int sl);      // Khoi tao co tham so
    int tongsua();   // Tinh tong luong sua bo cho
    void tiengkeu(); // Tieng keu loai bo
};

// Lop Cuu: ke thua tu lop GiaSuc, dai dien cho loai cuu
class Cuu : public GiaSuc {
 public:
    Cuu(int sl);     // Khoi tao co tham so
    int tongsua();   // Tinh tong luong sua cuu cho
    void tiengkeu(); // Tieng keu loai cuu
};

class De : public GiaSuc {
 public:
    De(int sl);      // Khoi tao co tham so
    int tongsua();   // Tinh tong luong sua de cho
    void tiengkeu(); // Tieng keu loai de
};
