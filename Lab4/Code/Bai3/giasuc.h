#include <iostream>
#include <time.h>
#include <cstdlib>
#pragma once
using namespace std;

// Lop co so GiaSuc: dai dien cho ba loai gia suc
class GiaSuc {
 protected:
    int soluong; // So luong gia suc
 public:
    GiaSuc(int sl);     // Khoi tao co tham so
    int tongsinhcon();  // Tinh tong so con sinh ra
};
