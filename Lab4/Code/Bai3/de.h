#include "giasuc.h"

// Lop De: ke thua tu lop GiaSuc, dai dien cho loai de
class De : public GiaSuc {
 public:
    De(int sl);      // Khoi tao co tham so
    int tongsua();   // Tinh tong luong sua de cho
    void tiengkeu(); // Tieng keu loai de
};
