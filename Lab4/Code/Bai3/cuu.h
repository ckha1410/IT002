#include "giasuc.h"

// Lop Cuu: ke thua tu lop GiaSuc, dai dien cho loai cuu
class Cuu : public GiaSuc {
 public:
    Cuu(int sl);     // Khoi tao co tham so
    int tongsua();   // Tinh tong luong sua cuu cho
    void tiengkeu(); // Tieng keu loai cuu
};
