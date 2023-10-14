//
// Created by robinson on 2023/10/13.
//
#include <iostream>
#include "matrix.h"

using namespace robinson::matrix;

int main() {
    Matrix m1(2, 3, {1, 2, 3, 4, 5, 6});
    Matrix m2(3, 2, {1, 1, 1, 1, 1, 1});
    m1.print();
    m2.print();
    Matrix m3;
    Matrix m4;
    m3 = m1 * m2;
    m3.print();
    std::cout << m1.at(1, 1) << std::endl;

    return 0;
}

